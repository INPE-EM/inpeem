-- Handles with the DEGRAD component execution.
-- @arg year A year for simulation.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_execute(year, model)
function componentDEGRAD_execute(year, model)
	if (model.verbose) then 
		print(year, "Executing Degrad - mode:"..model.mode)
	end

	local hasRegrowRates = model.componentDEGRAD.regrowRates ~= nil
	local regrowRates = model.componentDEGRAD.regrowRates
						 
	local sumCellLoss = 0
	local numCellLoss = 0
	local percForLost = 0
	
	local cellCO2AbsorptionDegrad = 0
	local cellCO2EmissionDegrad = 0
	
	local cellAGBDegradRegrow = 0
    local cellBGBDegradRegrow = 0
	
	local cell_agb_degrad = 0
	local cell_bgb_degrad = 0
	local cell_litter_degrad = 0
	local cell_wood_degrad = 0
	
	local cellAllDecay = 0
	local cellAllFire = 0
	
	local cellCH4AllFire = 0
	local cellCO2EqCH4AllFire = 0
	
	local cellN2OAllFire = 0
	local cellCO2EqN2OAllFire = 0
	
	local cellCOAllFire = 0
	local cellCO2EqCOAllFire = 0
	
	local cellNOxAllFire = 0
	local cellCO2EqNOxAllFire = 0
	
	local  Biomassa = 0
	
	for k, cell in pairs (model.cs.cells) do
		cellAllDecay = 0
		cellAllFire = 0
		cellCO2AllFire = 0
		cellCO2AllDecay = 0
		cellCO2AllComponents = 0
		cellCH4AllFire = 0
		cellCO2EqCH4AllFire = 0
		cellN2OAllFire = 0
		cellCO2EqN2OAllFire = 0
		cellCOAllFire = 0
		cellCO2EqCOAllFire = 0
		cellNOxAllFire = 0
		cellCO2EqNOxAllFire = 0
		
		if (year == model.yearInit) then 
			cell.remainingForestArea = cell.D_Forest
			cell.B_CurrentAGB = cell.B_AGB
			cell.B_AfterDisturbDiffAGB = 0
		end
		
		if (cell.remainingForestArea < 0) then
			cell.remainingForestArea = 0
		end
		
		if (model.mode == "non_spatial") then
			if (cell.DEGRAD_Degrad > 0 and cell.DEGRAD_AGBLoss > 0) then
				flagDEGRAD = true
			end
		end

		cellCO2AbsorptionDegrad = 0
		cellCO2EmissionDegrad = 0
				
		-- Current average biomass in the cell
		if (year == model.yearInit) then 
			cell.AGBRegrowRate = 0 	
			cell.DegradLoss = 0
			cell.DegradStep = 0
				
			if (model.mode == "spatial") then
				if (flagDEGRAD) then
					cell.B_CurrentAGB = cell.B_AGB * (1 - cell.DEGRAD_AGBPercReduction)
				end
				
				if (not hasRegrowRates) then
					-- Reinitialize the rate
					cell.AGBRegrowRate = 0
					if (cell.DEGRAD_PeriodRegrow ~= 0) then
						cell.AGBRegrowRate = (cell.B_AGB - cell.B_CurrentAGB) / cell.DEGRAD_PeriodRegrow 
					end
				end
			end
		end
		
		-- REGROW AND CARBON UPTAKE
		if (cell.remainingForestArea > 0) then 
			-- linear
			if (not hasRegrowRates) then 
				-- Vegetation growth
				if ((cell.B_CurrentAGB + cell.AGBRegrowRate) >= cell.B_AGB) then
					cell.AGBRegrowRate = cell.B_AGB - cell.B_CurrentAGB
					cell.B_CurrentAGB = cell.B_AGB		
				else  
					cell.B_CurrentAGB = cell.B_CurrentAGB + cell.AGBRegrowRate				
				end
				
				-- Carbon uptake according to the rate
				cellAGBDegradRegrow = cell.AGBRegrowRate * cell.remainingForestArea
				cellBGBDegradRegrow = cell.AGBRegrowRate * cell.B_BGBPercAGB * cell.remainingForestArea
				
				-- Recompute growth if area was deforested for next step assume part of it was lost
				percForLost = cell.D_Area / cell.remainingForestArea
				cell.AGBRegrowRate = cell.AGBRegrowRate * (1 - percForLost)
			else	
				
				if cell.DegradStep > 0 then 
					local B_aux = cell.B_CurrentAGB
			
					cell.B_CurrentAGB = cell.B_CurrentAGB + (cell.B_AfterDisturbDiffAGB * regrowRates[cell.DegradStep])
					
					-- Atualização da biomassa média
					cellAGBDegradRegrow = (cell.B_CurrentAGB - B_aux) * cell.remainingForestArea 
					cellBGBDegradRegrow = (cell.B_CurrentAGB - B_aux) * cell.B_BGBPercAGB * cell.remainingForestArea
					
					cell.DegradStep = cell.DegradStep + 1 									
				end	

			end
			-- Absorption in the cell
			cellCO2AbsorptionDegrad = (cellAGBDegradRegrow + cellBGBDegradRegrow) * cell.B_FactorB_CO2  
		end	


		-- DEGRADATION AND EMISSION
		if (cell.DEGRAD_Degrad > 0) then
			-- verify if degradation is compatible with remaining forest area
			if (cell.remainingForestArea < cell.DEGRAD_Degrad) then  
				cell.DEGRAD_Degrad = cell.remainingForestArea
			end

				-- Contador do número de eventos na célula
			if ((cell.DEGRAD_Degrad > 0) and (cell.DEGRAD_AGBLoss > 0)) then
				cell.countDegradYears = cell.countDegradYears + 1
				numCellLoss = numCellLoss + 1
			end
			
			-- Perda de biomassa TOTAL neste passo de tempo
			cell_agb_degrad = cell.B_CurrentAGB * cell.DEGRAD_Degrad * cell.DEGRAD_AGBLoss  
			cell_bgb_degrad = cell.B_CurrentAGB * cell.DEGRAD_Degrad * cell.DEGRAD_BGBLoss * cell.B_BGBPercAGB
			cell_litter_degrad = cell.B_CurrentAGB * cell.DEGRAD_Degrad * cell.DEGRAD_LitterLoss * cell.B_LitterPercAGB
			cell_wood_degrad = cell.B_CurrentAGB * cell.DEGRAD_Degrad * cell.DEGRAD_DeadWoodLoss * cell.B_DeadWoodPercAGB
			
			-- Emissão decorrente da degradação
            cellAllFire = cell_agb_degrad + cell_bgb_degrad + cell_litter_degrad + cell_wood_degrad
            
			-- CO2 EMISSIONS
			cellCO2EmissionDegrad = cellAllFire * cell.B_FactorB_CO2Fire  
            
            -- CH4 EMISSIONS - fire components
            cellCH4AllFire = cellAllFire * cell.B_FactorB_CH4Fire
            cellCO2EqCH4AllFire = cellCH4AllFire * model.gwpCH4

            -- N2O EMISSIONS - fire components
            cellN2OAllFire = cellAllFire * cell.B_FactorB_N2OFire
            cellCO2EqN2OAllFire = cellN2OAllFire * model.gwpN2O

            -- CO EMISSIONS - fire components
            cellCOAllFire = cellAllFire * cell.B_FactorB_COFire
            cellCO2EqCOAllFire = cellCOAllFire * model.gwpCO

            -- NOx EMISSIONS - fire components
            cellNOxAllFire = cellAllFire * cell.B_FactorB_NOxFire
            cellCO2EqNOxAllFire = cellNOxAllFire * model.gwpNOx
			
			-- Atualização da biomassa média 
			if (cell.remainingForestArea ~= 0) then
				cell.B_CurrentAGB = cell.B_CurrentAGB - (cell_agb_degrad / cell.remainingForestArea)
			end

			cell.DegradLoss = 0
			if (cell.B_AGB > 0) then
				cell.DegradLoss = (cell.B_AGB - cell.B_CurrentAGB) / cell.B_AGB
				sumCellLoss = sumCellLoss + cell.DegradLoss
			end 
			
			-- Reinitialize the rate
			if (not hasRegrowRates) then 
				cell.AGBRegrowRate = 0
				if (cell.DEGRAD_PeriodRegrow ~= 0) then		   
					cell.AGBRegrowRate = (cell.B_AGB - cell.B_CurrentAGB) / cell.DEGRAD_PeriodRegrow 
				end
			else	
				cell.DegradStep = 1
				cell.B_AfterDisturbDiffAGB = cell.B_AGB - cell.B_CurrentAGB
			end
		end   -- only if there was degration, otherwise emission is zero

		-- Correct Rate in case there is also deforestation in this step: for the next step regrow...  
		if (cell.remainingForestArea > 0) then
			if (not hasRegrowRates) then
				cell.AGBRegrowRate = cell.AGBRegrowRate * (1 - (cell.D_Area / cell.remainingForestArea))
			else
				cell.B_AfterDisturbDiffAGB = cell.B_AfterDisturbDiffAGB * (1 - (cell.D_Area / cell.remainingForestArea))
			end
		end
		if (model.save == true) then 
			cell[model.componentDEGRAD.attrActualAGB..year] = cell.B_CurrentAGB  
			cell[model.componentDEGRAD.attrCountDegradYears..year] = cell.countDegradYears  
			
            cell[model.componentDEGRAD.attrCO2..year] = cellCO2EmissionDegrad / 1000000
            cell[model.componentDEGRAD.attrCH4..year] = cellCH4AllFire / 1000000
			cell[model.componentDEGRAD.attrN2O..year] = cellN2OAllFire / 1000000
			cell[model.componentDEGRAD.attrCO..year] = cellCOAllFire / 1000000
			cell[model.componentDEGRAD.attrNOx..year] = cellNOxAllFire / 1000000 
			cell[model.componentDEGRAD.attrCO2In..year] = cellCO2AbsorptionDegrad / 1000000 
		end 
		
		model.DEGRAD_Result[year].DEGRAD_Area = model.DEGRAD_Result[year].DEGRAD_Area + cell.DEGRAD_Degrad

		-- Aggregating results at the regional level (summing cells)
		model.DEGRAD_Result[year].DEGRAD_CO2Emission = model.DEGRAD_Result[year].DEGRAD_CO2Emission + cellCO2EmissionDegrad
		model.DEGRAD_Result[year].DEGRAD_CO2Absorption = model.DEGRAD_Result[year].DEGRAD_CO2Absorption + cellCO2AbsorptionDegrad 

		-- Aggregating results at the regional level (summing cells): considering only cell above Degrad Limiar
		if ((cell.countDegradYears >=  cell.DEGRAD_LimiarDegradYears) and (cell.DegradLoss >= cell.DEGRAD_LimiarDegradLoss)) then
			model.DEGRAD_Result[year].DEGRAD_CO2EmissionAboveDegradLimiar = model.DEGRAD_Result[year].DEGRAD_CO2EmissionAboveDegradLimiar + cellCO2EmissionDegrad
			model.DEGRAD_Result[year].DEGRAD_CO2AbsorptionAboveDegradLimiar = model.DEGRAD_Result[year].DEGRAD_CO2AbsorptionAboveDegradLimiar + cellCO2AbsorptionDegrad 
            model.DEGRAD_Result[year].DEGRAD_CH4Eq2ndOrderFire = model.DEGRAD_Result[year].DEGRAD_CH4Eq2ndOrderFire + cellCO2EqCH4AllFire      
            model.DEGRAD_Result[year].DEGRAD_N2OEq2ndOrderFire = model.DEGRAD_Result[year].DEGRAD_N2OEq2ndOrderFire + cellCO2EqN2OAllFire
            model.DEGRAD_Result[year].DEGRAD_COEq2ndOrderFire = model.DEGRAD_Result[year].DEGRAD_COEq2ndOrderFire + cellCO2EqCOAllFire
            model.DEGRAD_Result[year].DEGRAD_NOxEq2ndOrderFire = model.DEGRAD_Result[year].DEGRAD_NOxEq2ndOrderFire + cellCO2EqNOxAllFire
		end
		
		Biomassa = cell.B_CurrentAGB
		
		-- Calculate forest for the next year
		cell.remainingForestArea = cell.remainingForestArea - cell.D_Area
	end
	
	print ("--------------------------------------------")
	print ("Biomassa: "..Biomassa)
	print ("--------------------------------------------")
	Biomassa = 0
	
	if (numCellLoss > 0) then 
		model.DEGRAD_Result[year].DEGRAD_AveLoss = sumCellLoss / numCellLoss 
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

	model.componentDEGRAD.attrActualAGB = "dAGB_"
	model.componentDEGRAD.attrCountDegradYears = "Count_"
	
	model.componentDEGRAD.attrCO2 = "dCO2_"
	model.componentDEGRAD.attrCH4 = "dCH4_"
	model.componentDEGRAD.attrN2O = "dN2O_"
	model.componentDEGRAD.attrCO = "dCO_"
	model.componentDEGRAD.attrNOx = "dNOx_"
	model.componentDEGRAD.attrCO2In = "dICO2_"

	if (model.save == true) then 
		for year = model.yearInit, model.yearFinal, 1 do                            
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrActualAGB..year  
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrCountDegradYears..year   
            model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrCO2..year
            model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrCH4..year
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrN2O..year
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrCO..year
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrNOx..year
			model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
			model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrCO2In..year
		end	    
	end

	-- init (runtime) future cellattribute names
	model.componentDEGRAD.attrAGB_loss = model.componentDEGRAD.name.."AGB_loss_"  
	model.componentDEGRAD.attrBGB_loss = model.componentDEGRAD.name.."BGB_loss_"  
	model.componentDEGRAD.attrDeadWood_loss = model.componentDEGRAD.name.."DeadWood_loss_"    
	model.componentDEGRAD.attrLitter_loss = model.componentDEGRAD.name.."Litter_loss_"   
	model.componentDEGRAD.attrPeriodRegrow = model.componentDEGRAD.name.."PeriodRegrow_"   


	forEachCell(model.cs, function(cell)
							cell.DEGRAD_Degrad = 0	
							cell.DEGRAD_AGBLoss = 0
							cell.DEGRAD_BGBLoss = 0
							cell.DEGRAD_DeadWoodLoss = 0
							cell.DEGRAD_LitterLoss = 0
							cell.DEGRAD_PeriodRegrow = 1 
							cell.DEGRAD_LimiarDegradYears = 1
							cell.DEGRAD_LimiarDegradLoss = 1
							cell.DEGRAD_AGBPercReduction = 0

							cell.lossDegradAGB = {}
							cell.regrowRateDegradAGB = {}

							cell.countDegradYears = 0
							cell.remainingForestArea = 0

							componentDEGRAD_initCellAverComponentValues(cell, model)
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
	cell.DEGRAD_AGBLoss = model.componentDEGRAD.averAGB_loss
	cell.DEGRAD_AGBPercReduction = model.componentDEGRAD.averAGB_percReduction
	cell.DEGRAD_BGBLoss = model.componentDEGRAD.averBGB_loss
	cell.DEGRAD_DeadWoodLoss = model.componentDEGRAD.averDeadWood_loss
	cell.DEGRAD_LitterLoss = model.componentDEGRAD.averLitter_loss
	cell.DEGRAD_Degrad = model.componentDEGRAD.averDegrad
	cell.DEGRAD_PeriodRegrow = model.componentDEGRAD.averPeriodRegrow
	cell.DEGRAD_LimiarDegradYears = model.componentDEGRAD.averLimiarDegradYears
	cell.DEGRAD_LimiarDegradLoss = model.componentDEGRAD.averLimiarDegradLoss
end

-- Handles with the verify method of a DEGRAD component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_verify(model)
function componentDEGRAD_verify(model)
	if (model.componentDEGRAD.name == nil) then 
		print("Error - Missing DEGRAD parameter: name") 
		os.exit()
	end

	if (model.componentDEGRAD.description == nil) then
		print("Error - Missing DEGRAD parameter: description")
		os.exit()
	end

	if (model.componentDEGRAD.averAGB_loss == nil) then
		print("Error - Missing DEGRAD parameter: averAGB_loss")
		os.exit()
	end

	if (model.componentDEGRAD.averBGB_loss == nil) then
		print("Error - Missing DEGRAD parameter: averBGB_loss")
		os.exit()
	end

	if (model.componentDEGRAD.averDeadWood_loss == nil) then
		print("Error - Missing DEGRAD parameter: averDeadWood_loss")
		os.exit()
	end

	if (model.componentDEGRAD.averLitter_loss == nil) then
		print("Error - Missing DEGRAD parameter: averLitter_loss")
		os.exit()
	end

	if (model.componentDEGRAD.averPeriodRegrow == nil) then
		print("Error - Missing DEGRAD parameter: averPeriodRegrow")
		os.exit()
	end

	if (model.componentDEGRAD.averLimiarDegradYears == nil) then
		print("Error - Missing DEGRAD parameter: averLimiarDegradYears")
		os.exit()
	end

	if (model.componentDEGRAD.averLimiarDegradLoss == nil) then
		print("Error - Missing DEGRAD parameter: averLimiarDegradLoss")
		os.exit()
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

	if (cell_temp[model.componentDEGRAD.attrDegrad..y] ~= nil) then
		cell.DEGRAD_Degrad 	= cell_temp[model.componentDEGRAD.attrDegrad..y]
	end	
	
	if (cell_temp[model.componentDEGRAD.attrAGB_loss..y] ~= nil) then
		cell.DEGRAD_AGBLoss = cell_temp[model.componentDEGRAD.attrAGB_loss..y]
	end

	if (cell_temp[model.componentDEGRAD.attrBGB_loss..y] ~= nil) then
		cell.DEGRAD_BGBLoss = cell_temp[model.componentDEGRAD.attrBGB_loss..y]
	end

	if (cell_temp[model.componentDEGRAD.attrLitter_loss..y] ~= nil) then
		cell.DEGRAD_LitterLoss = cell_temp[model.componentDEGRAD.attrLitter_loss..y]
	end

	if (cell_temp[model.componentDEGRAD.attrDeadWood_loss..y] ~= nil) then
		cell.DEGRAD_DeadWoodLoss = cell_temp[model.componentDEGRAD.attrDeadWood_loss..y]
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
			print("Error - Time required exceeds the input table size: AGB loss") 
			os.exit()
		end
		
		cell.DEGRAD_AGBLoss = model.dataTable.AGB_loss[step]
	end

	if (model.dataTable.BGB_loss ~= nil) then
		if (#model.dataTable.BGB_loss < step) then
			print("Error - Time required exceeds the input table size: BGB loss") 
			os.exit()
		end
		
		cell.DEGRAD_BGBLoss = model.dataTable.BGB_loss[step]
	end

	if (model.dataTable.Litter_loss ~= nil) then
		if (#model.dataTable.Litter_loss < step) then
			print("Error - Time required exceeds the input table size: Litter loss") 
		end
		
		cell.DEGRAD_LitterLoss = model.dataTable.Litter_loss[step]
	end

	if (model.dataTable.DeadWood_loss ~= nil) then
		if (#model.dataTable.DeadWood_loss < step) then
			print("Error - Time required exceeds the input table size: Dead Wood loss") 
			os.exit()
		end
		
		cell.DEGRAD_DeadWoodLoss = model.dataTable.DeadWood_loss[step]
	end

	if (model.dataTable.Degrad ~= nil) then
		if (#model.dataTable.Degrad < step) then
			print("Error - Time required exceeds the input table size: Degrad")
			os.exit()
		end

		cell.DEGRAD_Degrad = model.dataTable.Degrad[step]
	end

	if (model.dataTable.PeriodRegrow ~= nil) then
		if (#model.dataTable.PeriodRegrow < step) then
			print("Error - Time required exceeds the input table size: PeriodRegrow")
			os.exit()
		end
		
		cell.DEGRAD_PeriodRegrow = model.dataTable.PeriodRegrow[step]
	end

	if (model.dataTable.LimiarDegradYears ~= nil) then
		if (#model.dataTable.LimiarDegradYears < step) then
			print("Error - Time required exceeds the input table size: LimiarDegradYears")
			os.exit()
		end
		
		cell.DEGRAD_LimiarDegradYears = model.dataTable.LimiarDegradYears[step]
	end

	if (model.dataTable.LimiarDegradLoss ~= nil) then
		if (#model.dataTable.LimiarDegradLoss < step) then
			print("Error - Time required exceeds the input table size: LimiarDegradLoss")
			os.exit()
		end
		
		cell.DEGRAD_LimiarDegradLoss = model.dataTable.LimiarDegradLoss[step]
	end
end
 