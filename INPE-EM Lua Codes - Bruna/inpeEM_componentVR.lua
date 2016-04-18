------------------------------------------------------------------------------------------- 
-- Functions in this file (inpeEM_componentVR.lua)
------------------------------------------------------------------------------------------- 
----------------  component processing
-- function componentVR_execute (model, year)
-- function computeFutureDecomposition (cell, year, yearFinal,  attr1,  biomass, rate)                 
-- function computeFutureSlashDecompositionFire (cell, year, yearFinal,  attr1, attr2, biomass, rate, fireCycle, percFirstYear)                 

----------------  preparation
-- function componentVR_createNullComponent (model)
-- function componentVR_init (model)
-- function componentVR_initCellAttrNames (model)
-- function componentVR_initCellAverComponentValues (cell, model)
-- function componentVR_loadFromDB  (model, cell_temp, cell, year)
-- function componentVR_loadFromTable  (model, cell_temp, cell, year)




----------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------
function componentVR_execute ( year, model)
	
  -- Attributes where the future emissions will be stored using the computeFutureSlashDecompositionFire and computeFutureDecomposition functions
  local attr_agb_slash = model.componentVR.attr_agb_slash  
  local attr_agb_slash_fire = model.componentVR.attr_agb_slash_fire  
  local attr_agb_wood = model.componentVR.attr_agb_wood  
  
  local attr_bgb_slash = model.componentVR.attr_bgb_slash 
  local attr_bgb_slash_fire = model.componentVR.attr_bgb_slash_fire  
  local attr_bgb_under = model.componentVR.attr_bgb_under 
   
  local attr_dead_slash = model.componentVR.attr_dead_slash  
  local attr_dead_slash_fire = model.componentVR.attr_dead_slash_fire  
   
  local attr_litter_slash = model.componentVR.attr_litter_slash 
  local attr_litter_slash_fire = model.componentVR.attr_litter_slash_fire 
  
  local attr_elemental = model.componentVR.attr_elemental  
  
  if (model.verbose) then print (year, "Executing VR - mode:"..model.mode) end
  	
  	local biomassaTeste = 0
  for k, cell in pairs( model.cs.cells ) do

  	 
    -- check
    cell.total_biomass_check = 0
    local cell_agb_disturbed = 0
    
    -- Init FATE 
    local cell_agb_agb = 0
    local cell_bgb_bgb = 0

    -- FATE: fire or decomposition
    local cell_agb_lost_1stOrder = 0
    local cell_bgb_lost_1stOrder = 0
    
    -- FATE: fire first year
    local cell_agb_fire_first_year 	= 0
    local cell_bgb_fire_first_year  = 0
    local cell_dead_fire_first_year = 0
    local cell_litter_fire_first_year = 0

    -- FATE: decomposition and subsequent fire 
    local cell_agb_slash = 0
    local cell_bgb_slash = 0     
    local cell_dead_slash = 0     
    local cell_litter_slash = 0     
                
		-- FATE: decomposition 
    local cell_agb_wood = 0
    local cell_bgb_under = 0
	local cell_elemental = 0
	    
	     
     if (cell.D_Area>0) then
        --cell_agb_disturbed  = cell.D_Area*cell.B_AGB 
     	cell_agb_disturbed  = cell.D_Area * cell.B_ActualAGB --TOA

        -- FATE: remain alive
        cell_agb_agb =  cell_agb_disturbed*cell.VR_AGBPercAGB
        cell_bgb_bgb =  cell_agb_disturbed*cell.B_BGBPercAGB*cell.VR_BGBPercBGB

        -- FATE: fire first year
  	    cell_agb_fire_first_year 	= cell_agb_disturbed*cell.VR_AGBPercInstantaneous 
  	    cell_bgb_fire_first_year    = cell_agb_disturbed*cell.B_BGBPercAGB*cell.VR_BGBPercInstantaneous
  	    cell_dead_fire_first_year   = cell_agb_disturbed*cell.B_DeadWoodPercAGB*cell.VR_DeadWoodPercInstantaneous
  	    cell_litter_fire_first_year = cell_agb_disturbed*cell.B_LitterPercAGB*cell.VR_LitterPercInstantaneous
	       		     
        -- FATE: decomposition and subsequent fire 
        cell_agb_slash 		= cell_agb_disturbed*cell.VR_AGBPercDecomposition*(1-cell.VR_DecompositonPercElementalCarbon)
        cell_bgb_slash 		= cell_agb_disturbed*cell.B_BGBPercAGB*cell.VR_BGBPercDecompositionAbove*(1-cell.VR_DecompositonPercElementalCarbon)  
        cell_dead_slash 	= cell_agb_disturbed*cell.B_DeadWoodPercAGB*cell.VR_DeadWoodPercDecomposition*(1-cell.VR_DecompositonPercElementalCarbon)
        cell_litter_slash 	= cell_agb_disturbed*cell.B_LitterPercAGB*cell.VR_LitterPercDecomposition*(1-cell.VR_DecompositonPercElementalCarbon)
                     
				computeFutureSlashDecompositionFire (cell_agb_slash, year, model.yearFinal, cell,  attr_agb_slash,   attr_agb_slash_fire, cell.VR_DecayRateAGBDecomposition, cell.VR_DecompositonFireCyclePeriod)
				computeFutureSlashDecompositionFire (cell_bgb_slash, year, model.yearFinal, cell,  attr_bgb_slash,   attr_bgb_slash_fire, cell.VR_DecayRateBGBDecompositionAbove, cell.VR_DecompositonFireCyclePeriod)
				computeFutureSlashDecompositionFire (cell_dead_slash, year, model.yearFinal, cell,  attr_dead_slash,   attr_dead_slash_fire, cell.VR_DecayRateDeadWoodDecomposition, cell.VR_DecompositonFireCyclePeriod)
				computeFutureSlashDecompositionFire (cell_litter_slash, year, model.yearFinal, cell,  attr_litter_slash,   attr_litter_slash_fire, cell.VR_DecayRateLitterDecomposition, cell.VR_DecompositonFireCyclePeriod)
                  
				-- FATE: decomposition 
				cell_agb_wood = cell_agb_disturbed*cell.VR_AGBPercWoodProducts
        cell_bgb_under = cell_agb_disturbed*cell.B_BGBPercAGB*cell.VR_BGBPercDecompositionUnder*(1-cell.VR_DecompositonPercElementalCarbon)  
                    
        cell_elemental = cell.VR_DecompositonPercElementalCarbon*
                                (cell_agb_disturbed*cell.VR_AGBPercDecomposition +
                                 cell_agb_disturbed*cell.VR_AGBPercWoodProducts +
                                 cell_agb_disturbed*cell.B_BGBPercAGB*cell.VR_BGBPercDecompositionAbove + 
                                 cell_agb_disturbed*cell.B_DeadWoodPercAGB*cell.VR_DeadWoodPercDecomposition + 
                                 cell_agb_disturbed*cell.B_LitterPercAGB*cell.VR_LitterPercDecomposition + 
                                 cell_agb_disturbed*cell.B_BGBPercAGB*cell.VR_BGBPercDecompositionUnder)
                                             
				computeFutureDecomposition (cell_agb_wood, year, model.yearFinal, cell, attr_agb_wood, cell.VR_DecayRateWoodProducts)
				computeFutureDecomposition (cell_bgb_under, year, model.yearFinal, cell, attr_bgb_under, cell.VR_DecayRateBGBDecompositionUnder)
				computeFutureDecomposition (cell_elemental, year, model.yearFinal, cell, attr_elemental, cell.VR_DecayRateElementalCarbon)
     end 
	            
     cell.total_biomass_check = cell.total_biomass_check  + cell_agb_fire_first_year 
     													 + cell_bgb_fire_first_year 
  		    										 + cell_dead_fire_first_year 
  				    								 + cell_litter_fire_first_year                 
     
     ---------------------------------------------- Compute different types os biomass loss
 	             
 	   ---------------------------------------------- 1st order and estimate updated biomass Mtonha-1
     cell_agb_lost_1stOrder 	= cell_agb_disturbed*(1-cell.VR_AGBPercAGB) 
     cell_bgb_lost_1stOrder 	= cell_agb_disturbed*cell.B_BGBPercAGB*(1-cell.VR_BGBPercBGB)
     cell_dead_lost_1stOrder = cell_agb_disturbed*cell.B_DeadWoodPercAGB 
     cell_litter_lost_1stOrder = cell_agb_disturbed*cell.B_LitterPercAGB 
      
     cell_CO2_lost_1stOrder = (cell_agb_lost_1stOrder +    cell_bgb_lost_1stOrder + cell_dead_lost_1stOrder + cell_litter_lost_1stOrder )* cell.B_FactorB_CO2_fire
        
     ------------------------------------------------ 2nd order 
     	cell_all_decay = cell[attr_agb_slash..year] +
     	 						     cell[attr_bgb_slash..year] +
         	 						 cell[attr_dead_slash..year] +
         	 						 cell[attr_litter_slash..year] +
        							 cell[attr_agb_wood..year] + 
        							 cell[attr_elemental..year] + 
        							 cell[attr_bgb_under..year]  
     
      cell_all_fire = cell_agb_fire_first_year + 
 	                    cell_bgb_fire_first_year +
    	  			        cell[attr_agb_slash_fire..year] +
    					        cell[attr_bgb_slash_fire..year] +
    					        cell[attr_dead_slash_fire..year] +
    					        cell[attr_litter_slash_fire..year] 
                
     ------------------------------------------------- CO2 EMISSIONS
     cell_CO2_all_fire 	= cell_all_fire * cell.B_FactorB_CO2_fire
     cell_CO2_all_decay =  cell_all_decay * cell.B_FactorB_CO2

           
     -- Compute process emission   
     cell_CO2_all_components = cell_CO2_all_fire + cell_CO2_all_decay

     ------------------------------------------------- CH4 EMISSIONS - fire components
     cell_CH4_all_fire = cell_all_fire * cell.B_FactorB_CH4_fire
     cell_CO2eq_CH4_all_fire = cell_CH4_all_fire * gwp_CH4
          
     ------------------------------------------------------ N2O EMISSIONS - fire components
     cell_N2O_all_fire = cell_all_fire * cell.B_FactorB_N2O_fire
     cell_CO2eq_N2O_all_fire = cell_N2O_all_fire * gwp_N2O
               
     ------------------------------------------------------ CO EMISSIONS - fire components
     cell_CO_all_fire = cell_all_fire * cell.B_FactorB_CO_fire
     cell_CO2eq_CO_all_fire = cell_CO_all_fire * gwp_CO

     ------------------------------------------------------ NOx EMISSIONS - fire components
     cell_NOx_all_fire = cell_all_fire * cell.B_FactorB_NOx_fire
     cell_CO2eq_NOx_all_fire = cell_NOx_all_fire * gwp_NOx
 
     ------------ Saving some results spatially explicitly
     if (model.save == true) then 
        cell[model.componentVR.attrCO2..year] = cell_CO2_all_components/1000000
        cell[model.componentVR.attrCO2fire..year] = cell_CO2_all_fire/1000000
        cell[model.componentVR.attrCH4..year] = cell_CH4_all_fire/1000000
        cell[model.componentVR.attrN2O..year] = cell_N2O_all_fire/1000000
        cell[model.componentVR.attrCO..year] = cell_CO_all_fire/1000000
        cell[model.componentVR.attrNOx..year] = cell_NOx_all_fire/1000000  
        cell[model.componentVR.attrActualAGB..year] = cell.B_ActualAGB  
     end 
				       	
     ------------- Aggregating results at the regional level (summing cells)
     model.VR_result[year].VR_CO2_1stOrder 		= model.VR_result[year].VR_CO2_1stOrder + cell_CO2_lost_1stOrder
     model.VR_result[year].VR_CO2_2ndOrder 			= model.VR_result[year].VR_CO2_2ndOrder + cell_CO2_all_fire + cell_CO2_all_decay
     model.VR_result[year].VR_CO2_2ndOrder_fire 		= model.VR_result[year].VR_CO2_2ndOrder_fire + cell_CO2_all_fire
     model.VR_result[year].VR_CO2_2ndOrder_decay 		= model.VR_result[year].VR_CO2_2ndOrder_decay + cell_CO2_all_decay
     model.VR_result[year].VR_CH4_CO2Eq_2ndOrder_fire 	= model.VR_result[year].VR_CH4_CO2Eq_2ndOrder_fire + cell_CO2eq_CH4_all_fire
     model.VR_result[year].VR_N2O_CO2Eq_2ndOrder_fire 	= model.VR_result[year].VR_N2O_CO2Eq_2ndOrder_fire + cell_CO2eq_N2O_all_fire
     model.VR_result[year].VR_CO_CO2Eq_2ndOrder_fire 	= model.VR_result[year].VR_CO_CO2Eq_2ndOrder_fire + cell_CO2eq_CO_all_fire
     model.VR_result[year].VR_NOx_CO2Eq_2ndOrder_fire 	= model.VR_result[year].VR_NOx_CO2Eq_2ndOrder_fire + cell_CO2eq_NOx_all_fire
  end  --end of "loop cell"

