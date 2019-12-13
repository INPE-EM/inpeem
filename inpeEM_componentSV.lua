-- Handles with the Secondary Vegetation component execution.
-- @arg year A year for simulation.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentSV_execute(year, model)
function componentSV_execute(year, model)
	if (model.verbose) then
		print(year.."\tExecuting SV - mode:"..model.mode) 
	end

	local flagPrintAreaPercVegSec = true 	
	local flagPrintAreaAccPercVegSec = true
	local flagPrintHalfLife = true 		

	-- declare cell attributes for the current year
	local cs = model.cs 
	local attrInitialArea = model.componentSV.attrInitialArea..year
	local attrInitialRateAccBiomassPeriod1 = model.componentSV.attrInitialRateAccBiomassPeriod1..year
	local attrInitialRateAccBiomassPeriod2 = model.componentSV.attrInitialRateAccBiomassPeriod2..year 
	local attrRateRegrowth = model.componentSV.attrRateRegrowth..year
	local attrAreaRegrowth = model.componentSV.attrAreaRegrowth..year
	local attrBiomassRegrowth = model.componentSV.attrBiomassRegrowth..year
	local regrowArea = 0
	local regrowAreaBiomass = 0
	local period1AccBiomass = 0
	local period1RateAccBiomass = 0
	local period2AccBiomass = 0
	local period2RateAccBiomass = 0
	local areaSF = 0

	for i, cell in pairs (model.cs.cells) do
		-- STEP 1: compute how much secondary vegetation starts to grow following after current year's PF and SF deforestation 
		regrowArea = cell.SV_AreaPercVegSec * cell.D_Area + cell.relAreaCleared * cell.SV_AreaPercVegSec + cell.SV_AreaAccPercVegSec * cell.D_AreaAcc
		regrowAreaBiomass = regrowArea * cell.B_AGB + regrowArea * cell.B_AGB * cell.B_BGBPercAGB 
		period1AccBiomass = regrowAreaBiomass * cell.SV_RecoveryPeriod1Perc
		period1RateAccBiomass = period1AccBiomass / cell.SV_RecoveryPeriod1
		period2AccBiomass = regrowAreaBiomass * cell.SV_RecoveryPeriod2Perc
		period2RateAccBiomass = period2AccBiomass / cell.SV_RecoveryPeriod2

		-- STEP 2: initialize cell variables for dynamic updates
		cell[attrInitialRateAccBiomassPeriod1] = period1RateAccBiomass
		cell[attrInitialRateAccBiomassPeriod2] = period2RateAccBiomass
		cell[attrInitialArea] = regrowArea
		cell[attrAreaRegrowth] = cell[attrInitialArea] 
		cell[attrRateRegrowth] = cell[attrInitialRateAccBiomassPeriod1]
		cell[attrBiomassRegrowth] = 0 
		
		cell.areaCleared = 0
		cell.relAreaCleared = 0
		cell.biomassLost = 0
		cell.areaTotal = 0
		cell.areaGrowing = 0
		cell.biomassAcc = 0	 

		componentSV_computePastRegrow(cell, year, model)

		areaSF = 0

		if (model.mode == "spatial") then
			if (year == model.yearInit) then 
				cell.initialArea = cell.D_AreaAcc * cell.SV_AreaPercVegSec 
				areaSF = cell.initialArea 
			else
				areaSF = cell.initialArea + cell.areaTotal 
			end
		else
			areaSF = cell.areaTotal 
		end

		if (cell.D_AreaAcc < areaSF) then 
			areaSF = cell.D_AreaAcc
		end

		if (model.save == true) then
			cell[model.componentSV.attrOutAreaVS..year] = areaSF
			cell[model.componentSV.attrOutAreaAGR..year] = cell.D_AreaAcc - areaSF
			cell[model.componentSV.attrCO2..year] = cell.biomassLost * cell.B_FactorB_CO2Fire / 1000000
			cell[model.componentSV.attrCO2In..year] = cell.biomassAcc * cell.B_FactorB_CO2 / 1000000
		end

		model.SV_Result[year].SV_AreaTotal = model.SV_Result[year].SV_AreaTotal + areaSF
		model.SV_Result[year].SV_AreaCleared = model.SV_Result[year].SV_AreaCleared + cell.areaCleared
		model.SV_Result[year].SV_CO2Emission = model.SV_Result[year].SV_CO2Emission + cell.biomassLost * cell.B_FactorB_CO2Fire 
		model.SV_Result[year].SV_CO2Absorption = model.SV_Result[year].SV_CO2Absorption + cell.biomassAcc * cell.B_FactorB_CO2 
	end
