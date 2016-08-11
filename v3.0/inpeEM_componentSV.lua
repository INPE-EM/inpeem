local E = 2.718

-- Handles with the Secondary Vegetation component execution.
-- @arg year A year for simulation.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentSV_execute(year, model)
function componentSV_execute(year, model)
	if (model.verbose) then
		print(year, "Executing SV - mode:"..model.mode) 
	end

	flagPrintAreaPercVegSec = true 	
	flagPrintAreaAccPercVegSec = true
	flagPrintHalfLife = true 		

	-- declare cell attributes for the current year
	local cs = model.cs 
	local attr_initial_area = model.componentSV.attr_initial_area..year
	local attr_initial_rate_acc_biomass_period1	= model.componentSV.attr_initial_rate_acc_biomass_period1..year
	local attr_initial_rate_acc_biomass_period2	= model.componentSV.attr_initial_rate_acc_biomass_period2..year 
	local attr_rate_regrowth = model.componentSV.attr_rate_regrowth..year
	local attr_area_regrowth = model.componentSV.attr_area_regrowth..year
	local attr_biomass_regrowth	= model.componentSV.attr_biomass_regrowth..year

	for i, cell in pairs( model.cs.cells) do
		--------- STEP 1: compute how much secondary vegetation starts to grow following after current year's PF and SF deforestation 
		local regrow_area = cell.SV_AreaPercVegSec * cell.D_Area + cell.rel_area_cleared * cell.SV_AreaPercVegSec + cell.SV_AreaAccPercVegSec * cell.D_AreaAcc
		local regrow_area_biomass = regrow_area * cell.B_AGB + regrow_area * cell.B_AGB * cell.B_BGBPercAGB 
		local period1_acc_biomass = regrow_area_biomass * cell.SV_RecoveryPeriod1Perc
		local period1_rate_acc_biomass = period1_acc_biomass / cell.SV_RecoveryPeriod1
		local period2_acc_biomass = regrow_area_biomass * cell.SV_RecoveryPeriod2Perc
		local period2_rate_acc_biomass = period2_acc_biomass / cell.SV_RecoveryPeriod2

		--------- STEP 2: initialize cell variables for dynamic updates
		cell[attr_initial_rate_acc_biomass_period1] = period1_rate_acc_biomass
		cell[attr_initial_rate_acc_biomass_period2] = period2_rate_acc_biomass
		cell[attr_initial_area] = regrow_area
		cell[attr_area_regrowth] = cell[attr_initial_area] 
		cell[attr_rate_regrowth] = cell[attr_initial_rate_acc_biomass_period1]
		cell[attr_biomass_regrowth] = 0 
		cell.area_cleared = 0
		cell.rel_area_cleared = 0
		cell.biomass_lost = 0
		cell.area_total = 0
		cell.area_growing = 0
		cell.biomass_acc = 0	 

		componentSV_computePastRegrow(cell, year, model)

		local area_sf = 0

		if (model.mode == "spatial") then
			if (year == model.yearInit) then 
				cell.initial_area = cell.D_AreaAcc * cell.SV_AreaPercVegSec 
				area_sf = cell.initial_area 
			else
				area_sf = cell.initial_area + cell.area_total 
			end
		else
			area_sf = cell.area_total 
		end

		if (cell.D_AreaAcc < area_sf) then 
			area_sf = cell.D_AreaAcc
		end

		if (model.save == true) then
			cell[model.componentSV.attrOutAreaVS..year] = area_sf
			cell[model.componentSV.attrOutAreaAGR..year] = cell.D_AreaAcc - area_sf
		end

		model.SV_result[year].SV_area_total = model.SV_result[year].SV_area_total + area_sf
		model.SV_result[year].SV_area_cleared = model.SV_result[year].SV_area_cleared + cell.area_cleared
		model.SV_result[year].SV_CO2_emission = model.SV_result[year].SV_CO2_emission + cell.biomass_lost * cell.B_FactorB_CO2_fire 
		model.SV_result[year].SV_CO2_absorption = model.SV_result[year].SV_CO2_absorption + cell.biomass_acc * cell.B_FactorB_CO2 
	end
end