end

----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function computeFutureSlashDecompositionFire (biomass, year, yearFinal, cell, attr1, attr2, rate, fireCycle, percFirstYear)  
  local difference = 0.0
  local previous = biomass
  local count = 0
  for y = year + 1, yearFinal, 1 do
    local post_decay = attr1..y
    local post_fire  = attr2..y              
    count = count + 1
    
    estimate_decay = compute_exp (biomass, (-1)*rate, y-year)
      
    if (estimate_decay < 0.0) then
      estimate_decay = 0.0;
    end
      
    difference = previous - estimate_decay;
                 
    if (difference < 0.0) then 
      estimate_decay = 0.0
      difference = previous
    end
                       
    cell.total_biomass_check  = cell.total_biomass_check + difference
                      
    cell[post_decay] = cell[post_decay]+ difference
    
    previous = estimate_decay  
      
    if (count == fire_cycle) then
      local fire = estimate_decay*percFirstYear
      previous = previous - fire
      cell[post_fire] = cell[post_fire] + fire
      cell.total_biomass_check  = cell.total_biomass_check + fire                    
      count = 0
    end       
  end    
end
 
----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function computeFutureDecomposition (biomass,  year, yearFinal, cell, attr1,   rate)         
  local difference = 0.0
  local previous = biomass
  local count = 0
  for y = year + 1, yearFinal, 1 do
    local post_decay = attr1..y
    
    estimate_decay = compute_exp (biomass, (-1)*rate, y-year)
    
    if (estimate_decay < 0.0) then
      estimate_decay = 0.0;
    end
    
    difference = previous - estimate_decay;
                
    if (difference < 0.0) then 
      estimate_decay = 0.0
      difference = previous
    end
                     
    cell.total_biomass_check  = cell.total_biomass_check + difference
                    
    cell[post_decay] = cell[post_decay]+ difference
    
    previous = estimate_decay  
  end 