end

-- Handles with the calculation of the Past Regrow.
-- @arg cell A cell of a Cellular Space.
-- @arg year A year for simulation.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- function componentSV_computePastRegrow(cell, year, model)
function componentSV_computePastRegrow(cell, year, model)
	local halfLife = {}
	local attrAreaRegrowth = 0

	for k = model.yearInit, year do
		halfLife[k] = cell.SV_HalfLife
	end 

	for k = year - cell.SV_AgriculturalUseCycle - cell.SV_InitialAbandonmentCycle, year - 1, 1 do
		halfLife[k] = 100000
	end 

	for y = year - cell.SV_AgriculturalUseCycle, year, 1 do
		if (y >= model.yearInit) then
			attrAreaRegrowth = model.componentSV.attrAreaRegrowth..y
			cell.areaTotal = cell.areaTotal + cell[attrAreaRegrowth] 
		end
	end
	
	local attrInitialArea = 0
	local attr_initial_rate_regrowth_period2 = 0
	local attrRateRegrowth = 0
	local attrBiomassRegrowth	= 0
	
	local areaCleared = 0
	local biomassLost = 0
	local percCleared = 0 
	local percRemainingPerid1 = 1
		
	for y = model.yearInit , year - cell.SV_AgriculturalUseCycle - 1, 1 do
		attrInitialArea = model.componentSV.attrInitialArea..y
		attr_initial_rate_regrowth_period2 = model.componentSV.attrInitialRateAccBiomassPeriod2..y 
		attrRateRegrowth = model.componentSV.attrRateRegrowth..y
		attrAreaRegrowth = model.componentSV.attrAreaRegrowth..y
		attrBiomassRegrowth = model.componentSV.attrBiomassRegrowth..y

		cell.biomassAcc = cell.biomassAcc + cell[attrRateRegrowth]
		cell.areaTotal = cell.areaTotal + cell[attrAreaRegrowth] 
		cell.areaGrowing = cell.areaGrowing + cell[attrAreaRegrowth] 

		cell[attrBiomassRegrowth] = cell[attrBiomassRegrowth] + cell[attrRateRegrowth]

		if (cell[attrAreaRegrowth] > 0) then
			areaCleared = computeAreaExpDecay(model.E, cell[attrInitialArea], halfLife[y], year - y - cell.SV_AgriculturalUseCycle - cell.SV_InitialAbandonmentCycle)
			percCleared = areaCleared / cell[attrAreaRegrowth]
			biomassLost = cell[attrBiomassRegrowth] * percCleared
		else 
			cell[attrAreaRegrowth] = 0 
		end

		cell[attrAreaRegrowth] = cell[attrAreaRegrowth] - areaCleared
		cell[attrRateRegrowth] = cell[attrRateRegrowth] * (1 - percCleared) 
		cell[attrBiomassRegrowth] = cell[attrBiomassRegrowth] - biomassLost

		cell.biomassLost = cell.biomassLost + biomassLost
		cell.areaCleared = cell.areaCleared + areaCleared 

		if (cell.SV_AreaPercVegSec ~= 0) then
			cell.relAreaCleared = cell.relAreaCleared + areaCleared / cell.SV_AreaPercVegSec
		else
			if (cell.SV_AreaAccPercVegSec ~= 0) then
				cell.relAreaCleared = cell.relAreaCleared + areaCleared / cell.SV_AreaAccPercVegSec
			end
		end
		
		if (y == model.yearInit + cell.SV_RecoveryPeriod1) then
			percRemainingPerid1 = 1

			if (cell[attrInitialArea] > 0) then
				percRemainingPerid1 = cell[attrAreaRegrowth] / cell[attrInitialArea]
			end

			cell[attrRateRegrowth] = cell[attr_initial_rate_regrowth_period2] * percRemainingPerid1
		end
	end
end


-- Handles with the creation of a null Secondary Vegetation component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentSV_createNullComponent(model)
function componentSV_createNullComponent(model)
	if (model ~= nil)then
		model.componentSV = {
			name = "undefined",
			description = "",
			
			averAreaPercVegSec = 0,
			averAreaAccPercVegSec = 0,
			averAgriculturalUseCycle = 0,

			averRecoveryPeriod1Perc = 0,
			averRecoveryPeriod1 = 0, 
			averRecoveryPeriod2Perc = 0, 
			averRecoveryPeriod2 = 0, 

			averInitialAbandonmentCycle = 0,
			averHalfLife = 0,
		}
	end
