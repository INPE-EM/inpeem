-- Handles with the DEGRAD component execution.
-- @arg year A year for simulation.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_execute(year, model)
function componentDEGRAD_execute(year, model)
	--instancia as perdar de AGB, BGB, deadWood e literia
	local attrAGB_loss = model.componentDEGRAD.attrAGB_loss 
	local attrBGB_loss = model.componentDEGRAD.attrBGB_loss 
	local attrDeadWood_loss = model.componentDEGRAD.attrDeadWood_loss
	local attrLitter_loss = model.componentDEGRAD.attrLitter_loss

	if (model.verbose) then
		print(year, "Executing Degrad - mode:"..model.mode) 
	end

	--varre todas as celulas
	for k, cell in pairs (model.cs.cells) do
		-- TOA e BL
		-- Initialize actualAGB if not was previsiouly 
		if ((year == model.yearInit) and (cell.actualAGB == -1)) then 
			cell.actualAGB = cell.B_AGB
			cell.actualBGB = cell.B_AGB * cell.B_BGBPercAGB
		end

		-- Biomass loss in the cell - o q tem de biomassa * o que foi degradado * o que foi perdido
		cell_agb_degrad = cell.actualAGB * cell.degrad * attrAGB_loss
		cell_bgb_degrad = (cell.actualAGB * cell.B_BGBPercAGB) * cell.degrad * attrAGB_loss
		cell_litter_degrad = (cell.actualAGB * cell.B_LitterPercAGB) * cell.degrad * attrAGB_loss
		cell_dead_wood_degrad = (cell.actualAGB * cell.B_DeadWoodPercAGB) * cell.degrad * attrAGB_loss

		-- total Biomass loss in the cell - soma de todas as perdas na celula
		cell_CO2_emission_Degrad = (cell_agb_degrad + cell_bgb_degrad + cell_litter_degrad + cell_dead_wood_degrad) * cell.B_FactorB_CO2_fire 

		-- Updates biomass subtracting it what was degraded
		cell.actualAGB = (cell.actualAGB * model.cs.cellarea - cell_agb_degrad) / model.cs.cellarea
		cell.actualBGB = (cell.actualBGB * model.cs.cellarea - cell_bgb_degrad) / model.cs.cellarea

		if (model.save == true) then 
			cell[model.componentDEGRAD.attrActualAGB..year] = cell.actualAGB 
			cell[model.componentDEGRAD.attrActualBGB..year] = cell.actualBGB 
		end 

		-- DÚVIDA: essas variáveis não são inicializadas?
		-- Aggregating results at the regional level(summing cells)
		model.DEGRAD_result[year].DEGRAD_CO2_emission = model.DEGRAD_result[year].DEGRAD_CO2_emission + cell_CO2_emission_Degrad
		--model.DEGRAD_result[year].DEGRAD_CO2_absorption = model.DEGRAD_result[year].DEGRAD_CO2_absorption + cell_CO2_absorption_Degrad 
	end 
end

-- Handles with the creation of a null DEGRAD component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_createNullComponent(model)
function componentDEGRAD_createNullComponent(model)
	if (model ~= nil) then
		model.componentDEGRAD = { 	name = "undefined",
									description = "",			 				 
									averAGB_loss = 0,
									averBGB_loss = 0,
									averDeadWood_loss = 0, 
									averLitter_loss = 0,
									averDegrad = 0 
								}
	end
end

-- Handles with the initialization method of a DEGRAD component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_init(model)
function componentDEGRAD_init(model)
	-- init output attributes
	model.componentDEGRAD.saveAttrs = {}
	model.componentDEGRAD.saveCount = 0

	model.componentDEGRAD.attractualAGB = "AGB_"
	model.componentDEGRAD.attractualBGB = "BGB_"

	if (model.save == true) then 
		for year= model.yearInit, model.yearFinal, 1 do 
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attractualAGB..year 
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attractualBGB..year 
		end	 
	end

	-- init(run time) future cellattribute names
	model.componentDEGRAD.attrAGB_loss = model.componentDEGRAD.name.."AGB_loss" 
	model.componentDEGRAD.attrBGB_loss = model.componentDEGRAD.name.."BGB_loss" 
	model.componentDEGRAD.attrDeadWood_loss = model.componentDEGRAD.name.."DeadWood_loss" 
	model.componentDEGRAD.attrLitter_loss = model.componentDEGRAD.name.."Litter_loss" 

	-- init database attr names for component parameters
	componentDEGRAD_initCellAttrNames(model)