end

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentVR_createNullComponent (model)
  if model ~= nil then
  	model.componentVR = 
    {
      name = "undefined",
      description = "",			   				   
      averAGBPercAGB  = 0,       
      averAGBPercInstantaneous  = 0,       
      averAGBPercWoodProducts  = 0,   
      averAGBPercDecomposition      	= 0,
      
      averBGBPercBGB 	= 0,
      averBGBPercInstantaneous	= 0,
      averBGBPercDecompositionAbove = 0, 
      averBGBPercDecompositionUnder = 0, 
      
      averLitterPercInstantaneous = 0,
      averLitterPercDecomposition = 0,
      averDeadWoodPercInstantaneous = 0,
      averDeadWoodPercDecomposition = 0,
      averDecompositionPercFireCycle 	= 0,
      averDecompositonPercElementalCarbon= 0,
       
      averDecayRateWoodProducts = 0, 
      averDecayRateElementalCarbon = 0, 
      averDecayRateAGBDecomposition = 0, 
      averDecayRateBGBDecompositionUnder = 0,
      averDecayRateBGBDecompositionUnderUnder = 0,
      averDecayRateLitterDecomposition = 0
    }
	end
end
			
------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentVR_init (model)
  -- init output attributes
  model.componentVR.saveAttrs = {}
  model.componentVR.saveCount = 0
  
  model.componentVR.attrCO2		 		= "CO2_"
  model.componentVR.attrCO2fire		= "CO2fire_"
  model.componentVR.attrCH4 			= "CH4_"
  model.componentVR.attrN2O 			= "N2O_"
  model.componentVR.attrCO 				= "CO_"
  model.componentVR.attrNOx 			= "NOx_"
  model.componentVR.attrActualAGB = "AGB_"
				   
  if (model.save == true) then 
    for year= model.yearInit, model.yearFinal, 1 do                            
  	  model.componentVR.saveCount = model.componentVR.saveCount + 1
      model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrCO2..year
  	  model.componentVR.saveCount = model.componentVR.saveCount + 1
      model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrCO2fire..year
      model.componentVR.saveCount = model.componentVR.saveCount + 1
      model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrCH4..year
      model.componentVR.saveCount = model.componentVR.saveCount + 1
      model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrN2O..year
      model.componentVR.saveCount = model.componentVR.saveCount + 1
      model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrCO..year
      model.componentVR.saveCount = model.componentVR.saveCount + 1
      model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrNOx..year   
      model.componentVR.saveCount = model.componentVR.saveCount + 1
      model.componentVR.saveAttrs[model.componentVR.saveCount] = model.componentVR.attrActualAGB..year   
		end	    
  end
	   
  -- init (run time) future cellattribute names
  model.componentVR.attr_agb_slash = model.componentVR.name.."agb_slash"  
  model.componentVR.attr_agb_slash_fire = model.componentVR.name.."agb_slash_fire"  
  model.componentVR.attr_agb_wood = model.componentVR.name.."agb_wood"  
  
  model.componentVR.attr_bgb_slash = model.componentVR.name.."bgb_slash" 
  model.componentVR.attr_bgb_slash_fire = model.componentVR.name.."bgb_slash_fire"  
  model.componentVR.attr_bgb_under = model.componentVR.name.."bgb_under" 
   
         
  model.componentVR.attr_dead_slash = model.componentVR.name.."dead_slash" 
  model.componentVR.attr_dead_slash_fire = model.componentVR.name.."dead_slash_fire"  
  
  model.componentVR.attr_litter_slash = model.componentVR.name.."litter_slash" 
  model.componentVR.attr_litter_slash_fire = model.componentVR.name.."litter_slash_fire"  
  
  model.componentVR.attr_elemental = model.componentVR.name.."_elemental"  
   
 forEachCell(model.cs,function(cell)
    -- init future cell variables
    for year= model.yearInit, model.yearFinal, 1 do                
      cell[model.componentVR.attr_agb_slash..year] = 0   
      cell[model.componentVR.attr_agb_wood..year] = 0  
      cell[model.componentVR.attr_agb_slash_fire..year] = 0  
      
      cell[model.componentVR.attr_bgb_slash..year] = 0  
      cell[model.componentVR.attr_bgb_slash_fire..year] = 0  
      cell[model.componentVR.attr_bgb_under..year] = 0  
      
      cell[model.componentVR.attr_dead_slash..year] = 0  
      cell[model.componentVR.attr_dead_slash_fire..year] = 0  
       
      cell[model.componentVR.attr_litter_slash..year] = 0  
      cell[model.componentVR.attr_litter_slash_fire..year] = 0  
      
      cell[model.componentVR.attr_elemental..year] = 0  
    end
    -- init default values in each cell
    componentVR_initCellAverComponentValues  (cell, model)
    
	--TOA
    --cell.actualBGB = model.componentB.averAGB
--	cell.B_ActualAGB = model.componentB.averAGB  -- anap - error: only here?? if degrad not running, doing wrong
 --   cell.actualBGB = model.componentB.averAGB*model.componentB.averBGBPercAGB
	
  end)
  
  -- init database attr names for component parameters
  componentVR_initCellAttrNames (model)