end

-- Handles with the initialization method of a Secondary Vegetation component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentSV_init(model)
function componentSV_init(model)
	model.componentSV.saveAttrs = {}
	model.componentSV.saveCount = 0
	model.componentSV.attrOutAreaVS = "OutAVS"
	model.componentSV.attrOutAreaAGR = "OutAGR"
	
	model.componentSV.attrCO2 = "sCO2_" 
	model.componentSV.attrCO2In = "sICO2_" 

	if (model.save == true) then 
		for year = model.yearInit, model.yearFinal, 1 do 
			model.componentSV.saveCount = model.componentSV.saveCount + 1
			model.componentSV.saveAttrs[model.componentSV.saveCount] = model.componentSV.attrOutAreaVS..year
			model.componentSV.saveCount = model.componentSV.saveCount + 1
			model.componentSV.saveAttrs[model.componentSV.saveCount] = model.componentSV.attrOutAreaAGR..year
			model.componentSV.saveCount = model.componentSV.saveCount + 1
			model.componentSV.saveAttrs[model.componentSV.saveCount] = model.componentSV.attrCO2..year 
			model.componentSV.saveCount = model.componentSV.saveCount + 1
			model.componentSV.saveAttrs[model.componentSV.saveCount] = model.componentSV.attrCO2In..year 
		end
	end	 

	-- init (runtime) past cell attribute names
	model.componentSV.attrInitialArea = model.componentSV.name.."initialArea_regrow_"
	model.componentSV.attrInitialRateAccBiomassPeriod1 = model.componentSV.name.."rate_regrow_period1_"
	model.componentSV.attrInitialRateAccBiomassPeriod2 = model.componentSV.name.."rate_regrow_period2_" 
	model.componentSV.attrRateRegrowth = model.componentSV.name.."rate_regrow_"
	model.componentSV.attrAreaRegrowth = model.componentSV.name.."area_regrow_"
	model.componentSV.attrBiomassRegrowth = model.componentSV.name.."biomass_regrow_"

	forEachCell(model.cs, function(cell)
							cell.areaCleared = 0
							cell.relAreaCleared = 0
							cell.biomassLost = 0
							cell.areaTotal = 0
							cell.areaGrowing = 0
							cell.biomassAcc = 0	
							componentSV_initCellAverComponentValues(cell, model)
						   end
			   )

   componentSV_initCellAttrNames(model)
end

-- Handles with the cell attributes inicialization.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentSV_initCellAttrNames(model)
function componentSV_initCellAttrNames(model)
	model.componentSV.attrAreaAccPercVegSec = model.componentSV.name.."_aapvs"
	model.componentSV.attrAgriculturalUseCycle = model.componentSV.name.."_auc"
	model.componentSV.attrAreaPercVegSec = model.componentSV.name.."_apvs"
	model.componentSV.attrHalfLife = model.componentSV.name.."_hl"
	model.componentSV.attrInitialAbandonmentCycle = model.componentSV.name.."_iac"
	model.componentSV.attrRecoveryPeriod1 = model.componentSV.name.."_rp1"
	model.componentSV.attrRecoveryPeriod1Perc = model.componentSV.name.."_rp1p"
	model.componentSV.attrRecoveryPeriod2 = model.componentSV.name.."_rp2"
	model.componentSV.attrRecoveryPeriod2Perc = model.componentSV.name.."_rp2p"
end	

-- Handles with the initialization of the cell with average values.
-- @arg cell A cell of a Cellular Space.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentSV_initCellAverComponentValues(cell, model)
function componentSV_initCellAverComponentValues(cell, model)
	cell.SV_AreaPercVegSec = model.componentSV.averAreaPercVegSec
	cell.SV_AreaAccPercVegSec = model.componentSV.averAreaAccPercVegSec
	cell.SV_AgriculturalUseCycle = model.componentSV.averAgriculturalUseCycle
	cell.SV_RecoveryPeriod1Perc = model.componentSV.averRecoveryPeriod1Perc
	cell.SV_RecoveryPeriod1 = model.componentSV.averRecoveryPeriod1
	cell.SV_RecoveryPeriod2Perc = model.componentSV.averRecoveryPeriod2Perc
	cell.SV_RecoveryPeriod2 = model.componentSV.averRecoveryPeriod2
	cell.SV_InitialAbandonmentCycle = model.componentSV.averInitialAbandonmentCycle
	cell.SV_HalfLife = model.componentSV.averHalfLife
end

