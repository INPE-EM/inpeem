-- Handles with the Vegetation Removal component execution.
-- @arg year A year for simulation.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentVR_execute(year, model)
function componentVR_execute(year, model)
	if (model.verbose) then
		print(year, "Executing VR - mode:"..model.mode) 
	end
	
	-- Attributes where the future emissions will be stored using the computeFutureSlashDecompositionFire and computeFutureDecomposition functions
	local attrAGBSlash = model.componentVR.attrAGBSlash 
	local attrAGBSlashFire = model.componentVR.attrAGBSlashFire 
	local attrAGBWood = model.componentVR.attrAGBWood 

	local attrBGBSlash = model.componentVR.attrBGBSlash 
	local attrBGBSlashFire = model.componentVR.attrBGBSlashFire 
	local attrBGBUnder = model.componentVR.attrBGBUnder 

	local attrDeadSlash = model.componentVR.attrDeadSlash 
	local attrDeadSlashFire = model.componentVR.attrDeadSlashFire 

	local attrLitterSlash = model.componentVR.attrLitterSlash 
	local attrLitterSlashFire = model.componentVR.attrLitterSlashFire 

	local attrElemental = model.componentVR.attrElemental 

	-- Check
	local cellAGBDisturbed = 0

	-- Init FATE 
	local cellAGB_AGB = 0
	local cellBGB_BGB = 0

	-- FATE: fire or decomposition
	local cellAGBLost1stOrder = 0
	local cellBGBLost1stOrder = 0

	-- FATE: fire first year
	local cellAGBFireFirstYear = 0
	local cellBGBFireFirstYear = 0
	local cellDeadFireFirstYear = 0
	local cellLitterFireFirstYear = 0

	-- FATE: decomposition and subsequent fire 
	local cellAGBSlash = 0
	local cellBGBSlash = 0 
	local cellDeadSlash = 0 
	local cellLitterSlash = 0 

	-- FATE: decomposition 
	local cellAGBWood = 0
	local cellBGBUnder = 0
	local cellElemental = 0	
	
	local cellDeadLost1stOrder = 0
	local cellLitterLost1stOrder = 0
	local cellCO2Lost1stOrder = 0
	
	local cellAllDecay = 0
	local cellAllFire = 0
	
	local cellCO2AllFire = 0
	local cellCO2AllDecay = 0
	local cellCO2AllComponents = 0
	
	local cellCH4AllFire = 0
	local cellCO2EqCH4AllFire = 0
	
	local cellN2OAllFire = 0
	local cellCO2EqN2OAllFire = 0
	
	local cellCOAllFire = 0
	local cellCO2EqCOAllFire = 0
	
	local cellNOxAllFire = 0
	local cellCO2EqNOxAllFire = 0
	
	for k, cell in pairs (model.cs.cells) do
		-- check
		cell.totalBiomassCheck = 0
		
		cellAGBDisturbed = 0
		cellAGB_AGB = 0
		cellBGB_BGB = 0
		cellAGBLost1stOrder = 0
		cellBGBLost1stOrder = 0
		cellAGBFireFirstYear = 0
		cellBGBFireFirstYear = 0
		cellDeadFireFirstYear = 0
		cellLitterFireFirstYear = 0
		cellAGBSlash = 0
		cellBGBSlash = 0 
		cellDeadSlash = 0 
		cellLitterSlash = 0 
		cellAGBWood = 0
		cellBGBUnder = 0
		cellElemental = 0	
		cellDeadLost1stOrder = 0
		cellLitterLost1stOrder = 0
		cellCO2Lost1stOrder = 0
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

		if (cell.D_Area > 0) then
			if (not model.DEGRAD_flag) then
				cellAGBDisturbed = cell.D_Area * cell.B_AGB
			else
				cellAGBDisturbed = cell.D_Area * cell.B_ActualAGB
			end

			-- FATE: remain alive
			cellAGB_AGB = cellAGBDisturbed * cell.VR_AGBPercAGB
			cellBGB_BGB = cellAGBDisturbed * cell.B_BGBPercAGB * cell.VR_BGBPercBGB

			-- FATE: fire first year
			cellAGBFireFirstYear = cellAGBDisturbed * cell.VR_AGBPercInstantaneous 
			cellBGBFireFirstYear = cellAGBDisturbed * cell.B_BGBPercAGB * cell.VR_BGBPercInstantaneous
			cellDeadFireFirstYear = cellAGBDisturbed * cell.B_DeadWoodPercAGB * cell.VR_DeadWoodPercInstantaneous
			cellLitterFireFirstYear = cellAGBDisturbed * cell.B_LitterPercAGB * cell.VR_LitterPercInstantaneous

			-- FATE: decomposition and subsequent fire 
			cellAGBSlash = cellAGBDisturbed * cell.VR_AGBPercDecomposition * (1 - cell.VR_DecompositonPercElementalCarbon)
			cellBGBSlash = cellAGBDisturbed * cell.B_BGBPercAGB * cell.VR_BGBPercDecompositionAbove * (1 - cell.VR_DecompositonPercElementalCarbon) 
			cellDeadSlash = cellAGBDisturbed * cell.B_DeadWoodPercAGB * cell.VR_DeadWoodPercDecomposition * (1 - cell.VR_DecompositonPercElementalCarbon)
			cellLitterSlash = cellAGBDisturbed * cell.B_LitterPercAGB * cell.VR_LitterPercDecomposition * (1 - cell.VR_DecompositonPercElementalCarbon)

			computeFutureSlashDecompositionFire(cellAGBSlash, year, model.yearFinal, cell, attrAGBSlash, attrAGBSlashFire, cell.VR_DecayRateAGBDecomposition, cell.VR_DecompositonFireCyclePeriod, model.E)
			computeFutureSlashDecompositionFire(cellBGBSlash, year, model.yearFinal, cell, attrBGBSlash, attrBGBSlashFire, cell.VR_DecayRateBGBDecompositionAbove, cell.VR_DecompositonFireCyclePeriod, model.E)
			computeFutureSlashDecompositionFire(cellDeadSlash, year, model.yearFinal, cell, attrDeadSlash, attrDeadSlashFire, cell.VR_DecayRateDeadWoodDecomposition, cell.VR_DecompositonFireCyclePeriod, model.E)
			computeFutureSlashDecompositionFire(cellLitterSlash, year, model.yearFinal, cell, attrLitterSlash, attrLitterSlashFire, cell.VR_DecayRateLitterDecomposition, cell.VR_DecompositonFireCyclePeriod, model.E)

			-- FATE: decomposition 
			cellAGBWood = cellAGBDisturbed * cell.VR_AGBPercWoodProducts
			cellBGBUnder = cellAGBDisturbed * cell.B_BGBPercAGB * cell.VR_BGBPercDecompositionUnder * (1 - cell.VR_DecompositonPercElementalCarbon) 

			cellElemental = cell.VR_DecompositonPercElementalCarbon * (cellAGBDisturbed * cell.VR_AGBPercDecomposition +
																		cellAGBDisturbed * cell.VR_AGBPercWoodProducts +
																		cellAGBDisturbed * cell.B_BGBPercAGB * cell.VR_BGBPercDecompositionAbove + 
																		cellAGBDisturbed * cell.B_DeadWoodPercAGB * cell.VR_DeadWoodPercDecomposition + 
																		cellAGBDisturbed * cell.B_LitterPercAGB * cell.VR_LitterPercDecomposition + 
																		cellAGBDisturbed * cell.B_BGBPercAGB * cell.VR_BGBPercDecompositionUnder)

			computeFutureDecomposition(cellAGBWood, year, model.yearFinal, cell, attrAGBWood, cell.VR_DecayRateWoodProducts, model.E)
			computeFutureDecomposition(cellBGBUnder, year, model.yearFinal, cell, attrBGBUnder, cell.VR_DecayRateBGBDecompositionUnder, model.E)
			computeFutureDecomposition(cellElemental, year, model.yearFinal, cell, attrElemental, cell.VR_DecayRateElementalCarbon, model.E)
		end 

		cell.totalBiomassCheck = cell.totalBiomassCheck + cellAGBFireFirstYear + cellBGBFireFirstYear + cellDeadFireFirstYear + cellLitterFireFirstYear 

		-- Compute different types os biomass loss
		-- 1st order and estimate updated biomass Mtonha-1
		cellAGBLost1stOrder = cellAGBDisturbed * (1 - cell.VR_AGBPercAGB) 
		cellBGBLost1stOrder = cellAGBDisturbed * cell.B_BGBPercAGB * (1 - cell.VR_BGBPercBGB)
		cellDeadLost1stOrder = cellAGBDisturbed * cell.B_DeadWoodPercAGB 
		cellLitterLost1stOrder = cellAGBDisturbed * cell.B_LitterPercAGB 

		cellCO2Lost1stOrder = (cellAGBLost1stOrder + cellBGBLost1stOrder + cellDeadLost1stOrder + cellLitterLost1stOrder) * cell.B_FactorB_CO2Fire

		-- 2nd order 
		cellAllDecay = cell[attrAGBSlash..year] + cell[attrBGBSlash..year] + cell[attrDeadSlash..year] + cell[attrLitterSlash..year] +
						 cell[attrAGBWood..year] + cell[attrElemental..year] + cell[attrBGBUnder..year] 

		cellAllFire = cellAGBFireFirstYear + cellBGBFireFirstYear + cell[attrAGBSlashFire..year] +	cell[attrBGBSlashFire..year] +
						cell[attrDeadSlashFire..year] + cell[attrLitterSlashFire..year] 

		-- CO2 EMISSIONS
		cellCO2AllFire = cellAllFire * cell.B_FactorB_CO2Fire
		cellCO2AllDecay = cellAllDecay * cell.B_FactorB_CO2

		-- Compute process emission 
		cellCO2AllComponents = cellCO2AllFire + cellCO2AllDecay

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

		-- Saving some results spatially explicitly
		if (model.save == true) then 
			cell[model.componentVR.attrCO2..year] = cellCO2AllComponents / 1000000
			cell[model.componentVR.attrCO2Fire..year] = cellCO2AllFire / 1000000
			cell[model.componentVR.attrCH4..year] = cellCH4AllFire / 1000000
			cell[model.componentVR.attrN2O..year] = cellN2OAllFire / 1000000
			cell[model.componentVR.attrCO..year] = cellCOAllFire / 1000000
			cell[model.componentVR.attrNOx..year] = cellNOxAllFire / 1000000 
			cell[model.componentVR.attrActualAGB..year] = cell.actualAGB 
			cell[model.componentVR.attr1stCO2..year] = cellCO2Lost1stOrder / 1000000
		end 
			
		-- Aggregating results at the regional level(summing cells)
		model.VR_Result[year].VR_CO2_1stOrder = model.VR_Result[year].VR_CO2_1stOrder + cellCO2Lost1stOrder
		model.VR_Result[year].VR_CO2_2ndOrder = model.VR_Result[year].VR_CO2_2ndOrder + cellCO2AllFire + cellCO2AllDecay
		model.VR_Result[year].VR_CO2_2ndOrderFire = model.VR_Result[year].VR_CO2_2ndOrderFire + cellCO2AllFire
		model.VR_Result[year].VR_CO2_2ndOrderDecay = model.VR_Result[year].VR_CO2_2ndOrderDecay + cellCO2AllDecay
		model.VR_Result[year].VR_CH42Eq_2ndOrderFire = model.VR_Result[year].VR_CH42Eq_2ndOrderFire + cellCO2EqCH4AllFire
		model.VR_Result[year].VR_N2OEq_2ndOrderFire = model.VR_Result[year].VR_N2OEq_2ndOrderFire + cellCO2EqN2OAllFire
		model.VR_Result[year].VR_CO2Eq_2ndOrderFire = model.VR_Result[year].VR_CO2Eq_2ndOrderFire + cellCO2EqCOAllFire
		model.VR_Result[year].VR_NOxEq_2ndOrderFire = model.VR_Result[year].VR_NOxEq_2ndOrderFire + cellCO2EqNOxAllFire
	end --end of "loop cell"
