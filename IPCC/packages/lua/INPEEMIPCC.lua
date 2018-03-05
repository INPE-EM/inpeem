--- Handles with a INPE-EM IPCC model behavior.
-- @arg model.name The model name.
-- @arg model.startTime The initial year of simulation.
-- @arg model.endTime The final year of simulation.
-- @arg model.cs The spatial dimension definition (CellularSpace).
-- @arg model.landUseValues The name of the use land types for simulation.
-- @arg model.transitionMatrix The name of land use that is not consider on the simulation.
-- @arg model.run Handles with the execution method of a LuccMe model.
-- @arg model.verify Handles with the verify method of a LuccMe model.
-- @usage --DONTRUN
--import("inpeemipcc")
--
----------------------------------------------------------------
---- INPE-EM IPCC APPLICATION MODEL DEFINITION                --
----------------------------------------------------------------
--import("inpeemipcc")
--
--ipccNew = LuccMEModel
--{
--	name = "ipccNew",
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
--}  -- END INPE-EM IPCC application model definition
--
-------------------------------------------------------
---- ENVIROMMENT DEFINITION                          --
-------------------------------------------------------
--timer = Timer
--{
--	Event
--	{
--		start = ipccNew.startTime,
--		action = function(event)
--					ipccNew:run(event)
--				 end
--	}
--}
--
-------------------------------------------------------
---- ENVIROMMENT EXECUTION                           --
-------------------------------------------------------
--env_ipccNew = Environment{}
--env_ipccNew:add(timer)
--env_ipccNew:add(tsave)
--env_ipccNew:run(ipccNew.endTime)
--
--projFile = File("t3mp.tview")
--if(projFile:exists()) then
--	projFile:delete()
--end
function INPEEMIPCCModel(model)
	-- Implements the execution method of a INPE-EM IPCC model.
	-- @arg event An Event represents a time instant when the simulation engine must execute some computation.
	-- @usage --DONTRUN
	-- model.run(event)
	model.run = function(self, event)
		if (event:getTime() == self.startTime) then
			model:verify(event)
			
			print("\nExecuting Model")
			--Check years with data
			simulationTime = self.endTime - self.startTime
			yearWithData = {}
			
			for i = 0, simulationTime, 1 do
				local auxTime = self.startTime + i
				if (self.cs.cells[1]["use"..auxTime] ~= nil) then
					yearWithData[i + 1] = 1
				else
					yearWithData[i + 1] = 0
				end
			end
		end
		
		if (event:getTime() ~= self.endTime) then
			local step = event:getTime() - self.startTime + 1
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
				print("Calculating emissions between "..event:getTime().." and "..nextUse)
				
				
			else
				-- No data for the current year, skipping to the next one
				--print("No data for "..event:getTime().." skipping to next year")
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
		local equal = 0
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
    
		-- Verify the dates to be saved
		-- This verification is done on Save.lua, because it necessary to execute before here.
		collectgarbage("collect")
	end
	
	collectgarbage("collect")
	return model
end