-- Handles with the verify method of a DEGRAD component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentSV_verify(model)
function componentSV_verify(model)
	if (model.componentSV.name == nil) then
		print("Error - Missing SV parameter: name")
		os.exit()		
	end

	if (model.componentSV.description == nil) then
		print("Error - Missing SV parameter: description")
		os.exit()
	end

	if (model.componentSV.averAreaPercVegSec == nil) then
		print("Error - Missing SV parameter: averAreaPercVegSec")
		os.exit()
	end

	if (model.componentSV.averAreaAccPercVegSec == nil) then
		print("Error - Missing SV parameter: averAreaAccPercVegSec")
		os.exit()
	end

	if (model.componentSV.averAgriculturalUseCycle == nil) then
		print("Error - Missing SV parameter: averAgriculturalUseCycle") 
		os.exit()
	end

	if (model.componentSV.averRecoveryPeriod1Perc == nil) then
		print("Error - Missing SV parameter: averRecoveryPeriod1Perc") 
		os.exit()
	end

	if (model.componentSV.averRecoveryPeriod1 == nil) then
		print("Error - Missing SV parameter: averRecoveryPeriod1") 
		os.exit()
	end

	if (model.componentSV.averRecoveryPeriod2Perc == nil) then
		print("Error - Missing SV parameter: averRecoveryPeriod2Perc") 
		os.exit()
	end

	if (model.componentSV.averRecoveryPeriod2 == nil) then
		print("Error - Missing SV parameter: averRecoveryPeriod2") 
		os.exit()
	end

	if (model.componentSV.averInitialAbandonmentCycle == nil) then
		print("Error - Missing SV parameter: averInitialAbandonmentCycle") 
		os.exit()
	end

	if (model.componentSV.averHalfLife == nil) then
		print("Error - Missing SV parameter: averHalfLife") 
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
function componentSV_loadFromDB(model, cell_temp, cell, y)
	y = string.sub(y, string.len(y) - 1)
	
	if (cell_temp[model.componentSV.attrAreaPercVegSec..y] ~= nil) then
		cell.SV_AreaPercVegSec 	= cell_temp[model.componentSV.attrAreaPercVegSec..y]
		
		if (flagPrintAreaPercVegSec) then 
			print(y.." \tLoading "..model.componentSV.attrAreaPercVegSec..y) 
			flagPrintAreaPercVegSec = false 
		end
	end

	if (cell_temp[model.componentSV.attrAreaAccPercVegSec..y] ~= nil) then
		cell.SV_AreaAccPercVegSec = cell_temp[model.componentSV.attrAreaAccPercVegSec..y]
		
		if (flagPrintAreaAccPercVegSec) then 
			print(y.." \tLoading "..model.componentSV.attrAreaAccPercVegSec..y) 
			flagPrintAreaAccPercVegSec = false 
		end
	end

	if (cell_temp[model.componentSV.attrAgriculturalUseCycle..y] ~= nil) then
		cell.SV_AgriculturalUseCycle = cell_temp[model.componentSV.attrAgriculturalUseCycle..y]
	end

	if (cell_temp[model.componentSV.attrRecoveryPeriod1Perc..y] ~= nil) then
		cell.SV_RecoveryPeriod1Perc = cell_temp[model.componentSV.attrRecoveryPeriod1Perc..y]
	end

	if (cell_temp[model.componentSV.attrRecoveryPeriod1..y] ~= nil) then
		cell.SV_RecoveryPeriod1 = cell_temp[model.componentSV.attrRecoveryPeriod1..y]
	end

	if (cell_temp[model.componentSV.attrRecoveryPeriod2Perc..y] ~= nil) then
		cell.SV_RecoveryPeriod2Perc = cell_temp[model.componentSV.attrRecoveryPeriod2Perc..y]
	end

	if (cell_temp[model.componentSV.attrRecoveryPeriod2..y] ~= nil) then
		cell.SV_RecoveryPeriod2 = cell_temp[model.componentSV.attrRecoveryPeriod2..y]
	end

	if (cell_temp[model.componentSV.attrInitialAbandonmentCycle..y] ~= nil) then
		cell.SV_InitialAbandonmentCycle = cell_temp[model.componentSV.attrInitialAbandonmentCycle..y]
	end

	if (cell_temp[model.componentSV.attrHalfLife..y] ~= nil) then
		cell.SV_HalfLife = cell_temp[model.componentSV.attrHalfLife..y]
		
		if (flagPrintHalfLife) then 
			print(y.." \tLoading "..model.componentSV.attrHalfLife) 
			flagPrintHalfLife = false 
		end
	end
