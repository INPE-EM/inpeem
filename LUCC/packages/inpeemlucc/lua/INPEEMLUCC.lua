--- Handles with a INPE-EM LUCC model behavior.
-- @arg model.name The model name.
-- @arg model.startTime The initial year of simulation.
-- @arg model.endTime The final year of simulation.
-- @arg model.cs The spatial dimension definition (CellularSpace).
-- @arg model.landUseValues The name of the use land types for simulation.
-- @arg model.transitionMatrix The name of land use that is not consider on the simulation.
-- @arg model.run Handles with the execution method of a LuccMe model.
-- @arg model.verify Handles with the verify method of a LuccMe model.
-- @arg model.calculateEmission Handles with the emission calculation.
-- @usage --DONTRUN
--import("inpeemlucc")
--
----------------------------------------------------------------
---- INPE-EM LUCC APPLICATION MODEL DEFINITION                --
----------------------------------------------------------------
--import("inpeemlucc")
--
--luccNew = LuccMEModel
--{
--	name = "luccNew",
--
--	-----------------------------------------------------
--	-- Temporal dimension definition                   --
--	-----------------------------------------------------
--	startTime = 2000,
--	endTime = 2010,
--
--	-----------------------------------------------------
--	-- Spatial dimension definition                    --
--	-----------------------------------------------------
--	cs = CellularSpace
--	{
--		project = "t3mp.tview",
--		layer = "layer_name",
--		cellArea = 1,
--	},
--
--	-----------------------------------------------------
--	-- Land use values definition                      --
--	-----------------------------------------------------
--	landUseValues = {1, 2}, 	--f, d
--
--	transitionMatrix = 
--	{
--		{"(£t2-£t1)*$teste", "(£t2-£t1)*($teste+$teste2)"},
--		{"(£t2-£t1)*($teste+$teste2)", "(£t2-£t1)*$teste"}
--	}
--}  -- END INPE-EM LUCC application model definition
--
-------------------------------------------------------
---- ENVIROMMENT DEFINITION                          --
-------------------------------------------------------
--timer = Timer
--{
--	Event
--	{
--		start = luccNew.startTime,
--		action = function(event)
--					luccNew:run(event)
--				 end
--	}
--}
--
-------------------------------------------------------
---- ENVIROMMENT EXECUTION                           --
-------------------------------------------------------
--env_luccNew = Environment{}
--env_luccNew:add(timer)
--env_luccNew:add(tsave)
--env_luccNew:run(luccNew.endTime)
--
--projFile = File("t3mp.tview")
--if(projFile:exists()) then
--	projFile:delete()
--end
function INPEEMLUCCModel(model)
	-- Implements the execution method of a INPE-EM LUCC model.
	-- @arg event An Event represents a time instant when the simulation engine must execute some computation.
	-- @usage --DONTRUN
	-- model.run(event)
	model.run = function(self, event)
		local currentTime = event:getTime()
		
		if (currentTime == self.startTime) then
			model:verify(event)
			print("\nExecuting Model")
			
			-- Check years with data
			simulationTime = self.endTime - self.startTime
			yearWithData = {}
			biomassMaps = {}
			countMaps = 1

			for i = 0, simulationTime, 1 do
				local auxTime = self.startTime + i
				if (self.cs.cells[1]["use"..auxTime] ~= nil) then
					yearWithData[i + 1] = 1
				else
					yearWithData[i + 1] = 0
				end
			end
			
			-- Find the biomass maps
			for i = 1, #self.transitionMatrix, 1 do
				for j = 1, #self.transitionMatrix[i], 1 do
					local startName = 0
					local endName = 0
					local auxBiomassMap = ""
					local existBiomassMap = false
					
					startName = string.find(self.transitionMatrix[i][j], "@")
					startName = startName + 1
					endName = string.find(self.transitionMatrix[i][j], "&")
					endName = endName - 1
					
					auxBiomassMap = string.sub(self.transitionMatrix[i][j], startName, endName)
					
					for k = 1, #biomassMaps, 1 do
						if auxBiomassMap == biomassMaps[k] then
							existBiomassMap = true
							break
						end	
					end
					
					if (not existBiomassMap) then
						biomassMaps[countMaps] = auxBiomassMap
						countMaps = countMaps + 1
						existBiomassMap = false
					end
				end
			end
		end
		
		if (currentTime ~= self.endTime) then
			local step = currentTime - self.startTime + 1
			local nextUse = 0

			-- Check if the current use has data
			if (yearWithData[step] == 1) then
				-- Find the next year to calculate the emissions
				for i = step + 1, #yearWithData, 1 do
					if(yearWithData[i] == 1) then
						nextUse = self.startTime + i - 1
						break
					end
				end
				
				-- Inform the years that will be calculated the emissions
				print("Calculating emissions between "..currentTime.." and "..nextUse)
				local y = string.sub(currentTime, string.len(currentTime) - 1).."_"..string.sub(nextUse, string.len(nextUse) - 1)
				local columnName = "eC_"..y
				local cBckName = "bio_"..y
				local auxIndex = 0
				
				for i = 1, #self.cs, 1 do
					local auxEquation = self.transitionMatrix[self.cs.cells[i]["use"..currentTime]][self.cs.cells[i]["use"..nextUse]]
					
					-- Find the biomass data of the current formula for the cell
					for j = 1, #biomassMaps, 1 do
						if (string.find(auxEquation, biomassMaps[j]) ~= nil) then
							auxIndex = j
							break
						end
					end
					
					
					-- Create a backup to save
					if (currentTime == self.startTime) then
						self.cs.cells[i][biomassMaps[auxIndex].."Backup"] = self.cs.cells[i][biomassMaps[auxIndex]]
					end
					
					if (self.cs.cells[i][biomassMaps[auxIndex].."BackupYear"] ~= nil) then
						self.cs.cells[i][biomassMaps[auxIndex]] = self.cs.cells[i][biomassMaps[auxIndex].."BackupYear"]
						self.cs.cells[i][cBckName] = self.cs.cells[i][biomassMaps[auxIndex].."BackupYear"]
					end
					
					-- Execute the emission calculation
					model:calculateEmission(event, auxEquation, i, columnName, biomassMaps[auxIndex])
					
					-- Change the biomass data
					self.cs.cells[i][biomassMaps[auxIndex].."BackupYear"] = self.cs.cells[i][biomassMaps[auxIndex]]
					self.cs.cells[i][biomassMaps[auxIndex]] = self.cs.cells[i][biomassMaps[auxIndex].."Backup"] 
				end

				if (currentTime ~= self.startTime) then
					self.cs:save(self.name..y, {cBckName, columnName})
				else
					self.cs:save(self.name..y, columnName)
				end
			end
		else
			print("End of Simulation");
		end
	end

	-- Implements the verify method of a LuccMe model.
	-- @arg event An Event represents a time instant when the simulation engine must execute some computation.
	-- @usage --DONTRUN 
	-- model.verify(event)
	model.verify = function(self, event)
		print("\nVerifying Model parameters")
		
		-- Verify the model name
		if (model.name == nil) then
			error("Model name not defined", 2)
		end

		-- Verify the scenario name
		if (self.name == nil) then
			error("A scenario name is required", 2)
		end

		-- Verify the scenario start time
		if (self.startTime == nil) then
			error("A scenario start time is required", 2)
		end
		
		  -- Verify the scenario stop time
		if (self.endTime == nil) then
			error("A scenario end time is required", 2)
		end
		
		-- Verify the scenario date
		if (self.endTime <= self.startTime) then
			error("The scenario end time must be higher than the scenario start time", 2)
		end

		-- Verify the cellular space
		if (not self.cs) then
			error("A Cellular Space must be defined", 2)
		else
			if (self.cs.cells[1].lin ~= nil) then
				local aux = self.cs
				self.cs = CellularSpace {
					project = "t3mp.tview",
					layer = "layer",
					xy = {"col", "lin"},
					cellArea = aux.cellArea
				}
			elseif (self.cs.cells[1].Lin ~= nil) then
				local aux = self.cs
				self.cs = CellularSpace {
					project = "t3mp.tview",
					layer = "layer",
					xy = {"Col", "Lin"},
					cellArea = aux.cellArea
			}
			end
		end

		-- Verify whether the land values is declared and its valid
		if(self.landUseValues == nil) then
			error("Land use values is missing", 2)
		end
    
		-- Verify transition matrix
		if(self.transitionMatrix == nil) then
			error("Transition matrix is missing", 2)
		end
		
		for i = 1, #self.landUseValues, 1 do
			if(#self.landUseValues ~= #self.transitionMatrix[i]) then
				error("Wrong transition matrix size", 2);
			end
		end
		
		io.flush()
		collectgarbage("collect")
	end
	
	-- Implements the emission calculate.
	-- @arg event An Event represents a time instant when the simulation engine must execute some computation.
	-- @arg equation The equation used to calculate the emission.
	-- @arg i The index of the cellArea
	-- @arg columnName The name of output column in the shape file.
	-- @usage --DONTRUN 
	-- model:calculateEmission(event, equation, cellIndex, columnName)
	model.calculateEmission = function(self, event, equation, i, columnName, biomassMap)
		-- transform in global to run the load command
		gSelf = self
		gI = i

		-- change special characters to terrame language
		local aux = string.gsub(equation, "($)", "gSelf.cs.cells[gI][\"")
		aux = string.gsub(aux, "(#)", "\"]")
		
		-- change special characters to terrame language
		-- biomass to carbon: factor 0.48
		aux = string.gsub(aux, "(@)", "(gSelf.cs.cells[gI][\"")
		aux = string.gsub(aux, "(&)", "\"]*0.48)")
		
		-- load generates a function() with the content of the string
		executeEquation = load("return "..aux)
		
		-- call the function and store in a new column
		self.cs.cells[i][columnName] = executeEquation()
		
		-- remove the carbon emission of the biomass
		print(self.cs.cells[i]["col"],self.cs.cells[i]["row"],self.cs.cells[i][biomassMap], self.cs.cells[i][columnName])
		self.cs.cells[i][biomassMap] = self.cs.cells[i][biomassMap] - (self.cs.cells[i][columnName] / 0.48)
		if (self.cs.cells[i][biomassMap] < 0) then
			self.cs.cells[i][biomassMap] = 0
		end
	end
	
	collectgarbage("collect")
	return model
end