end

-- Handles with deposity of carbon to decay in future by fire.
-- @arg biomass A cell value of biomass.
-- @arg year A year for calculation.
-- @arg yearFinal A final year for calculation.
-- @arg cell A Cellular Space cell.
-- @arg attr1 An attribute name to calculate postDecay.
-- @arg attr2 An attribute name to calculate postFire.
-- @arg rate A decay rate.
-- @arg fireCycle Number of years to burn residue left on the ground.
-- @arg E Exponetial value.
-- @arg percFirstYear AGB percentage after timber exploration which burns in the first year (carbon released instantaneously).
-- @usage --DONTRUN
-- computeFutureSlashDecompositionFire(cellAGBSlash, year, model.yearFinal, cell, attrAGBSlash, attrAGBSlashFire, cell.VR_DecayRateAGBDecomposition, cell.VR_DecompositonFireCyclePeriod, model.E)
function computeFutureSlashDecompositionFire(biomass, year, yearFinal, cell, attr1, attr2, rate, fireCycle, E, percFirstYear) 
	local difference = 0.0
	local previous = biomass
	local count = 0
	local postDecay = ""
	local postFire = ""
	local fire = 0
	local percFirstYear = 0.5
	
	for y = year + 1, yearFinal, 1 do
		postDecay = attr1..y
		postFire = attr2..y 
		count = count + 1

		estimateDecay = compute_exp(biomass,(-1) * rate, y - year, E)

		if (estimateDecay < 0.0) then
			estimateDecay = 0.0
		end

		difference = previous - estimateDecay

		if (difference < 0.0) then 
			estimateDecay = 0.0
			difference = previous
		end

		cell.totalBiomassCheck = cell.totalBiomassCheck + difference

		cell[postDecay] = cell[postDecay] + difference

		previous = estimateDecay 

		if (count == fireCycle) then
			fire = estimateDecay * percFirstYear
			previous = previous - fire
			cell[postFire] = cell[postFire] + fire
			cell.totalBiomassCheck = cell.totalBiomassCheck + fire 
			count = 0
		end 
	end 