end

-- Handles with the load of the attributes from a table (used with non-spatial model).
-- @arg model A INPE-EM Model.
-- @arg cell A cell of a Cellular Space.
-- @arg step A number of the simulation step.
-- @usage --DONTRUN
-- componentSV_loadFromTable(model, cell, step)
function componentSV_loadFromTable(model, cell, step)
	if (model.dataTable.AreaPercVegSec ~= nil) then
		if (#model.dataTable.AreaPercVegSec < step) then
			print("Error - Time required exceeds the input table size: AreaPercVegSec") 
			os.exit()
		end
		
		cell.SV_AreaPercVegSec = model.dataTable.AreaPercVegSec[step]
	end

	if (model.dataTable.AreaAccPercVegSec ~= nil) then
		if (#model.dataTable.AreaAccPercVegSec < step) then
			print("Error - Time required exceeds the input table size: AreaAccPercVegSec", 2) 
			os.exit()
		end
		
		cell.SV_AreaAccPercVegSec = model.dataTable.AreaAccPercVegSec[step]
	end

	if (model.dataTable.AgriculturalUseCycle ~= nil) then
		if (#model.dataTable.AgriculturalUseCycle < step) then
			print("Error - Time required exceeds the input table size: AgriculturalUseCycle", 2) 
			os.exit()
		end
		
		cell.SV_AgriculturalUseCycle = model.dataTable.AgriculturalUseCycle[step]
	end

	if (model.dataTable.RecoveryPeriod1Perc ~= nil) then
		if (#model.dataTable.RecoveryPeriod1Perc < step) then
			print("Error - Time required exceeds the input table size: RecoveryPeriod1Perc", 2) 
			os.exit()
		end
		
		cell.SV_RecoveryPeriod1Perc = model.dataTable.RecoveryPeriod1Perc[step]
	end

	if (model.dataTable.RecoveryPeriod1 ~= nil) then
		if (#model.dataTable.RecoveryPeriod1 < step) then
			print("Error - Time required exceeds the input table size: RecoveryPeriod1", 2) 
			os.exit()
		end
		
		cell.SV_RecoveryPeriod1 = model.dataTable.RecoveryPeriod1[step]
	end

	if (model.dataTable.RecoveryPeriod2Perc ~= nil) then
		if (#model.dataTable.RecoveryPeriod2Perc < step) then
			print("Error - Time required exceeds the input table size: RecoveryPeriod2Perc", 2) 
			os.exit()
		end
		
		cell.SV_RecoveryPeriod2Perc = model.dataTable.RecoveryPeriod2Perc[step]
	end

	if (model.dataTable.RecoveryPeriod2 ~= nil) then
		if (#model.dataTable.RecoveryPeriod2 < step) then
			print("Error - Time required exceeds the input table size: RecoveryPeriod2", 2) 
			os.exit()
		end
		
		cell.SV_RecoveryPeriod2 = model.dataTable.RecoveryPeriod2[step]
	end

	if (model.dataTable.InitialAbandonmentCycle ~= nil) then
		if (#model.dataTable.InitialAbandonmentCycle < step) then
			print("Error - Time required exceeds the input table size: InitialAbandonmentCycle", 2) 
			os.exit()
		end
		
		cell.SV_InitialAbandonmentCycle = model.dataTable.InitialAbandonmentCycle[step]
	end

	if (model.dataTable.HalfLife ~= nil) then
		if (#model.dataTable.HalfLife < step) then
			print("Error - Time required exceeds the input table size: HalfLife", 2) 
			os.exit()
		end
		
		cell.SV_HalfLife = model.dataTable.HalfLife[step]
	end
end

-- Handles with the area cleared calculation.
-- @arg area_init Initial area.
-- @arg halfLife Half Life time.
-- @arg t_final Delta time.
-- @usage --DONTRUN
-- computeAreaExpDecay(model.E, cell[attrInitialArea], halfLife[y], year - y - cell.SV_AgriculturalUseCycle - cell.SV_InitialAbandonmentCycle)
function computeAreaExpDecay(E, area_init, halfLife, t_final)
	local prev = area_init
	local diff = 0

	if (halfLife > 0 and area_init > 0 and t_final >= 0) then
		k = (math.log(50) - math.log(100)) / halfLife
		for t = 1, t_final, 1 do
			x = area_init * E ^ (k * t)
			diff = prev - x
			prev = prev - diff
		end
	end
	
	return diff
end