end
   
----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function componentVR_initCellAverComponentValues (cell, model)
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


function componentVR_verify (model)
  if (model.componentVR.name == nil)
  then error ("Missing VR parameter: name", 5) end
  
  if (model.componentVR.description == nil)
  then error ("Missing VR parameter: description", 5) end
   
  if (model.componentVR.averAGBPercAGB == nil)
  then error ("Missing VR parameter: averAGBPercAGB", 5) end
   
  if (model.componentVR.averAGBPercWoodProducts == nil)
  then error ("Missing VR parameter: averAGBPercWoodProducts", 5) end      
  
  if (model.componentVR.averAGBPercInstantaneous == nil)
  then error ("Missing VR parameter: averAGBPercInstantaneous", 5) end	       
   
  if (model.componentVR.averAGBPercDecomposition == nil)
	then error ("Missing VR parameter: averAGBPercDecomposition", 5) end   
   
  if (model.componentVR.averDeadWoodPercInstantaneous == nil)
  then error ("Missing VR parameter: averDeadWoodPercInstantaneous", 5) end	       
   
  if (model.componentVR.averDeadWoodPercDecomposition == nil)
	then error ("Missing VR parameter: averDeadWoodPercDecomposition", 5) end        
  
  if (model.componentVR.averLitterPercInstantaneous == nil)
  then error ("Missing VR parameter: averLitterPercInstantaneous", 5) end	       
   
  if (model.componentVR.averLitterPercDecomposition == nil)
	then error ("Missing VR parameter: averLitterPercDecomposition", 5) end        
   
  if (model.componentVR.averBGBPercBGB == nil)
	then error ("Missing VR parameter: averBGBPercBGB", 5) end 
     
  if (model.componentVR.averBGBPercInstantaneous == nil)
  then error ("Missing VR parameter: averBGBPercInstantaneous", 5) end
     
  if (model.componentVR.averBGBPercDecompositionAbove == nil)
  then error ("Missing VR parameter: averBGBPercDecompositionAbove", 5) end
       
  if (model.componentVR.averBGBPercDecompositionUnder == nil)
  then error ("Missing VR parameter: averBGBPercDecompositionUnder", 5) end
       
  if (model.componentVR.averDecompositonPercElementalCarbon == nil)
  then error ("Missing VR parameter: averDecompositonPercElementalCarbon", 5) end
     
  if (model.componentVR.averDecompositionFireCyclePeriod == nil)
  then error ("Missing VR parameter: averDecompositionFireCyclePeriod", 5) end
  
  if (model.componentVR.averDecayRateAGBDecomposition == nil)
  then error ("Missing VR parameter: averDecayRateAGBDecomposition", 5) end
     
  if (model.componentVR.averDecayRateWoodProducts == nil)
  then error ("Missing VR parameter: averDecayRateWoodProducts", 5) end
     
  if (model.componentVR.averDecayRateElementalCarbon == nil)
  then error ("Missing VR parameter: averDecayRateElementalCarbon", 5) end
     
  if (model.componentVR.averDecayRateBGBDecompositionUnder == nil)
  then error ("Missing VR parameter: averDecayRateBGBDecompositionUnder", 5) end
  
  if (model.componentVR.averDecayRateBGBDecompositionAbove == nil)
  then error ("Missing VR parameter: averDecayRateBGBDecompositionAbove", 5) end
     
  if (model.componentVR.averDecayRateDeadWoodDecomposition == nil)
  then error ("Missing VR parameter: averDecayRateDeadWoodDecomposition", 5) end
  
  if (model.componentVR.averDecayRateLitterDecomposition == nil)
  then error ("Missing VR parameter: averDecayRateLitterDecomposition", 5) end
  
  return true
