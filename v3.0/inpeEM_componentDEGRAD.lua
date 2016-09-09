-- Handles with the DEGRAD component execution.
-- @arg year A year for simulation.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_execute(year, model)
function componentDEGRAD_execute(year, model)

	if (model.verbose) then 
		print(year, "Executing Degrad - mode:"..model.mode)
	end

	local sum_cell_loss = 0
	local num_cell_loss = 0
	
	local cell_CO2_absorption_Degrad = 0
	local cell_CO2_emission_Degrad = 0
	
	local cell_agb_degrad_regrow = 0
    local cell_bgb_degrad_regrow = 0
	
	local percForLost = 0
	
	local cell_agb_degrad = 0
	local cell_bgb_degrad = 0
	local cell_litter_degrad = 0
	local cell_wood_degrad = 0
	
	for k, cell in pairs( model.cs.cells ) do
		if (year == model.yearInit) then 
			cell.B_ActualAGB = cell.B_AGB
			cell.B_ActualAGB = cell.B_AGB * cell.B_BGBPercAGB
		end
		
		if (model.mode == "non_spatial") then
			if (cell.DEGRAD_Degrad > 0 and cell.DEGRAD_AGB_loss > 0) then
				flagDEGRAD = true
			end

		end

		cell_CO2_absorption_Degrad = 0
		cell_CO2_emission_Degrad = 0

		-- Current average biomass in the cell
		if year == model.yearInit then 
			cell.AGBRegrowRate = 0 	
			cell.DegradLoss = 0
			if (model.mode == "spatial") then
				if (flagDEGRAD) then
					cell.B_ActualAGB = cell.B_AGB * (1 - cell.DEGRAD_AGB_percReduction)
				end

				-- Reinitialize the rate
				cell.AGBRegrowRate = 0
				if (cell.DEGRAD_PeriodRegrow ~= 0) then
					cell.AGBRegrowRate = (cell.B_AGB - cell.B_ActualAGB) / cell.DEGRAD_PeriodRegrow 
				end
			end
		end

		-- Regrowth and Carbon uptake
		if (model.cs.cellarea - cell.D_AreaAcc + cell.D_Area > 0) then 
			-- Vegetation growth
			if ((cell.B_ActualAGB + cell.AGBRegrowRate) >= cell.B_AGB) then
				cell.AGBRegrowRate = cell.B_AGB - cell.B_ActualAGB
				cell.B_ActualAGB = cell.B_AGB			    
			else  
				cell.B_ActualAGB = cell.B_ActualAGB + cell.AGBRegrowRate				
			end

			AGBupdated = cell.B_ActualAGB
			rate = cell.AGBRegrowRate

			-- Carbon uptake according to the rate
			cell_agb_degrad_regrow = cell.AGBRegrowRate * (model.cs.cellarea - cell.D_AreaAcc + cell.D_Area)
			cell_bgb_degrad_regrow = cell.AGBRegrowRate * cell.B_BGBPercAGB *(model.cs.cellarea - cell.D_AreaAcc + cell.D_Area)


			-- recompute growth if area was deforested for next step assume part of it was lost
			percForLost = cell.D_Area/(model.cs.cellarea - cell.D_AreaAcc + cell.D_Area)
			cell.AGBRegrowRate = cell.AGBRegrowRate*(1-percForLost)

			-- Absorption in the cell
			cell_CO2_absorption_Degrad = (cell_agb_degrad_regrow + cell_bgb_degrad_regrow) * cell.B_FactorB_CO2  
		else 
			cell.B_ActualAGB = 0
		end	

		-- Degradation and emission
		if (cell.DEGRAD_Degrad > 0) then
			-- verify if degradation is compatible with remaining forest area
			if (model.cs.cellarea - cell.D_AreaAcc + cell.D_Area) <  cell.DEGRAD_Degrad then  
				error("Error in the data: degradation is not compatible with remaining forest area", 2)
			end

			-- Contador do número de eventos na célula
			if (cell.DEGRAD_Degrad > 0 and cell.DEGRAD_AGB_loss > 0) then
				cell.countDegradYears = cell.countDegradYears + 1
				num_cell_loss = num_cell_loss + 1
			end

			-- Perda de biomassa TOTAL neste passo de tempo
			cell_agb_degrad = cell.B_ActualAGB * cell.DEGRAD_Degrad * cell.DEGRAD_AGB_loss  
			cell_bgb_degrad = cell.B_ActualAGB * cell.DEGRAD_Degrad * cell.DEGRAD_BGB_loss * cell.B_BGBPercAGB
			cell_litter_degrad = cell.B_ActualAGB * cell.DEGRAD_Degrad * cell.DEGRAD_Litter_loss * cell.B_LitterPercAGB
			cell_wood_degrad = cell.B_ActualAGB * cell.DEGRAD_Degrad * cell.DEGRAD_DeadWood_loss * cell.B_DeadWoodPercAGB

			-- Emissão decorrente da degradação
			cell_CO2_emission_Degrad = (cell_agb_degrad + cell_bgb_degrad + cell_litter_degrad + cell_wood_degrad) * cell.B_FactorB_CO2_fire  
			
			-- Atualização da biomassa média 
			if ((model.cs.cellarea - cell.D_AreaAcc + cell.D_Area) ~= 0) then
				cell.B_ActualAGB = cell.B_ActualAGB - (cell_agb_degrad / (model.cs.cellarea - cell.D_AreaAcc + cell.D_Area))
			end

			cell.DegradLoss = 0
			if (cell.B_AGB > 0) then
				cell.DegradLoss = (cell.B_AGB - cell.B_ActualAGB) / cell.B_AGB
				sum_cell_loss = sum_cell_loss + cell.DegradLoss
			end 
			
			-- Reinitialize the rate
			cell.AGBRegrowRate = 0
			if (cell.DEGRAD_PeriodRegrow ~= 0) then		   
				cell.AGBRegrowRate = (cell.B_AGB - cell.B_ActualAGB) / cell.DEGRAD_PeriodRegrow 
			end
		end   -- only if there was degration, otherwise emission is zero

		local rate2 = cell.AGBRegrowRate

		-- Correct Rate in case there is also deforestation in this step: for the next step regrow...  
		if (model.cs.cellarea - cell.D_AreaAcc + cell.D_Area > 0) then
			cell.AGBRegrowRate = cell.AGBRegrowRate * (1 - cell.D_Area / (model.cs.cellarea - cell.D_AreaAcc + cell.D_Area))
		end

		if (cell.AGBRegrowRate > 4) then 
			print (year, cell.B_AGB, AGBupdated, cell.B_ActualAGB, rate, rate2, cell.AGBRegrowRate) 
		end

		model.DEGRAD_result[year].DEGRAD_Area = model.DEGRAD_result[year].DEGRAD_Area + cell.DEGRAD_Degrad

		-- Aggregating results at the regional level (summing cells)
		model.DEGRAD_result[year].DEGRAD_CO2_emission = model.DEGRAD_result[year].DEGRAD_CO2_emission + cell_CO2_emission_Degrad
		model.DEGRAD_result[year].DEGRAD_CO2_absorption = model.DEGRAD_result[year].DEGRAD_CO2_absorption + cell_CO2_absorption_Degrad 

		-- Aggregating results at the regional level (summing cells): considering only cell above Degrad Limiar
		if (cell.countDegradYears >=  cell.DEGRAD_LimiarDegradYears and cell.DegradLoss >= cell.DEGRAD_LimiarDegradLoss) then
			model.DEGRAD_result[year].DEGRAD_CO2_emission_aboveDegradLimiar = model.DEGRAD_result[year].DEGRAD_CO2_emission_aboveDegradLimiar + cell_CO2_emission_Degrad
			model.DEGRAD_result[year].DEGRAD_CO2_absorption_aboveDegradLimiar = model.DEGRAD_result[year].DEGRAD_CO2_absorption_aboveDegradLimiar + cell_CO2_absorption_Degrad 
		end

		if (model.save == true) then 
			cell[model.componentDEGRAD.attrActualAGB..year] = cell.B_ActualAGB  
			cell[model.componentDEGRAD.attrCountDegradYears..year] = cell.countDegradYears  
		end 
	end

	if (num_cell_loss > 0) then 
		model.DEGRAD_result[year].DEGRAD_AveLoss = sum_cell_loss / num_cell_loss 
	end