end
 
-- Handles with the deposity of carbon to decay in future.
-- @arg biomass A cell value of biomass.
-- @arg year A year for calculation.
-- @arg yearFinal A final year for calculation.
-- @arg cell A Cellular Space cell.
-- @arg attr1 An attribute name to calculate postDecay.
-- @arg rate A decay rate.
-- @arg E Exponetial value.
-- @usage --DONTRUN
-- computeFutureDecomposition(cellAGBWood, year, model.yearFinal, cell, attrAGBWood, cell.VR_DecayRateWoodProducts, model.E)
function computeFutureDecomposition(biomass, year, yearFinal, cell, attr1, rate, E) 
	local difference = 0.0
	local previous = biomass
	local count = 0
	local postDecay = ""
	
	for y = year + 1, yearFinal, 1 do
		postDecay = attr1..y

		estimateDecay = compute_exp(biomass,(-1) * rate, y - year, E)

		if (estimateDecay < 0.0) then
			estimateDecay = 0.0
		end

		difference = previous - estimateDecay

		if (difference < 0.0) then 
			estimateDecay = 0.0
			difference = previous
		end

		cell.totalBiomassCheck = cell.totalBiomassCheck + difference

		cell[postDecay] = cell[postDecay] + difference

		previous = estimateDecay 
	end 
end

-- Handles with the creation of a null Vegetation Removal component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentVR_createNullComponent(model) 
function componentVR_createNullComponent(model)
	if (model ~= nil) then
		model.componentVR = {
			name = "undefined",
			description = "",			 				 
			averAGBPercAGB = 0, 
			averAGBPercInstantaneous = 0, 
			averAGBPercWoodProducts = 0, 
			averAGBPercDecomposition = 0,

			averBGBPercBGB = 0,
			averBGBPercInstantaneous = 0,
			averBGBPercDecompositionAbove = 0, 
			averBGBPercDecompositionUnder = 0, 

			averLitterPercInstantaneous = 0,
			averLitterPercDecomposition = 0,
			averDeadWoodPercInstantaneous = 0,
			averDeadWoodPercDecomposition = 0,
			averDecompositionPercFireCycle = 0,
			averDecompositonPercElementalCarbon = 0,

			averDecayRateWoodProducts = 0, 
			averDecayRateElementalCarbon = 0, 
			averDecayRateAGBDecomposition = 0, 
			averDecayRateBGBDecompositionUnder = 0,
			averDecayRateBGBDecompositionUnderUnder = 0,
			averDecayRateLitterDecomposition = 0
		}
	end