-- Handles with the calculation of the Past Regrow.
-- @arg cell A cell of a Cellular Space.
-- @arg year A year for simulation.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- function componentSV_computePastRegrow(cell, year, model)
function componentSV_computePastRegrow(cell, year, model)
	local halfLife ={}

	for k = model.yearInit, year do
		halfLife[k] = cell.SV_HalfLife
	end 

	for k = year - cell.SV_AgriculturalUseCycle - cell.SV_InitialAbandonmentCycle, year - 1, 1 do
		halfLife[k] = 100000
		
		if (k >= model.yearInit) then
			local attr_rate_regrowth = model.componentSV.attr_rate_regrowth..k; --XXXXXXXXXXXXXXXXXXXXXXX
		end
	end 

	for y = year - cell.SV_AgriculturalUseCycle, year, 1 do
		if (y >= model.yearInit) then
			local attr_area_regrowth = model.componentSV.attr_area_regrowth..y
			cell.area_total = cell.area_total + cell[attr_area_regrowth] 
		end
	end

	for y = model.yearInit , year - cell.SV_AgriculturalUseCycle - 1, 1 do
		local attr_initial_area = model.componentSV.attr_initial_area..y
		local attr_initial_rate_regrowth_period2 = model.componentSV.attr_initial_rate_acc_biomass_period2..y 
		local attr_rate_regrowth = model.componentSV.attr_rate_regrowth..y
		local attr_area_regrowth = model.componentSV.attr_area_regrowth..y
		local attr_biomass_regrowth	= model.componentSV.attr_biomass_regrowth..y

		cell.biomass_acc = cell.biomass_acc + cell[attr_rate_regrowth]
		cell.area_total = cell.area_total + cell[attr_area_regrowth] 
		cell.area_growing = cell.area_growing + cell[attr_area_regrowth] 

		cell[attr_biomass_regrowth] = cell[attr_biomass_regrowth] + cell[attr_rate_regrowth]

		local area_cleared = 0
		local biomass_lost = 0
		local perc_cleared = 0 

		if (cell[attr_area_regrowth] > 0) then
			area_cleared = computeAreaExpDecay(cell[attr_initial_area], halfLife[y], year - y - cell.SV_AgriculturalUseCycle - cell.SV_InitialAbandonmentCycle)
			perc_cleared = area_cleared / cell[attr_area_regrowth]
			biomass_lost = cell[attr_biomass_regrowth] * perc_cleared
		else 
			cell[attr_area_regrowth] = 0 
		end

		cell[attr_area_regrowth] = cell[attr_area_regrowth] - area_cleared
		cell[attr_rate_regrowth] = cell[attr_rate_regrowth] * (1 - perc_cleared) 
		cell[attr_biomass_regrowth] = cell[attr_biomass_regrowth] - biomass_lost

		cell.biomass_lost = cell.biomass_lost + biomass_lost
		cell.area_cleared = cell.area_cleared + area_cleared 

		if (cell.SV_AreaPercVegSec ~= 0) then
			cell.rel_area_cleared = cell.rel_area_cleared + area_cleared / cell.SV_AreaPercVegSec
		else
			if (cell.SV_AreaPercVegSec ~= 0) then
				cell.rel_area_cleared = cell.rel_area_cleared + area_cleared / cell.SV_AreaPercVegSec
			end
		end

		if (y == model.yearInit + cell.SV_RecoveryPeriod1) then
			local perc_remaining_perid1 = 1

			if (cell[attr_initial_area] > 0) then
				perc_remaining_perid1 = cell[attr_area_regrowth] / cell[attr_initial_area]
			end

			cell[attr_rate_regrowth] = cell[attr_initial_rate_regrowth_period2] * perc_remaining_perid1
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
			averBGBpercBGB = 0
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
	model.componentSV.attrOutAreaVS = model.componentSV.name.."_OutAreaVS"
	model.componentSV.attrOutAreaAGR = model.componentSV.name.."_OutAreaAGR"

	if (model.save == true) then 
		for year= model.yearInit, model.yearFinal, 1 do 
			model.componentSV.saveCount = model.componentSV.saveCount + 1
			model.componentSV.saveAttrs[model.componentSV.saveCount] = model.componentSV.attrOutAreaVS..year
			model.componentSV.saveCount = model.componentSV.saveCount + 1
			model.componentSV.saveAttrs[model.componentSV.saveCount] = model.componentSV.attrOutAreaAGR..year
		end
	end	 

	model.componentSV.attr_initial_area = model.componentSV.name.."initial_area_regrow_"
	model.componentSV.attr_initial_rate_acc_biomass_period1 = model.componentSV.name.."rate_regrow_period1_"
	model.componentSV.attr_initial_rate_acc_biomass_period2 = model.componentSV.name.."rate_regrow_period2_" 
	model.componentSV.attr_rate_regrowth = model.componentSV.name.."rate_regrow_"
	model.componentSV.attr_area_regrowth = model.componentSV.name.."area_regrow_"
	model.componentSV.attr_biomass_regrowth = model.componentSV.name.."biomass_regrow_"

	forEachCell(model.cs, function(cell)
							cell.area_cleared = 0
							cell.rel_area_cleared = 0
							cell.biomass_lost = 0
							cell.area_total = 0
							cell.area_growing = 0
							cell.biomass_acc = 0	
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
	model.componentSV.attrAreaPercVegSec = model.componentSV.name.."_AreaPercVegSec"
	model.componentSV.attrAreaAccPercVegSec = model.componentSV.name.."_AreaAccPercVegSec"
	model.componentSV.attrAgriculturalUseCycle = model.componentSV.name.."_AgriculturalUseCycle"
	model.componentSV.attrRecoveryPeriod1Perc = model.componentSV.name.."_RecoveryPeriod1Perc"
	model.componentSV.attrRecoveryPeriod1 = model.componentSV.name.."_RecoveryPeriod1"
	model.componentSV.attrRecoveryPeriod2Perc = model.componentSV.name.."_RecoveryPeriod2Perc"
	model.componentSV.attrRecoveryPeriod2 = model.componentSV.name.."_RecoveryPeriod2"
	model.componentSV.attrInitialAbandonmentCycle = model.componentSV.name.."_InitialAbandonmentCycle"
	model.componentSV.attrHalfLife = model.componentSV.name.."_HalfLife"
	model.componentSV.attrBGBpercBGB = model.componentSV.name.."_BGBpercBGB"
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
	cell.SV_BGBpercBGB = model.componentSV.averBGBpercBGB
end

-- Handles with the verify method of a DEGRAD component.
-- @arg model A INPE-EM Model.
-- @usage --DONTRUN
-- componentSV_verify(model)
function componentSV_verify(model)
	if (model.componentSV.name == nil) then
		error("Missing SV parameter: name", 2) 
	end

	if (model.componentSV.description == nil) then
		error("Missing SV parameter: description", 2) 
	end

	if (model.componentSV.averAreaPercVegSec == nil) then
		error("Missing SV parameter: averAreaPercVegSec", 2) 
	end

	if (model.componentSV.averAreaAccPercVegSec == nil) then
		error("Missing SV parameter: averAreaAccPercVegSec", 2) 
	end

	if (model.componentSV.averAgriculturalUseCycle == nil) then
		error("Missing SV parameter: averAgriculturalUseCycle", 2) 
	end

	if (model.componentSV.averRecoveryPeriod1Perc == nil) then
		error("Missing SV parameter: averRecoveryPeriod1Perc", 2) 
	end

	if (model.componentSV.averRecoveryPeriod1 == nil) then
		error("Missing SV parameter: averRecoveryPeriod1", 2) 
	end

	if (model.componentSV.averRecoveryPeriod2Perc == nil) then
		error("Missing SV parameter: averRecoveryPeriod2Perc", 2) 
	end

	if (model.componentSV.averRecoveryPeriod2 == nil) then
		error("Missing SV parameter: averRecoveryPeriod2", 2) 
	end

	if (model.componentSV.averInitialAbandonmentCycle == nil) then
		error("Missing SV parameter: averInitialAbandonmentCycle", 2) 
	end

	if (model.componentSV.averHalfLife == nil) then
		error("Missing SV parameter: averHalfLife", 2) 
	end

	if (model.componentSV.averBGBpercBGB == nil) then
		error("Missing SV parameter: averBGBpercBGB", 2) 
	end

	return true
end

-- Handles with the load of the attributes from the database or shape.
-- @arg model A INPE-EM Model.
-- @arg cell_temp XXXXXXXXXXXXXXXXXXXXXXX
-- @arg cell XXXXXXXXXXXXXXXXXXXXXXX
-- @arg y XXXXXXXXXXXXXXXXXXXXXXX
-- @usage --DONTRUN
-- componentSV_loadFromDB(model, cell_temp, cell, y)
function componentSV_loadFromDB(model, cell_temp, cell, y)
	if (cell_temp[model.componentSV.attrAreaPercVegSec..y] ~= nil) then
		cell.SV_AreaPercVegSec 	= cell_temp[model.componentSV.attrAreaPercVegSec..y]
		
		if (flagPrintAreaPercVegSec) then 
			print(y, "Loading "..model.componentSV.attrAreaPercVegSec..y) 
			flagPrintAreaPercVegSec = false 
		end
	end

	if (cell_temp[model.componentSV.attrAreaAccPercVegSec..y] ~= nil) then
		cell.SV_AreaAccPercVegSec = cell_temp[model.componentSV.attrAreaAccPercVegSec..y]
		
		if (flagPrintAreaAccPercVegSec) then 
			print(y, "Loading "..model.componentSV.attrAreaAccPercVegSec..y) 
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
		cell.SV_HalfLife 	= cell_temp[model.componentSV.attrHalfLife..y]
		
		if (flagPrintHalfLife) then 
			print(y,"Loading "..model.componentSV.attrHalfLife) 
			flagPrintHalfLife = false 
		end
	end

	if (cell_temp[model.componentSV.attrBGBpercBGB..y] ~= nil)then
		cell.SV_BGBpercBGB 	= cell_temp[model.componentSV.attrBGBpercBGB..y]
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
			error("Time required exceeds the input table size: AreaPercVegSec", 2) 
		end
		
		cell.SV_AreaPercVegSec = model.dataTable.AreaPercVegSec[step]
	end

	if (model.dataTable.AreaAccPercVegSec ~= nil) then
		if (#model.dataTable.AreaAccPercVegSec < step) then
			error("Time required exceeds the input table size: AreaAccPercVegSec", 2) 
		end
		
		cell.SV_AreaAccPercVegSec = model.dataTable.AreaAccPercVegSec[step]
	end

	if (model.dataTable.AgriculturalUseCycle ~= nil) then
		if (#model.dataTable.AgriculturalUseCycle < step) then
			error("Time required exceeds the input table size: AgriculturalUseCycle", 2) 
		end
		
		cell.SV_AgriculturalUseCycle = model.dataTable.AgriculturalUseCycle[step]
	end

	if (model.dataTable.RecoveryPeriod1Perc ~= nil) then
		if (#model.dataTable.RecoveryPeriod1Perc < step) then
			error("Time required exceeds the input table size: RecoveryPeriod1Perc", 2) 
		end
		
		cell.SV_RecoveryPeriod1Perc = model.dataTable.RecoveryPeriod1Perc[step]
	end

	if (model.dataTable.RecoveryPeriod1 ~= nil) then
		if (#model.dataTable.RecoveryPeriod1 < step) then
			error("Time required exceeds the input table size: RecoveryPeriod1", 2) 
		end
		
		cell.SV_RecoveryPeriod1 = model.dataTable.RecoveryPeriod1[step]
	end

	if (model.dataTable.RecoveryPeriod2Perc ~= nil) then
		if (#model.dataTable.RecoveryPeriod2Perc < step) then
			error("Time required exceeds the input table size: RecoveryPeriod2Perc", 2) 
		end
		
		cell.SV_RecoveryPeriod2Perc = model.dataTable.RecoveryPeriod2Perc[step]
	end

	if (model.dataTable.RecoveryPeriod2 ~= nil) then
		if (#model.dataTable.RecoveryPeriod2 < step) then
			error("Time required exceeds the input table size: RecoveryPeriod2", 2) 
		end
		
		cell.SV_RecoveryPeriod2 = model.dataTable.RecoveryPeriod2[step]
	end

	if (model.dataTable.InitialAbandonmentCycle ~= nil) then
		if (#model.dataTable.InitialAbandonmentCycle < step) then
			error("Time required exceeds the input table size: InitialAbandonmentCycle", 2) 
		end
		
		cell.SV_InitialAbandonmentCycle = model.dataTable.InitialAbandonmentCycle[step]
	end

	if (model.dataTable.HalfLife ~= nil) then
		if (#model.dataTable.HalfLife < step) then
			error("Time required exceeds the input table size: HalfLife", 2) 
		end
		
		cell.SV_HalfLife = model.dataTable.HalfLife[step]
	end

	if (model.dataTable.BGBpercBGB ~= nil) then
		if (#model.dataTable.BGBpercBGB < step) then
			error("Time required exceeds the input table size: BGBpercBGB", 2) 
		end
		
		cell.SV_BGBpercBGB = model.dataTable.BGBpercBGB[step]
	end
end

-- Handles with the area cleared calculation.
-- @arg area_init Initial area.
-- @arg halfLife Half Life time.
-- @arg t_final Delta time.
-- @usage --DONTRUN
-- computeAreaExpDecay(cell[attr_initial_area], halfLife[y], year - y - cell.SV_AgriculturalUseCycle - cell.SV_InitialAbandonmentCycle)
function computeAreaExpDecay(area_init, halfLife, t_final)
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