end

-- Handles with the creation of a null DEGRAD component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_createNullComponent(model)
function componentDEGRAD_createNullComponent(model)
	if model ~= nil then
	model.componentDEGRAD = {
								name = "undefined",
								description = "",
								averAGB_loss = 0,
								averBGB_loss = 0,
								averDeadWood_loss = 0,
								averLitter_loss = 0,
								averDegrad = 0,
								PeriodRegrow = 1,
								LimiarDegradYears = 1,
								LimiarDegradLoss = 0
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

	model.componentDEGRAD.attrActualAGB = "AGB_"
	model.componentDEGRAD.attrCountDegradYears = "Count_"

	if (model.save == true) then 
		for year = model.yearInit, model.yearFinal, 1 do                            
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrActualAGB..year  
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrCountDegradYears..year   
		end	    
	end

	-- init (runtime) future cellattribute names
	model.componentDEGRAD.attrAGB_loss = model.componentDEGRAD.name.."AGB_loss_"  
	model.componentDEGRAD.attrBGB_loss = model.componentDEGRAD.name.."BGB_loss_"  
	model.componentDEGRAD.attrDeadWood_loss = model.componentDEGRAD.name.."DeadWood_loss_"    
	model.componentDEGRAD.attrLitter_loss = model.componentDEGRAD.name.."Litter_loss_"   
	model.componentDEGRAD.attrPeriodRegrow = model.componentDEGRAD.name.."PeriodRegrow_"   


	forEachCell(model.cs, function(cell)
							cell.DEGRAD_AGB_loss = 0
							cell.DEGRAD_BGB_loss = 0
							cell.DEGRAD_DeadWood_loss = 0
							cell.DEGRAD_Litter_loss = 0
							cell.DEGRAD_Degrad = 0	
							cell.DEGRAD_PeriodRegrow = 1 
							cell.DEGRAD_LimiarDegradYears = 1
							cell.DEGRAD_LimiarDegradLoss = 1
							cell.DEGRAD_AGB_percReduction = 0

							cell.lossDegradAGB = {}
							cell.regrowRateDegradAGB = {}

							cell.countDegradYears = 0

							componentDEGRAD_initCellAverComponentValues (cell, model)
						end
				)

	componentDEGRAD_initCellAttrNames(model)
end

-- Handles with the cell attributes inicialization.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_initCellAttrNames(model)
function componentDEGRAD_initCellAttrNames(model)
	model.componentDEGRAD.attrDegrad = model.componentDEGRAD.name.."_darea"	
	model.componentDEGRAD.attrAGB_loss = model.componentDEGRAD.name.."_loss1"
	model.componentDEGRAD.attrBGB_loss = model.componentDEGRAD.name.."_loss2"
	model.componentDEGRAD.attrDeadWood_loss = model.componentDEGRAD.name.."_loss3"
	model.componentDEGRAD.attrLitter_loss = model.componentDEGRAD.name.."_loss4"

	model.componentDEGRAD.attrPeriodRegrow = model.componentDEGRAD.name.."_pr"	
	model.componentDEGRAD.attrLimiarDegradYears = model.componentDEGRAD.name.."_lim1"	
	model.componentDEGRAD.attrLimiarDegradLoss = model.componentDEGRAD.name.."_lim2"	
end	

-- Handles with the initialization of the cell with average values.
-- @arg cell A cell of a Cellular Space.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_createNullComponent(model)
function componentDEGRAD_initCellAverComponentValues(cell, model)
  cell.DEGRAD_AGB_loss = model.componentDEGRAD.averAGB_loss
  cell.DEGRAD_AGB_percReduction = model.componentDEGRAD.averAGB_percReduction
  cell.DEGRAD_BGB_loss = model.componentDEGRAD.averBGB_loss
  cell.DEGRAD_DeadWood_loss = model.componentDEGRAD.averDeadWood_loss
  cell.DEGRAD_Litter_loss = model.componentDEGRAD.averLitter_loss
  cell.DEGRAD_Degrad = model.componentDEGRAD.averDegrad
  cell.DEGRAD_PeriodRegrow = model.componentDEGRAD.averPeriodRegrow
  cell.DEGRAD_LimiarDegradYears = model.componentDEGRAD.averLimiarDegradYears
  cell.DEGRAD_LimiarDegradLoss = model.componentDEGRAD.averLimiarDegradLoss
end

-- Handles with the verify method of a DEGRAD component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_verify(model)
function componentDEGRAD_verify (model)
	if (model.componentDEGRAD.name == nil) then 
		error("Missing DEGRAD parameter: name", 2) 
	end

	if (model.componentDEGRAD.description == nil) then
		error("Missing DEGRAD parameter: description", 2)
	end

	if (model.componentDEGRAD.averAGB_loss == nil) then
		error("Missing DEGRAD parameter: averAGB_loss", 2)
	end

	if (model.componentDEGRAD.averBGB_loss == nil) then
		error("Missing DEGRAD parameter: averBGB_loss", 2)
	end

	if (model.componentDEGRAD.averDeadWood_loss == nil) then
		error("Missing DEGRAD parameter: averDeadWood_loss", 2)
	end

	if (model.componentDEGRAD.averLitter_loss == nil) then
		error("Missing DEGRAD parameter: averLitter_loss", 2)
	end

	if (model.componentDEGRAD.averPeriodRegrow == nil) then
		error("Missing DEGRAD parameter: averPeriodRegrow", 2)
	end

	if (model.componentDEGRAD.averLimiarDegradYears == nil) then
		error("Missing DEGRAD parameter: averLimiarDegradYears", 2)
	end

	if (model.componentDEGRAD.averLimiarDegradLoss == nil) then
		error("Missing DEGRAD parameter: averLimiarDegradLoss", 2)
	end

	return true
end

-- Handles with the load of the attributes from the database or shape.
-- @arg model A INPE-EM Model.
-- @arg cell_temp A cell of Cellular Space.
-- @arg cell A cell of Cellular Space.
-- @arg y A year value.
-- @usage --DONTRUN
-- componentDEGRAD_loadFromDB(model, cell_temp, cell, y)
function componentDEGRAD_loadFromDB(model, cell_temp, cell, y)
	y = string.sub(y, string.len(y) - 1)
	
	if cell_temp[model.componentDEGRAD.attrDegrad..y] ~= nil then
		cell.degrad = cell_temp[model.componentDEGRAD.attrDegrad..y]
	end
	
	if (cell_temp[model.componentDEGRAD.attrAGB_loss..y] ~= nil) then
		cell.DEGRAD_AGB_loss = cell_temp[model.componentDEGRAD.attrAGB_loss..y]
	end

	if (cell_temp[model.componentDEGRAD.attrBGB_loss..y] ~= nil) then
		cell.DEGRAD_BGB_loss = cell_temp[model.componentDEGRAD.attrBGB_loss..y]
	end

	if (cell_temp[model.componentDEGRAD.attrLitter_loss..y] ~= nil) then
		cell.DEGRAD_Litter_loss = cell_temp[model.componentDEGRAD.attrLitter_loss..y]
	end


	if (cell_temp[model.componentDEGRAD.attrDeadWood_loss..y] ~= nil) then
		cell.DEGRAD_DeadWood_loss = cell_temp[model.componentDEGRAD.attrDeadWood_loss..y]
	end

	if (cell_temp[model.componentDEGRAD.attrDegrad..y] ~= nil) then
		cell.DEGRAD_Degrad 	= cell_temp[model.componentDEGRAD.attrDegrad..y] * model.cs.cellarea
	end

	if (cell_temp[model.componentDEGRAD.PeriodRegrow] ~= nil) then
		cell.DEGRAD_PeriodRegrow = cell_temp[model.componentDEGRAD.PeriodRegrow]
	end

	if (cell_temp[model.componentDEGRAD.LimiarDegradYears] ~= nil) then
		cell.DEGRAD_LimiarDegradYears = cell_temp[model.componentDEGRAD.LimiarDegradYears]
	end

	if (cell_temp[model.componentDEGRAD.LimiarDegradLoss] ~= nil) then
		cell.LimiarDegradLoss = cell_temp[model.componentDEGRAD.LimiarDegradLoss]
	end
end

-- Handles with the load of the attributes from a table (used with non-spatial model).
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentD_loadFromTable(model)
function componentDEGRAD_loadFromTable(model, cell, step)
	if (model.dataTable.AGB_loss ~= nil) then
		if (#model.dataTable.AGB_loss < step) then
			error ("Time required exceeds the input table size: AGB loss", 2) 
		end
		
		cell.DEGRAD_AGB_loss = model.dataTable.AGB_loss[step]
	end

	if (model.dataTable.BGB_loss ~= nil) then
		if (#model.dataTable.BGB_loss < step) then
			error ("Time required exceeds the input table size: BGB loss", 2) 
		end
		
		cell.DEGRAD_BGB_loss = model.dataTable.BGB_loss[step]
	end

	if (model.dataTable.Litter_loss ~= nil) then
		if (#model.dataTable.Litter_loss < step) then
			error ("Time required exceeds the input table size: Litter loss", 2) 
		end
		
		cell.DEGRAD_Litter_loss = model.dataTable.Litter_loss[step]
	end

	if (model.dataTable.DeadWood_loss ~= nil) then
		if (#model.dataTable.DeadWood_loss < step) then
			error ("Time required exceeds the input table size: Dead Wood loss", 2) 
		end
		
		cell.DEGRAD_DeadWood_loss = model.dataTable.DeadWood_loss[step]
	end

	if (model.dataTable.Degrad ~= nil) then
		if (#model.dataTable.Degrad < step) then
			error ("Time required exceeds the input table size: Degrad", 2) 
		end

		cell.DEGRAD_Degrad = model.dataTable.Degrad[step]
	end

	if (model.dataTable.PeriodRegrow ~= nil) then
		if (#model.dataTable.PeriodRegrow < step) then
			error ("Time required exceeds the input table size: PeriodRegrow", 2) 
		end
		
		cell.DEGRAD_PeriodRegrow = model.dataTable.PeriodRegrow[step]
	end

	if (model.dataTable.LimiarDegradYears ~= nil) then
		if (#model.dataTable.LimiarDegradYears < step) then
			error ("Time required exceeds the input table size: LimiarDegradYears", 2) 
		end
		
		cell.DEGRAD_LimiarDegradYears = model.dataTable.LimiarDegradYears[step]
	end

	if (model.dataTable.LimiarDegradLoss ~= nil) then
		if (#model.dataTable.LimiarDegradLoss < step) then
			error ("Time required exceeds the input table size: LimiarDegradLoss", 2) 
		end
		
		cell.DEGRAD_LimiarDegradLoss = model.dataTable.LimiarDegradLoss[step]
	end
end
 