end
			
-- Handles with the initialization method of a Vegetation Removal component.
-- @arg model A INPE-EM Model
-- @usage --DONTRUN
-- componentVR_init(model)
function componentVR_init(model)
	-- init output attributes
	model.componentVR.saveAttrs = {}
	model.componentVR.saveCount = 0

	model.componentVR.attrCO2 = "vCO2_"
	model.componentVR.attrCO2Fire = "vCO2f_"
	model.componentVR.attrCH4 = "vCH4_"
	model.componentVR.attrN2O = "vN2O_"
	model.componentVR.attrCO = "vCO_"
	model.componentVR.attrNOx = "vNOx_"
	model.componentVR.attrActualAGB = "vAGB_"
	
	model.componentVR.attr1stCO2 = "v1CO2_"

	if (model.save == true) then 
		for year = model.yearInit, model.yearFinal, 1 do 
			model.componentVR.saveCount = model.componentVR.saveCount + 1
			model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrCO2..year
			model.componentVR.saveCount = model.componentVR.saveCount + 1
			model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrCO2Fire..year
			model.componentVR.saveCount = model.componentVR.saveCount + 1
			model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrCH4..year
			model.componentVR.saveCount = model.componentVR.saveCount + 1
			model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrN2O..year
			model.componentVR.saveCount = model.componentVR.saveCount + 1
			model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrCO..year
			model.componentVR.saveCount = model.componentVR.saveCount + 1
			model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrNOx..year
			model.componentVR.saveCount = model.componentVR.saveCount + 1
			model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attr1stCO2..year
		end	 
	end

	-- init(run time) future cellattribute names
	model.componentVR.attrAGBSlash = model.componentVR.name.."agb_slash" 
	model.componentVR.attrAGBSlashFire = model.componentVR.name.."agb_slash_fire" 
	model.componentVR.attrAGBWood = model.componentVR.name.."agb_wood" 

	model.componentVR.attrBGBSlash = model.componentVR.name.."bgb_slash" 
	model.componentVR.attrBGBSlashFire = model.componentVR.name.."bgb_slash_fire" 
	model.componentVR.attrBGBUnder = model.componentVR.name.."bgb_under" 

	model.componentVR.attrDeadSlash = model.componentVR.name.."dead_slash" 
	model.componentVR.attrDeadSlashFire = model.componentVR.name.."dead_slash_fire" 

	model.componentVR.attrLitterSlash = model.componentVR.name.."litter_slash" 
	model.componentVR.attrLitterSlashFire = model.componentVR.name.."litter_slash_fire" 

	model.componentVR.attrElemental = model.componentVR.name.."_elemental" 

	forEachCell(model.cs, function(cell)
								-- init future cell variables
								for year = model.yearInit, model.yearFinal, 1 do 
									cell[model.componentVR.attrAGBSlash..year] = 0 
									cell[model.componentVR.attrAGBWood..year] = 0 
									cell[model.componentVR.attrAGBSlashFire..year] = 0 

									cell[model.componentVR.attrBGBSlash..year] = 0 
									cell[model.componentVR.attrBGBSlashFire..year] = 0 
									cell[model.componentVR.attrBGBUnder..year] = 0 

									cell[model.componentVR.attrDeadSlash..year] = 0 
									cell[model.componentVR.attrDeadSlashFire..year] = 0 

									cell[model.componentVR.attrLitterSlash..year] = 0 
									cell[model.componentVR.attrLitterSlashFire..year] = 0 

									cell[model.componentVR.attrElemental..year] = 0 
								end
								
								-- init default values in each cell
								componentVR_initCellAverComponentValues(cell, model)
							end
				)

	-- init database attr names for component parameters
	componentVR_initCellAttrNames(model)
end
 
