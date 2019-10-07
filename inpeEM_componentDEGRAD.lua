-- Handles with the DEGRAD component execution.
-- @arg year A year for simulation.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentDEGRAD_execute(year, model)
function componentDEGRAD_execute(year, model)
	if (model.verbose) then 
		print(year, "Executing Degrad - mode:"..model.mode)
	end

	local flagEquation = model.componentDEGRAD.equationFlag
	local eqRegrowRate = { 0.068965733, 0.040628348, 0.028924917, 0.022481008, 0.01839198, 0.015563613, 0.013489763, 0.011903615, 0.010651032, 
						   0.009636704, 0.008798504, 0.008094194, 0.007494051, 0.006976549, 0.006525713, 0.006129438, 0.005778385, 0.00546523, 0.005184151, 
						   0.004930462, 0.004700344, 0.004490661, 0.004298806, 0.0041226, 0.003960204, 0.003810056, 0.003670823, 0.003541355, 0.003420662, 
						   0.003307881, 0.00320226, 0.003103137, 0.003009933, 0.002922132, 0.002839278, 0.002760965, 0.002686831, 0.002616549, 0.002549827, 
						   0.002486402, 0.002426036, 0.002368512, 0.002313635, 0.002261226, 0.002211124, 0.002163178, 0.002117253, 0.002073225, 0.002030977, 
						   0.001990404, 0.001951409, 0.001913902, 0.001877798, 0.001843022, 0.001809501, 0.001777168, 0.001745961, 0.001715824, 0.001686701, 
						   0.001658543, 0.001631302, 0.001604934, 0.001579399, 0.001554656, 0.001530671, 0.001507409, 0.001484838, 0.001462927, 0.001441648, 
						   0.001420974, 0.001400879, 0.001381341, 0.001362335, 0.001343841, 0.001325838, 0.001308307, 0.001291229, 0.001274588, 0.001258366, 
						   0.001242549, 0.00122712, 0.001212067, 0.001197376, 0.001183033, 0.001169026, 0.001155345, 0.001141977, 0.001128912, 0.00111614, 
						   0.001103651, 0.001091436, 0.001079486, 0.001067792, 0.001056347, 0.001045142, 0.00103417, 0.001023424, 0.001012897, 0.001002582, 
						   0.000992474, 0.000982565, 0.00097285, 0.000963323, 0.00095398, 0.000944814, 0.000935821, 0.000926996, 0.000918334, 0.000909831, 
						   0.000901482, 0.000893284, 0.000885232, 0.000877323, 0.000869552, 0.000861916, 0.000854412, 0.000847036, 0.000839786, 0.000832657, 
						   0.000825646, 0.000818752, 0.000811971, 0.0008053, 0.000798736, 0.000792278, 0.000785922, 0.000779666, 0.000773508, 0.000767446, 
						   0.000761477, 0.000755599, 0.00074981, 0.000744108, 0.000738491, 0.000732958, 0.000727506, 0.000722134, 0.00071684, 0.000711622, 
						   0.000706478, 0.000701408, 0.000696409, 0.00069148, 0.00068662, 0.000681826, 0.000677099, 0.000672436, 0.000667836, 0.000663298, 
						   0.00065882, 0.000654402, 0.000650042, 0.000645739, 0.000641492, 0.0006373, 0.000633162, 0.000629077, 0.000625043, 0.00062106, 
						   0.000617127, 0.000613244, 0.000609408, 0.000605619, 0.000601877, 0.00059818, 0.000594527, 0.000590919, 0.000587353, 0.00058383, 
						   0.000580349, 0.000576908, 0.000573507, 0.000570146, 0.000566823, 0.000563539, 0.000560292, 0.000557082, 0.000553907, 0.000550769, 
						   0.000547665, 0.000544596, 0.000541561, 0.000538559, 0.000535589, 0.000532652, 0.000529746, 0.000526872, 0.000524028, 0.000521215, 
						   0.000518431, 0.000515676, 0.00051295, 0.000510253, 0.000507583, 0.000504941, 0.000502326, 0.000499738, 0.000497175, 0.000494639, 
						   0.000492128, 0.000489642, 0.000487181, 0.000484744, 0.000482331, 0.000479942, 0.000477576, 0.000475233, 0.000472913, 0.000470614, 
						   0.000468338, 0.000466084, 0.00046385, 0.000461638, 0.000459447, 0.000457276, 0.000455125, 0.000452994, 0.000450883, 0.000448791, 
						   0.000446718, 0.000444664, 0.000442629, 0.000440612, 0.000438613, 0.000436632, 0.000434668, 0.000432722, 0.000430793, 0.000428881, 
						   0.000426985, 0.000425106, 0.000423244, 0.000421397, 0.000419566, 0.000417751, 0.000415951, 0.000414167, 0.000412397, 0.000410643, 
						   0.000408903, 0.000407178, 0.000405467, 0.00040377, 0.000402087, 0.000400418, 0.000398762, 0.00039712, 0.000395491, 0.000393876 
					     }

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
			cell.DegradStep = 1
			
			if (model.mode == "spatial") then
				if (flagDEGRAD) then
					cell.B_CurrentAGB = cell.B_AGB * (1 - cell.DEGRAD_AGBPercReduction)
				end
				
				if (not flagEquation) then
					-- Reinitialize the rate
					cell.AGBRegrowRate = 0
					if (cell.DEGRAD_PeriodRegrow ~= 0) then
						cell.AGBRegrowRate = (cell.B_AGB - cell.B_CurrentAGB) / cell.DEGRAD_PeriodRegrow 
					end
				end
			end
		end

		-- Regrowth and Carbon uptake
		if (cell.remainingForestArea > 0) then
			-- linear
			if (not flagEquation) then 
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
				cell.AGBRegrowRate = (cell.B_AGB - cell.B_CurrentAGB) * eqRegrowRate[cell.DegradStep]

				-- Vegetation growth
				if ((cell.B_CurrentAGB + cell.AGBRegrowRate) >= cell.B_AGB) then
					cell.B_CurrentAGB = cell.B_AGB		
				else  
					cell.B_CurrentAGB = cell.B_CurrentAGB + cell.AGBRegrowRate	
				end
				
				-- Carbon uptake according to the rate
				cellAGBDegradRegrow = cell.AGBRegrowRate * cell.remainingForestArea
				cellBGBDegradRegrow = cell.AGBRegrowRate * cell.B_BGBPercAGB * cell.remainingForestArea
			end
			
			-- Absorption in the cell
			cellCO2AbsorptionDegrad = (cellAGBDegradRegrow + cellBGBDegradRegrow) * cell.B_FactorB_CO2  
		end	
		
		-- Degradation and emission
		if (cell.DEGRAD_Degrad > 0) then
			cell.DegradStep = 1
			
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
			if (not flagEquation) then 
				cell.AGBRegrowRate = 0
				if (cell.DEGRAD_PeriodRegrow ~= 0) then		   
					cell.AGBRegrowRate = (cell.B_AGB - cell.B_CurrentAGB) / cell.DEGRAD_PeriodRegrow 
				end
			else
				cell.DegradStep = cell.DegradStep + 1
			end
		end   -- only if there was degration, otherwise emission is zero

		-- Correct Rate in case there is also deforestation in this step: for the next step regrow...  
		if (not flagEquation) then 
			if (cell.remainingForestArea > 0) then
				cell.AGBRegrowRate = cell.AGBRegrowRate * (1 - (cell.D_Area / cell.remainingForestArea))
			end
		else
			if (cell.DegradStep > 1 and cell.DEGRAD_Degrad <= 0) then
				cell.DegradStep = cell.DegradStep + 1
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
		
		-- Calculate forest for the next year
		cell.remainingForestArea = cell.remainingForestArea - cell.D_Area
	end
	
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
 