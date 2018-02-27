--- Handles with a INPE-EM IPCC model behavior.
-- @arg model.name The model name.
-- @arg model.startTime The initial year of simulation.
-- @arg model.endTime The final year of simulation.
-- @arg model.cs The spatial dimension definition (CellularSpace).
-- @arg model.landUseTypes The name of the use land types for simulation.
-- @arg model.landUseNoData The name of land use that is not consider on the simulation.
-- @arg model.potential The name of component that calculates the potential of change  for each cell.
-- @arg model.allocation The name of component that handles with the allocation on the cell
-- based on it potential and demand.
-- @arg model.demand The name of component that handles with the allocation demand.
-- @arg model.save The name of component that handles with the simulation data save in a database.
-- @arg model.isCoupled A flag to inform with the model for simulation is coupled to another.
-- @arg model.execute Handles with the execution method of a LuccMe model.
-- @arg model.verify Handles with the verify method of a LuccMe model.
-- @arg model.dinamicVars Handles with the dinamicVars method of a LuccMe model.
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
--env_ipccNew = Environment{}
--env_ipccNew:add(timer)
--
-------------------------------------------------------
---- ENVIROMMENT EXECUTION                           --
-------------------------------------------------------
--if ipccNew.isCoupled == false then
--	tsave = databaseSave(ipccNew)
--	env_ipccNew:add(tsave)
--	env_ipccNew:run(ipccNew.endTime)
--	saveSingleTheme(ipccNew, true)
--	projFile = File("t3mp.tview")
--	if(projFile:exists()) then
--		projFile:delete()
--	end
--end
function INPEEMIPCCModel(model)
	-- Implements the execution method of a INPE-EM IPCC model.
	-- @arg event An Event represents a time instant when the simulation engine must execute some computation.
	-- @usage --DONTRUN
	-- model.run(event)
	model.run = function(self, event)
		if (event:getTime() == self.startTime) then
			model:verify(event)
		end
		
		print("\nExecuting Model")
		-- XXXXXXXXXXXXXX
		-- XXXXXXXXXXXXXX
		-- XXXXXXXXXXXXXX
		-- XXXXXXXXXXXXXX
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