-- Handles with the initialization of the cell with average values.
-- @arg cell A cell of a Cellular Space.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentVR_initCellAverComponentValues(cell, model)
function componentVR_initCellAverComponentValues(cell, model)
	cell.VR_AGBPercAGB = model.componentVR.averAGBPercAGB 
	cell.VR_AGBPercWoodProducts = model.componentVR.averAGBPercWoodProducts 
	cell.VR_AGBPercInstantaneous = model.componentVR.averAGBPercInstantaneous 
	cell.VR_AGBPercDecomposition = model.componentVR.averAGBPercDecomposition
	
	cell.VR_LitterPercInstantaneous = model.componentVR.averLitterPercInstantaneous 
	cell.VR_LitterPercDecomposition = model.componentVR.averLitterPercDecomposition 

	cell.VR_DeadWoodPercInstantaneous = model.componentVR.averDeadWoodPercInstantaneous 
	cell.VR_DeadWoodPercDecomposition = model.componentVR.averDeadWoodPercDecomposition 

	cell.VR_BGBPercBGB = model.componentVR.averBGBPercBGB
	cell.VR_BGBPercInstantaneous = model.componentVR.averBGBPercInstantaneous
	cell.VR_BGBPercDecompositionAbove = model.componentVR.averBGBPercDecompositionAbove
	cell.VR_BGBPercDecompositionUnder = model.componentVR.averBGBPercDecompositionUnder
	
	cell.VR_DecompositonPercElementalCarbon = model.componentVR.averDecompositonPercElementalCarbon
	cell.VR_DecompositonFireCyclePeriod = model.componentVR.averDecompositonFireCyclePeriod 
	
	cell.VR_DecayRateAGBDecomposition = model.componentVR.averDecayRateAGBDecomposition 
	cell.VR_DecayRateWoodProducts = model.componentVR.averDecayRateWoodProducts 
	cell.VR_DecayRateElementalCarbon = model.componentVR.averDecayRateElementalCarbon 
	cell.VR_DecayRateBGBDecompositionUnder = model.componentVR.averDecayRateBGBDecompositionUnder 
	cell.VR_DecayRateBGBDecompositionAbove = model.componentVR.averDecayRateBGBDecompositionAbove 
	cell.VR_DecayRateDeadWoodDecomposition = model.componentVR.averDecayRateDeadWoodDecomposition 
	cell.VR_DecayRateLitterDecomposition = model.componentVR.averDecayRateLitterDecomposition 
end

-- Handles with the cell attributes inicialization.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentVR_initCellAttrNames(model)
function componentVR_initCellAttrNames(model)
	model.componentVR.attrAGBPercAGB = model.componentVR.name.."_agb1" 
	model.componentVR.attrAGBPercDecomposition = model.componentVR.name.."_agb2"
	model.componentVR.attrAGBPercInstantaneous = model.componentVR.name.."_agb3" 
	model.componentVR.attrAGBPercWoodProducts = model.componentVR.name.."_agb4" 
	
	model.componentVR.attrBGBPercBGB = model.componentVR.name.."_bgb1"
	model.componentVR.attrBGBPercDecompositionAbove = model.componentVR.name.."_bgb2"
	model.componentVR.attrBGBPercDecompositionUnder = model.componentVR.name.."_bgb3"
	model.componentVR.attrBGBPercInstantaneous	= model.componentVR.name.."_bgb4"

	model.componentVR.attrDeadWoodPercDecomposition = model.componentVR.name.."_dw1" 
	model.componentVR.attrDeadWoodPercInstantaneous = model.componentVR.name.."_dw2" 

	model.componentVR.attrLitterPercDecomposition = model.componentVR.name.."_lit1" 
	model.componentVR.attrLitterPercInstantaneous = model.componentVR.name.."_lit2" 

	model.componentVR.attrDecayRateAGBDecomposition = model.componentVR.name.."_dr1" 
	model.componentVR.attrDecayRateBGBDecompositionAbove = model.componentVR.name.."_dr2" 
	model.componentVR.attrDecayRateBGBDecompositionUnder = model.componentVR.name.."_dr3" 
	model.componentVR.attrDecayRateDeadWoodDecomposition = model.componentVR.name.."_dr4" 
	model.componentVR.attrDecayRateElementalCarbon = model.componentVR.name.."_dr5" 
	model.componentVR.attrDecayRateLitterDecomposition = model.componentVR.name.."_dr6" 
	model.componentVR.attrDecayRateWoodProducts = model.componentVR.name.."_dr7" 
	
	model.componentVR.attrDecompositionPercElementalCarbon = model.componentVR.name.."_dec1" 
	model.componentVR.attrDecompositonFireCyclePeriod = model.componentVR.name.."_dec2" 
end