end

----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function componentVR_initCellAttrNames (model)
  model.componentVR.attrAGBPercAGB  			= model.componentVR.name.."AGBPercAGB"       
  model.componentVR.attrAGBPercWoodProducts  	= model.componentVR.name.."AGBPercWoodProducts"             
  model.componentVR.attrAGBPercInstantaneous  	= model.componentVR.name.."AGBPercInstantaneous"       
  model.componentVR.attrAGBPercDecomposition 	= model.componentVR.name.."AGBPercDecomposition" 
   
  model.componentVR.attrBGBPercBGB 			= model.componentVR.name.."BGBPercBGB"
  model.componentVR.attrBGBPercInstantaneous	= model.componentVR.name.."BGBPercInstantaneous"
  model.componentVR.attrBGBPercDecompositionAbove   = model.componentVR.name.."BGBPercDecompositionAbove"
  model.componentVR.attrBGBPercDecompositionUnder   = model.componentVR.name.."BGBPercDecompositionUnder"
   
  model.componentVR.attrDeadWoodPercInstantaneous  	= model.componentVR.name.."DeadWoodPercInstantaneous"       
  model.componentVR.attrDeadWoodPercDecomposition 	= model.componentVR.name.."DeadWoodPercDecomposition" 
  
  model.componentVR.attrLitterPercInstantaneous  	= model.componentVR.name.."LitterPercInstantaneous"       
  model.componentVR.attrLitterPercDecomposition 	= model.componentVR.name.."LitterPercDecomposition" 
  
  model.componentVR.attrDecompositionPercElementalCarbon 		= model.componentVR.name.."DecompositionPercElementalCarbon" 
  model.componentVR.attrDecompositonFireCyclePeriod      		= model.componentVR.name.."DecompositonFireCyclePeriod"             
  
  model.componentVR.attrDecayRateAGBDecomposition 			= model.componentVR.name.."DecayRateAGBDecomposition" 
  model.componentVR.attrDecayRateDeadWoodDecomposition 	= model.componentVR.name.."DecayRateDeadWoodDecomposition" 
  model.componentVR.attrDecayRateLitterDecomposition 		= model.componentVR.name.."DecayRateLitterDecomposition" 
  model.componentVR.attrDecayRateWoodProducts 					= model.componentVR.name.."DecayRateWoodProducts" 
  model.componentVR.attrDecayRateElementalCarbon 				= model.componentVR.name.."DecayRateElementalCarbon" 
  model.componentVR.attrDecayRateBGBDecompositionUnder 	= model.componentVR.name.."DecayRateBGBDecompositionUnder" 
  model.componentVR.attrDecayRateBGBDecompositionAbove 	= model.componentVR.name.."DecayRateBGBDecompositionUnderAbove" 