end
 
-- Handles with the initialization of the cell with average values.
-- @arg cell A cell of a Cellular Space.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_createNullComponent(model)
function componentDEGRAD_initCellAverComponentValues(cell, model)
	cell.Degrad_AGB_loss = model.componentDEGRAD.averAGB_loss
	cell.Degrad_BGB_loss = model.componentDEGRAD.averBGB_loss
	cell.Degrad_DeadWood_loss = model.componentDEGRAD.averDeadWood_loss
	cell.Degrad_Litter_loss = model.componentDEGRAD.averLitter_loss
	cell.degrad = model.componentDEGRAD.averDegrad 
end

-- Handles with the verify method of a DEGRAD component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_verify(model)
function componentDEGRAD_verify(model)
	if (model.componentDEGRAD.name == nil) then
		error("Missing Degrad parameter: name", 2) 
	end

	if (model.componentDEGRAD.description == nil) then
		error("Missing Degrad parameter: description", 2) 
	end

	if (model.componentDEGRAD.averAGB_loss == nil) then
		error("Missing Degrad parameter: averAGB_loss", 2) 
	end

	if (model.componentDEGRAD.averBGB_loss == nil) then
		error("Missing Degrad parameter: averBGB_loss", 2) 
	end 

	if (model.componentDEGRAD.averDeadWood_loss == nil) then
		error("Missing Degrad parameter: averDeadWood_loss", 2) 
	end	 

	if (model.componentDEGRAD.averLitter_loss == nil)	then
		error("Missing Degrad parameter: averLitter_loss", 2) 
	end 

	if (model.componentDEGRAD.averDegrad == nil) then
		error("Missing Degrad parameter: averDegrad", 2) 
	end
	
	return true
end

-- Handles with the cell attributes inicialization.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_initCellAttrNames(model)
function componentDEGRAD_initCellAttrNames(model)
	model.componentDEGRAD.attrAGB_loss = model.componentDEGRAD.name.."AGB_loss" 
	model.componentDEGRAD.attrBGB_loss = model.componentDEGRAD.name.."BGB_loss" 
	model.componentDEGRAD.attrDeadWood_loss = model.componentDEGRAD.name.."DeadWood_loss" 
	model.componentDEGRAD.attrLitter_loss = model.componentDEGRAD.name.."Litter_loss" 
	model.componentDEGRAD.attrDegrad = model.componentDEGRAD.name.."Degrad"
end

-- Handles with the load of the attributes from the database or shape.
-- @arg model A INPE-EM Model.
-- @arg cell_temp A cell of Cellular Space.
-- @arg cell A cell of Cellular Space.
-- @arg y A year value.
-- @usage --DONTRUN
-- componentDEGRAD_loadFromDB(model, cell_temp, cell, y)
function componentDEGRAD_loadFromDB(model, cell_temp, cell, y)
	if (cell_temp[model.componentDEGRAD.attrDegrad..y] ~= nil) then
		cell.degrad = cell_temp[model.componentDEGRAD.attrDegrad..y]
	end
end

-- Handles with the load of the attributes from a table (used with non-spatial model).
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentD_loadFromTable(model)
function componentDEGRAD_loadFromTable(model)
	if (model.dataTable.Degrad ~= nil) then
		if (#model.dataTable.Degrad < step) then
			error("Time required exceeds the input table size: Degrad", 2) 
		end
		
		cell.degrad = model.dataTable.Degrad [step]
	end 
end
 