-- Handles with the verify method of a Vegetation Removal component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentVR_verify(model)
function componentVR_verify(model)
	if (model.componentVR.name == nil) then
		print("Error - Missing VR parameter: name") 
		os.exit()
	end

	if (model.componentVR.description == nil) then
		print("Error - Missing VR parameter: description") 
		os.exit()
	end

	if (model.componentVR.averAGBPercAGB == nil) then
		print("Error - Missing VR parameter: averAGBPercAGB")
		os.exit()		
	end

	if (model.componentVR.averAGBPercWoodProducts == nil) then
		print("Error - Missing VR parameter: averAGBPercWoodProducts")
		os.exit()
	end 

	if (model.componentVR.averAGBPercInstantaneous == nil) then
		print("Error - Missing VR parameter: averAGBPercInstantaneous")
		os.exit()
	end	 

	if (model.componentVR.averAGBPercDecomposition == nil)	then
		print("Error - Missing VR parameter: averAGBPercDecomposition")
		os.exit()
	end 

	if (model.componentVR.averDeadWoodPercInstantaneous == nil) then
		print("Error - Missing VR parameter: averDeadWoodPercInstantaneous")
		os.exit()
	end	 

	if (model.componentVR.averDeadWoodPercDecomposition == nil)	then
		print("Error - Missing VR parameter: averDeadWoodPercDecomposition")
		os.exit()
	end 

	if (model.componentVR.averLitterPercInstantaneous == nil) then
		print("Error - Missing VR parameter: averLitterPercInstantaneous")
		os.exit()
	end	 

	if (model.componentVR.averLitterPercDecomposition == nil) then
		print("Error - Missing VR parameter: averLitterPercDecomposition")
		os.exit()
	end 

	if (model.componentVR.averBGBPercBGB == nil) then
		print("Error - Missing VR parameter: averBGBPercBGB")
		os.exit()
	end 

	if (model.componentVR.averBGBPercInstantaneous == nil) then
		print("Error - Missing VR parameter: averBGBPercInstantaneous")
		os.exit()
	end

	if (model.componentVR.averBGBPercDecompositionAbove == nil) then
		print("Error - Missing VR parameter: averBGBPercDecompositionAbove")
		os.exit()
	end

	if (model.componentVR.averBGBPercDecompositionUnder == nil) then
		print("Error - Missing VR parameter: averBGBPercDecompositionUnder")
		os.exit()
	end

	if (model.componentVR.averDecompositonPercElementalCarbon == nil) then
		print("Error - Missing VR parameter: averDecompositonPercElementalCarbon")
		os.exit()
	end

	if (model.componentVR.averDecompositionFireCyclePeriod == nil) then
		print("Error - Missing VR parameter: averDecompositionFireCyclePeriod")
		os.exit()
	end

	if (model.componentVR.averDecayRateAGBDecomposition == nil) then
		print("Error - Missing VR parameter: averDecayRateAGBDecomposition")
		os.exit()
	end

	if (model.componentVR.averDecayRateWoodProducts == nil) then
		print("Error - Missing VR parameter: averDecayRateWoodProducts")
		os.exit()
	end

	if (model.componentVR.averDecayRateElementalCarbon == nil) then
		print("Error - Missing VR parameter: averDecayRateElementalCarbon")
		os.exit()
	end

	if (model.componentVR.averDecayRateBGBDecompositionUnder == nil) then
		print("Error - Missing VR parameter: averDecayRateBGBDecompositionUnder")
		os.exit()
	end

	if (model.componentVR.averDecayRateBGBDecompositionAbove == nil) then
		print("Error - Missing VR parameter: averDecayRateBGBDecompositionAbove")
		os.exit()
	end

	if (model.componentVR.averDecayRateDeadWoodDecomposition == nil) then
		print("Error - Missing VR parameter: averDecayRateDeadWoodDecomposition")
		os.exit()
	end

	if (model.componentVR.averDecayRateLitterDecomposition == nil) then
		print("Error - Missing VR parameter: averDecayRateLitterDecomposition")
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
-- componentSV_loadFromDB(model, cell_temp, cell, y) 
function componentVR_loadFromDB(model, cell_temp, cell, y)
	y = string.sub(y, string.len(y) - 1)
	
	if (cell_temp[model.componentVR.attrAGBPercAGB..y] ~= nil) then
		cell.VR_AGBPercAGB = cell_temp[model.componentVR.attrAGBPercAGB..y]
	end

	if (cell_temp[model.componentVR.attrAGBPercWoodProducts..y] ~= nil) then
		cell.VR_AGBPercWoodProducts = cell_temp[model.componentVR.attrAGBPercWoodProducts..y]
	end

	if (cell_temp[model.componentVR.attrAGBPercInstantaneous..y] ~= nil) then
		cell.VR_AGBPercInstantaneous = cell_temp[model.componentVR.attrAGBPercInstantaneous..y]
	end

	if (cell_temp[model.componentVR.attrAGBPercDecomposition..y] ~= nil) then
		cell.VR_AGBPercDecomposition = cell_temp[model.componentVR.attrAGBPercDecomposition..y]
	end

	if (cell_temp[model.componentVR.attrBGBPercBGB..y] ~= nil) then
		cell.VR_BGBPercBGB 	= cell_temp[model.componentVR.attrBGBPercBGB..y]
	end

	if (cell_temp[model.componentVR.attrBGBPercInstantaneous..y] ~= nil) then
		cell.VR_BGBPercInstantaneous = cell_temp[model.componentVR.attrBGBPercInstantaneous..y]
	end

	if (cell_temp[model.componentVR.attrBGBPercDecompositionUnder..y] ~= nil) then
		cell.VR_BGBPercDecompositionUnder = cell_temp[model.componentVR.attrBGBPercDecompositionUnder..y]
	end

	if (cell_temp[model.componentVR.attrBGBPercDecompositionAbove..y] ~= nil) then
		cell.VR_BGBPercDecompositionAbove = cell_temp[model.componentVR.attrBGBPercDecompositionAbove..y]
	end

	if (cell_temp[model.componentVR.attrLitterPercInstantaneous..y] ~= nil) then
		cell.VR_LitterPercInstantaneous	= cell_temp[model.componentVR.attrLitterPercInstantaneous..y]
	end

	if (cell_temp[model.componentVR.attrLitterPercDecomposition..y] ~= nil) then
		cell.VR_LitterPercDecomposition = cell_temp[model.componentVR.attrLitterPercDecomposition..y]
	end

	if (cell_temp[model.componentVR.attrDeadWoodPercInstantaneous..y] ~= nil) then
		cell.VR_DeadWoodPercInstantaneous = cell_temp[model.componentVR.attrDeadWoodPercInstantaneous..y]
	end

	if (cell_temp[model.componentVR.attrDeadWoodPercDecomposition..y] ~= nil) then
		cell.VR_DeadWoodPercDecomposition = cell_temp[model.componentVR.attrDeadWoodPercDecomposition..y]
	end

	if (cell_temp[model.componentVR.attrDecompositionPercElementalCarbon..y] ~= nil) then
		cell.VR_DecompositonPercElementalCarbon = cell_temp[model.componentVR.attrDecompositionPercElementalCarbon..y]
	end

	if (cell_temp[model.componentVR.attrDecompositonFireCyclePeriod..y] ~= nil) then
		cell.VR_DecompositonFireCyclePeriod = cell_temp[model.componentVR.attrDecompositonFireCyclePeriod..y]
	end

	-- DECOMPOSITION FATE - DECAY RATES
	if (cell_temp[model.componentVR.attrDecayRateAGBDecomposition..y] ~= nil) then
		cell.VR_DecayRateAGBDecomposition = cell_temp[model.componentVR.attrDecayRateAGBDecomposition..y]
	end

	if (cell_temp[model.componentVR.attrDecayRateWoodProducts..y] ~= nil) then
		cell.VR_DecayRateWoodProducts = cell_temp[model.componentVR.attrDecayRateWoodProducts..y]
	end

	if (cell_temp[model.componentVR.attrDecayRateElementalCarbon..y] ~= nil) then
		cell.VR_DecayRateElementalCarbon = cell_temp[model.componentVR.attrDecayRateElementalCarbon..y]
	end

	if (cell_temp[model.componentVR.attrDecayRateBGBDecompositionUnder..y] ~= nil) then
		cell.VR_DecayRateBGBDecompositionUnder = cell_temp[model.componentVR.attrDecayRateBGBDecompositionUnder..y]
	end

	if (cell_temp[model.componentVR.attrDecayRateBGBDecompositionAbove..y] ~= nil) then
		cell.VR_DecayRateBGBDecompositionAbove = cell_temp[model.componentVR.attrDecayRateBGBDecompositionAbove..y]
	end

	if (cell_temp[model.componentVR.attrDecayRateDeadWoodDecomposition..y] ~= nil) then
		cell.VR_DecayRateDeadWoodDecomposition = cell_temp[model.componentVR.attrDecayRateDeadWoodDecomposition..y]
	end

	if (cell_temp[model.componentVR.attrDecayRateLitterDecomposition..y] ~= nil) then
		cell.VR_DecayRateLitterDecomposition = cell_temp[model.componentVR.attrDecayRateLitterDecomposition..y]
	end