end

------------------------------------------------------------------------------------------------------	   
------------------------------------------------------------------------------------------------------	   
function componentVR_loadFromDB  (model, cell_temp, cell, y)
  if cell_temp[model.componentVR.attrAGBPercAGB..y] ~= nil then
 	      cell.VR_AGBPercAGB = cell_temp[model.componentVR.attrAGBPercAGB..y]
  end
 
  if cell_temp[model.componentVR.attrAGBPercWoodProducts..y] ~= nil then
 	      cell.VR_AGBPercWoodProducts = cell_temp[model.componentVR.attrAGBPercWoodProducts..y]
  end
 
  if cell_temp[model.componentVR.attrAGBPercInstantaneous..y] ~= nil then
 	      cell.VR_AGBPercInstantaneous = cell_temp[model.componentVR.attrAGBPercInstantaneous..y]
  end
 
  if cell_temp[model.componentVR.attrAGBPercDecomposition..y] ~= nil then
 	      cell.VR_AGBPercDecomposition = cell_temp[model.componentVR.attrAGBPercDecomposition..y]
  end
  
  if cell_temp[model.componentVR.attrBGBPercBGB..y] ~= nil then
 	      cell.VR_BGBPercBGB 	= cell_temp[model.componentVR.attrBGBPercBGB..y]
  end

 if cell_temp[model.componentVR.attrBGBPercInstantaneous..y] ~= nil then
	      cell.VR_BGBPercInstantaneous 	= cell_temp[model.componentVR.attrBGBPercInstantaneous..y]
 end
  
  if cell_temp[model.componentVR.attrBGBPercDecompositionUnder..y] ~= nil then
 	      cell.VR_BGBPercDecompositionUnder 	= cell_temp[model.componentVR.attrBGBPercDecompositionUnder..y]
  end
  
  if cell_temp[model.componentVR.attrBGBPercDecompositionAbove..y] ~= nil then
 	      cell.VR_BGBPercDecompositionAbove 	= cell_temp[model.componentVR.attrBGBPercDecompositionAbove..y]
  end
  
  if cell_temp[model.componentVR.attrLitterPercInstantaneous..y] ~= nil then
 	      cell.VR_LitterPercInstantaneous	= cell_temp[model.componentVR.attrLitterPercInstantaneous..y]
  end
 
  if cell_temp[model.componentVR.attrLitterPercDecomposition..y] ~= nil then
 	      cell.VR_LitterPercDecomposition 	= cell_temp[model.componentVR.attrLitterPercDecomposition..y]
  end
  
  if cell_temp[model.componentVR.attrDeadWoodPercInstantaneous..y] ~= nil then
 	      cell.VR_DeadWoodPercInstantaneous	= cell_temp[model.componentVR.attrDeadWoodPercInstantaneous..y]
  end
 
  if cell_temp[model.componentVR.attrDeadWoodPercDecomposition..y] ~= nil then
 	      cell.VR_DeadWoodPercDecomposition 	= cell_temp[model.componentVR.attrDeadWoodPercDecomposition..y]
  end
  
  if cell_temp[model.componentVR.attrDecompositionPercElementalCarbon..y] ~= nil then
 	      cell.VR_DecompositonPercElementalCarbon 	= cell_temp[model.componentVR.attrDecompositionPercElementalCarbon..y]
  end
 
  if cell_temp[model.componentVR.attrDecompositonFireCyclePeriod..y] ~= nil then
 	      cell.VR_DecompositonFireCyclePeriod 	= cell_temp[model.componentVR.attrDecompositonFireCyclePeriod..y]
  end
 
  --------------------- DECOMPOSITION FATE - DECAY RATES
  if cell_temp[model.componentVR.attrDecayRateAGBDecomposition..y] ~= nil then
 	      cell.VR_DecayRateAGBDecomposition	= cell_temp[model.componentVR.attrDecayRateAGBDecomposition..y]
  end
 
  if cell_temp[model.componentVR.attrDecayRateWoodProducts..y] ~= nil then
 	      cell.VR_DecayRateWoodProducts 	= cell_temp[model.componentVR.attrDecayRateWoodProducts..y]
  end
 
  if cell_temp[model.componentVR.attrDecayRateElementalCarbon..y] ~= nil then
 	      cell.VR_DecayRateElementalCarbon 	= cell_temp[model.componentVR.attrDecayRateElementalCarbon..y]
  end
 
  if cell_temp[model.componentVR.attrDecayRateBGBDecompositionUnder..y] ~= nil then
 	      cell.VR_DecayRateBGBDecompositionUnder 	= cell_temp[model.componentVR.attrDecayRateBGBDecompositionUnder..y]
  end
  
  if cell_temp[model.componentVR.attrDecayRateBGBDecompositionAbove..y] ~= nil then
 	      cell.VR_DecayRateBGBDecompositionAbove 	= cell_temp[model.componentVR.attrDecayRateBGBDecompositionAbove..y]
  end
 
  if cell_temp[model.componentVR.attrDecayRateDeadWoodDecomposition..y] ~= nil then
 	      cell.VR_DecayRateDeadWoodDecomposition 	= cell_temp[model.componentVR.attrDecayRateDeadWoodDecomposition..y]
  end
  
  if cell_temp[model.componentVR.attrDecayRateLitterDecomposition..y] ~= nil then
 	      cell.VR_DecayRateLitterDecomposition 	= cell_temp[model.componentVR.attrDecayRateLitterDecomposition..y]
  end
end

------------------------------------------------------------------------------------------------------	   
------------------------------------------------------------------------------------------------------	   
function componentVR_loadFromTable(model)
  --------------------- AGB
  if (model.dataTable.AGBPercAGB ~= nil) then
    if (#model.dataTable.AGBPercAGB < step) then
      error ("Time required exceeds the input table size: DsreaPercVegSec", 5) 
    end
    cell.VR_AGBPercAGB = model.dataTable.AGBPercAGB [step]
	end
    
  if (model.dataTable.AGBPercWoodProducts ~= nil) then
    if (#model.dataTable.AGBPercWoodProducts < step) then
	    error ("Time required exceeds the input table size: AGBPercWoodProducts", 5) 
    end
		cell.VR_AGBPercWoodProducts = model.dataTable.AGBPercWoodProducts [step]
  end

  if (model.dataTable.AGBPercInstantaneous ~= nil) then
    if (#model.dataTable.AGBPercInstantaneous < step) then
   	  error ("Time required exceeds the input table size: AGBPercInstantaneous", 5) 
    end
    cell.VR_AGBPercInstantaneous = model.dataTable.AGBPercInstantaneous [step]
  end

  if (model.dataTable.AGBPercDecomposition ~= nil) then
    if (#model.dataTable.AGBPercDecomposition < step) then
	    error ("Time required exceeds the input table size: AGBPercDecomposition", 5) 
	  end
    cell.VR_AGBPercDecomposition = model.dataTable.AGBPercDecomposition [step]
  end    

   --------------------- BGB
  if (model.dataTable.BGBPercBGB ~= nil) then
    if (#model.dataTable.BGBPercBGB < step) then
      error ("Time required exceeds the input table size: BGBPercBGB", 5) 
    end
    cell.VR_BGBPercBGB = model.dataTable.BGBPercBGB [step]
  end    

  if (model.dataTable.BGBPercInstantaneous ~= nil) then
    if (#model.dataTable.BGBPercInstantaneous < step) then
      error ("Time required exceeds the input table size: BGBPercInstantaneous", 5) 
    end
    cell.VR_BGBPercInstantaneous = model.dataTable.BGBPercInstantaneous [step]
  end 
      
  if (model.dataTable.BGBPercDecompositionUnder ~= nil) then
    if (#model.dataTable.BGBPercDecompositionUnder < step) then
      error ("Time required exceeds the input table size: BGBPercDecompositionUnder", 5) 
    end
    cell.VR_BGBPercDecompositionUnder = model.dataTable.BGBPercDecompositionUnder [step]
  end    
   
  if (model.dataTable.BGBPercDecompositionAbove ~= nil) then
    if (#model.dataTable.BGBPercDecompositionAbove < step) then
      error ("Time required exceeds the input table size: BGBPercDecompositionAbove", 5) 
    end
    cell.VR_BGBPercDecompositionAbove = model.dataTable.BGBPercDecompositionAbove [step]
  end    
 
  --------------------- LITTER
  if (model.dataTable.LitterPercInstantaneous ~= nil) then
    if (#model.dataTable.LitterPercInstantaneous < step) then
      error ("Time required exceeds the input table size: LitterPercInstantaneous", 5) 
    end
    cell.VR_LitterPercInstantaneous = model.dataTable.LitterPercInstantaneous [step]
  end

  if (model.dataTable.LitterPercDecomposition ~= nil) then
    if (#model.dataTable.LitterPercDecomposition < step) then
      error ("Time required exceeds the input table size: LitterPercDecomposition", 5) 
    end
    cell.VR_LitterPercDecomposition = model.dataTable.LitterPercDecomposition [step]
  end      
   
  --------------------- DEAD WOOD
  if (model.dataTable.DeadWoodPercInstantaneous ~= nil) then
    if (#model.dataTable.DeadWoodPercInstantaneous < step) then
      error ("Time required exceeds the input table size: DeadWoodPercInstantaneous", 5) 
    end
    cell.VR_DeadWoodPercInstantaneous = model.dataTable.DeadWoodPercInstantaneous [step]
  end

  if (model.dataTable.DeadWoodPercDecomposition ~= nil) then
    if (#model.dataTable.DeadWoodPercDecomposition < step) then
      error ("Time required exceeds the input table size: DeadWoodPercDecomposition", 5) 
    end
    cell.VR_DeadWoodPercDecomposition = model.dataTable.DeadWoodPercDecomposition [step]
  end   

  --------------------- DECOMPOSITION FATE
  if (model.dataTable.DecompositionPercElementalCarbon ~= nil) then
    if (#model.dataTable.DecompositionPercElementalCarbon < step) then
      error ("Time required exceeds the input table size: DecompositionPercElementalCarbon", 5) 
    end
    cell.VR_DecompositonPercElementalCarbon = model.dataTable.DecompositionPercElementalCarbon [step]
  end      

  if (model.dataTable.DecompositonFireCyclePeriod ~= nil) then
    if (#model.dataTable.DecompositonFireCyclePeriod < step) then
      error ("Time required exceeds the input table size: DecompositonFireCyclePeriod", 5) 
    end
    cell.VR_DecompositonFireCyclePeriod = model.dataTable.DecompositonFireCyclePeriod [step]
  end   
 
  --------------------- DECOMPOSITION FATE - DECAY RATES
  if (model.dataTable.DecayRateAGBDecomposition ~= nil) then
    if (#model.dataTable.DecayRateAGBDecomposition < step) then
      error ("Time required exceeds the input table size: DecayRateAGBDecomposition", 5) 
    end
    cell.VR_DecayRateAGBDecomposition = model.dataTable.DecayRateAGBDecomposition [step]
  end   

  if (model.dataTable.DecayRateWoodProducts ~= nil) then
    if (#model.dataTable.DecayRateWoodProducts < step) then
      error ("Time required exceeds the input table size: DecayRateWoodProducts", 5) 
    end
    cell.VR_DecayRateWoodProducts = model.dataTable.DecayRateWoodProducts [step]
  end   
  
  if (model.dataTable.DecayRateElementalCarbon ~= nil) then
    if (#model.dataTable.DecayRateElementalCarbon < step) then
      error ("Time required exceeds the input table size: DecayRateElementalCarbon", 5) 
    end
    cell.VR_DecayRateElementalCarbon = model.dataTable.DecayRateElementalCarbon [step]
  end   
 
  if (model.dataTable.DecayRateBGBDecompositionUnder ~= nil) then
    if (#model.dataTable.DecayRateBGBDecompositionUnder < step) then
      error ("Time required exceeds the input table size: DecayRateBGBDecompositionUnder", 5) 
    end
    cell.VR_DecayRateBGBDecompositionUnder = model.dataTable.DecayRateBGBDecompositionUnder [step]
  end  

  if (model.dataTable.DecayRateBGBDecompositionAbove ~= nil) then
    if (#model.dataTable.DecayRateBGBDecompositionAbove < step) then
      error ("Time required exceeds the input table size: DecayRateBGBDecompositionAbove", 5) 
    end
    cell.VR_DecayRateBGBDecompositionAbove = model.dataTable.DecayRateBGBDecompositionAbove [step]
  end 
 
  if (model.dataTable.DecayRateLitterDecomposition ~= nil) then
    if (#model.dataTable.DecayRateLitterDecomposition < step) then
      error ("Time required exceeds the input table size: DecayRateLitterDecomposition", 5) 
    end
    cell.VR_DecayRateLitterDecomposition = model.dataTable.DecayRateLitterDecomposition [step]
  end   
 
  if (model.dataTable.DecayRateDeadWoodDecomposition ~= nil) then
    if (#model.dataTable.DecayRateDeadWoodDecomposition < step) then
      error ("Time required exceeds the input table size: DecayRateDeadWoodDecomposition", 5) 
    end
    cell.VR_DecayRateDeadWoodDecomposition = model.dataTable.DecayRateDeadWoodDecomposition [step]
  end   
end
 