end

-- Handles with the load of the Vegetation Removal attributes from a table (used with non-spatial model).
-- @arg model A INPE-EM Model.
-- @arg cell A cell of Cellular Space.
-- @arg step A year of the simulation.
-- @usage --DONTRUN
-- componentVR_loadFromTable(model, cell, step)
function componentVR_loadFromTable(model, cell, step)
	-- AGB
	if (model.dataTable.AGBPercAGB ~= nil) then
		if (#model.dataTable.AGBPercAGB < step) then
			print("Error - Time required exceeds the input table size: DsreaPercVegSec") 
			os.exit()
		end
		
		cell.VR_AGBPercAGB = model.dataTable.AGBPercAGB[step]
	end

	if (model.dataTable.AGBPercWoodProducts ~= nil) then
		if (#model.dataTable.AGBPercWoodProducts < step) then
			print("Error - Time required exceeds the input table size: AGBPercWoodProducts") 
			os.exit()
		end
		
		cell.VR_AGBPercWoodProducts = model.dataTable.AGBPercWoodProducts[step]
	end

	if (model.dataTable.AGBPercInstantaneous ~= nil) then
		if (#model.dataTable.AGBPercInstantaneous < step) then
			print("Error - Time required exceeds the input table size: AGBPercInstantaneous") 
			os.exit()
		end
		
		cell.VR_AGBPercInstantaneous = model.dataTable.AGBPercInstantaneous[step]
	end

	if (model.dataTable.AGBPercDecomposition ~= nil) then
		if (#model.dataTable.AGBPercDecomposition < step) then
			print("Error - Time required exceeds the input table size: AGBPercDecomposition") 
			os.exit()
		end
		
		cell.VR_AGBPercDecomposition = model.dataTable.AGBPercDecomposition[step]
	end 

	-- BGB
	if (model.dataTable.BGBPercBGB ~= nil) then
		if (#model.dataTable.BGBPercBGB < step) then
			print("Error - Time required exceeds the input table size: BGBPercBGB") 
			os.exit()
		end
		
		cell.VR_BGBPercBGB = model.dataTable.BGBPercBGB[step]
	end 

	if (model.dataTable.BGBPercInstantaneous ~= nil) then
		if (#model.dataTable.BGBPercInstantaneous < step) then
			print("Error - Time required exceeds the input table size: BGBPercInstantaneous") 
			os.exit()
		end
		
		cell.VR_BGBPercInstantaneous = model.dataTable.BGBPercInstantaneous[step]
	end 

	if (model.dataTable.BGBPercDecompositionUnder ~= nil) then
		if (#model.dataTable.BGBPercDecompositionUnder < step) then
			print("Error - Time required exceeds the input table size: BGBPercDecompositionUnder") 
			os.exit()
		end
		
		cell.VR_BGBPercDecompositionUnder = model.dataTable.BGBPercDecompositionUnder[step]
	end 

	if (model.dataTable.BGBPercDecompositionAbove ~= nil) then
		if (#model.dataTable.BGBPercDecompositionAbove < step) then
			print("Error - Time required exceeds the input table size: BGBPercDecompositionAbove") 
			os.exit()
		end
		
		cell.VR_BGBPercDecompositionAbove = model.dataTable.BGBPercDecompositionAbove[step]
	end 

	-- LITTER
	if (model.dataTable.LitterPercInstantaneous ~= nil) then
		if (#model.dataTable.LitterPercInstantaneous < step) then
			print("Error - Time required exceeds the input table size: LitterPercInstantaneous") 
			os.exit()
		end
		
		cell.VR_LitterPercInstantaneous = model.dataTable.LitterPercInstantaneous[step]
	end

	if (model.dataTable.LitterPercDecomposition ~= nil) then
		if (#model.dataTable.LitterPercDecomposition < step) then
			print("Error - Time required exceeds the input table size: LitterPercDecomposition") 
			os.exit()
		end
		
		cell.VR_LitterPercDecomposition = model.dataTable.LitterPercDecomposition[step]
	end 

	-- DEAD WOOD
	if (model.dataTable.DeadWoodPercInstantaneous ~= nil) then
		if (#model.dataTable.DeadWoodPercInstantaneous < step) then
			print("Error - Time required exceeds the input table size: DeadWoodPercInstantaneous") 
			os.exit()
		end
		
		cell.VR_DeadWoodPercInstantaneous = model.dataTable.DeadWoodPercInstantaneous[step]
	end

	if (model.dataTable.DeadWoodPercDecomposition ~= nil) then
		if (#model.dataTable.DeadWoodPercDecomposition < step) then
			print("Error - Time required exceeds the input table size: DeadWoodPercDecomposition") 
			os.exit()
		end
		
		cell.VR_DeadWoodPercDecomposition = model.dataTable.DeadWoodPercDecomposition[step]
	end 

	-- DECOMPOSITION FATE
	if (model.dataTable.DecompositionPercElementalCarbon ~= nil) then
		if (#model.dataTable.DecompositionPercElementalCarbon < step) then
			print("Error - Time required exceeds the input table size: DecompositionPercElementalCarbon") 
			os.exit()
		end
		
		cell.VR_DecompositonPercElementalCarbon = model.dataTable.DecompositionPercElementalCarbon[step]
	end 

	if (model.dataTable.DecompositonFireCyclePeriod ~= nil) then
		if (#model.dataTable.DecompositonFireCyclePeriod < step) then
			print("Error - Time required exceeds the input table size: DecompositonFireCyclePeriod") 
			os.exit()
		end
		
		cell.VR_DecompositonFireCyclePeriod = model.dataTable.DecompositonFireCyclePeriod[step]
	end 

	-- DECOMPOSITION FATE - DECAY RATES
	if (model.dataTable.DecayRateAGBDecomposition ~= nil) then
		if (#model.dataTable.DecayRateAGBDecomposition < step) then
			print("Error - Time required exceeds the input table size: DecayRateAGBDecomposition") 
			os.exit()
		end
		
		cell.VR_DecayRateAGBDecomposition = model.dataTable.DecayRateAGBDecomposition[step]
	end 

	if (model.dataTable.DecayRateWoodProducts ~= nil) then
		if (#model.dataTable.DecayRateWoodProducts < step) then
			print("Error - Time required exceeds the input table size: DecayRateWoodProducts") 
			os.exit()
		end
		
		cell.VR_DecayRateWoodProducts = model.dataTable.DecayRateWoodProducts[step]
	end 

	if (model.dataTable.DecayRateElementalCarbon ~= nil) then
		if (#model.dataTable.DecayRateElementalCarbon < step) then
			print("Error - Time required exceeds the input table size: DecayRateElementalCarbon") 
			os.exit()
		end
		
		cell.VR_DecayRateElementalCarbon = model.dataTable.DecayRateElementalCarbon[step]
	end 

	if (model.dataTable.DecayRateBGBDecompositionUnder ~= nil) then
		if (#model.dataTable.DecayRateBGBDecompositionUnder < step) then
			print("Error - Time required exceeds the input table size: DecayRateBGBDecompositionUnder") 
			os.exit()
		end
		
		cell.VR_DecayRateBGBDecompositionUnder = model.dataTable.DecayRateBGBDecompositionUnder[step]
	end 

	if (model.dataTable.DecayRateBGBDecompositionAbove ~= nil) then
		if (#model.dataTable.DecayRateBGBDecompositionAbove < step) then
			print("Error - Time required exceeds the input table size: DecayRateBGBDecompositionAbove") 
			os.exit()
		end
		
		cell.VR_DecayRateBGBDecompositionAbove = model.dataTable.DecayRateBGBDecompositionAbove[step]
	end 

	if (model.dataTable.DecayRateLitterDecomposition ~= nil) then
		if (#model.dataTable.DecayRateLitterDecomposition < step) then
			print("Error - Time required exceeds the input table size: DecayRateLitterDecomposition") 
			os.exit()
		end
		
		cell.VR_DecayRateLitterDecomposition = model.dataTable.DecayRateLitterDecomposition[step]
	end 

	if (model.dataTable.DecayRateDeadWoodDecomposition ~= nil) then
		if (#model.dataTable.DecayRateDeadWoodDecomposition < step) then
			print("Error - Time required exceeds the input table size: DecayRateDeadWoodDecomposition") 
			os.exit()
		end
		
		cell.VR_DecayRateDeadWoodDecomposition = model.dataTable.DecayRateDeadWoodDecomposition[step]
	end 
end

-- Handles with the decay calculation.
-- @arg xo Biomass value.
-- @arg k Rate.
-- @arg t Delta time.
-- @arg E exponential constant time.
-- @usage --DONTRUN
-- compute_exp(biomass,(-1) * rate, y - year, E)
function compute_exp(xo, k, t, E)
	local x = xo * E ^ (k * t)

	return x
end