------------------------------------------------------------------------------------------- 
-- Functions in this file (inpeEM_componentDEGRAD.lua)
------------------------------------------------------------------------------------------- 
----------------  Component processing
-- function componentDEGRAD_execute (model, year)                

----------------  Preparation
-- function componentDEGRAD_createNullComponent (model)
-- function componentDEGRAD_init (model)
-- function componentDEGRAD_initCellAttrNames (model)
-- function componentDEGRAD_initCellAverComponentValues (cell, model)
-- function componentDEGRAD_loadFromDB  (model, cell_temp, cell, year)
-- function componentDEGRAD_loadFromTable  (model, cell_temp, cell, year)

flagDEGRAD = false
----------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------
function componentDEGRAD_execute ( year, model)
   	
	if (model.verbose) then print (year, "Executing Degrad - mode:"..model.mode) end
	
	local sum_cell_loss = 0
	local num_cell_loss = 0
	
	for k, cell in pairs( model.cs.cells ) do
	
	     cell.remaining_forest_area = model.cs.cellarea - cell.D_NoData - cell.D_AreaAcc + cell.D_Area
	    -- print (year.."F"..cell.remaining_forest_area)
	
	      if (model.mode == "non_spatial") then
	             if (cell.DEGRAD_Degrad > 0 and cell.DEGRAD_AGB_loss > 0) then
	                     flagDEGRAD = true
	             end
	      end
	
	       local cell_CO2_absorption_Degrad = 0
	       local cell_CO2_emission_Degrad   = 0
	       
			--Current average biomass in the cell
			if year == model.yearInit then 
				
				cell.AGBRegrowRate = 0 	
				cell.DegradLoss = 0
				 if (model.mode == "spatial") then
				     if (flagDEGRAD) then
				     	cell.B_ActualAGB = cell.B_AGB*(1-cell.DEGRAD_AGB_percReduction)  -- quite a gambi, need to run non-spatial model first to adjust
				     end
				     
				      -- Reinitialize the rate	(only here - it was wrong, always reinitializing when it was only growing)	
					cell.AGBRegrowRate = 0
				    if cell.DEGRAD_PeriodRegrow ~= 0 then		-- se fizer isso, nao combina regeneracao - ok   
				       cell.AGBRegrowRate = (cell.B_AGB - cell.B_ActualAGB)/ cell.DEGRAD_PeriodRegrow 
				    end
				 end
			end
			
    --------------------------- Regrowth and Carbon uptake
       			
	      if (cell.remaining_forest_area > 0) then -- only if you have area to grow you grow... 
	   
       		-- Vegetation growth
			if (cell.B_ActualAGB + cell.AGBRegrowRate) >= cell.B_AGB then
			    cell.AGBRegrowRate = cell.B_AGB - cell.B_ActualAGB
			    cell.B_ActualAGB = cell.B_AGB			    
			else  
				cell.B_ActualAGB = cell.B_ActualAGB + cell.AGBRegrowRate				
			end
			
			 AGBupdated = cell.B_ActualAGB
			 rate = cell.AGBRegrowRate
			
			-- Carbon uptake according to the rate
			local cell_agb_degrad_regrow = cell.AGBRegrowRate * (cell.remaining_forest_area)
			local cell_bgb_degrad_regrow = cell.AGBRegrowRate * cell.B_BGBPercAGB *(cell.remaining_forest_area)

			
			-- recompute growth if area was deforested for next step assume part of it was lost
	        local percForLost = cell.D_Area/(cell.remaining_forest_area)
	        cell.AGBRegrowRate = cell.AGBRegrowRate*(1-percForLost)
	        
			-- Absorption in the cell
			cell_CO2_absorption_Degrad = (cell_agb_degrad_regrow + cell_bgb_degrad_regrow) * cell.B_FactorB_CO2  
			
		else 
		    cell.B_ActualAGB = 0
		end	
  --------------------------- Degradation and emission
	 
		    if 	(cell.DEGRAD_Degrad > 0) then
		                   
				    -- verify if degradation is compatible with remaining forest area
				    if (cell.remaining_forest_area) <  cell.DEGRAD_Degrad then  
				                print (year, "ERROR", cell.remaining_forest_area, cell.DEGRAD_Degrad)
				                cell.DEGRAD_Degrad = cell.remaining_forest_area
		                        --error ("Error in the data: degradation is not compatible with remaining forest area", )
		            end
		          
					
					-- Contador do número de eventos na célula
					if cell.DEGRAD_Degrad > 0  and cell.DEGRAD_AGB_loss > 0 then
						cell.countDegradYears = cell.countDegradYears + 1
						num_cell_loss = num_cell_loss + 1

					end
					
					-- Perda de biomassa TOTAL neste passo de tempo
					local cell_agb_degrad    =  cell.B_ActualAGB * cell.DEGRAD_Degrad * cell.DEGRAD_AGB_loss  
					local cell_bgb_degrad    =  cell.B_ActualAGB * cell.DEGRAD_Degrad * cell.DEGRAD_BGB_loss * cell.B_BGBPercAGB
					local cell_litter_degrad =  cell.B_ActualAGB * cell.DEGRAD_Degrad * cell.DEGRAD_Litter_loss * cell.B_LitterPercAGB
					local cell_wood_degrad   =  cell.B_ActualAGB * cell.DEGRAD_Degrad * cell.DEGRAD_DeadWood_loss * cell.B_DeadWoodPercAGB
					
					-- Emissão decorrente da degradação
					cell_CO2_emission_Degrad = (cell_agb_degrad + cell_bgb_degrad + cell_litter_degrad + cell_wood_degrad)* cell.B_FactorB_CO2_fire  
--					cell_CO2_emission_Degrad = (cell_agb_degrad + cell_bgb_degrad)* cell.B_FactorB_CO2  
		
					-- Atualização da biomassa média 
					if (cell.remaining_forest_area) ~= 0 then
						cell.B_ActualAGB = cell.B_ActualAGB - (cell_agb_degrad / (cell.remaining_forest_area))
					end
					
					cell.DegradLoss = 0
					if cell.B_AGB > 0 then
						cell.DegradLoss = (cell.B_AGB - cell.B_ActualAGB) / cell.B_AGB
				        sum_cell_loss = sum_cell_loss + cell.DegradLoss
		            end 
				    -- Reinitialize the rate	(only here - it was wrong version talita, always reinitializing when it was only growing)
				    -- ANAP/JEAN: aqui está faltando decrescimo se teve muitos eventos - corrigir a taxa e talvez o proprio cell.B_AGB (teto, nunca recupera) se teve muitos eventos. nao serve para nao espacial...usar submodelos diferentes	
					cell.AGBRegrowRate = 0
				    if cell.DEGRAD_PeriodRegrow ~= 0 then		   
				       cell.AGBRegrowRate = (cell.B_AGB - cell.B_ActualAGB)/ cell.DEGRAD_PeriodRegrow 
				    end
				    
	      end   -- only if there was degration, otherwise emission is zero
	
	     local rate2 = cell.AGBRegrowRate
      
	      ---- Correct Rate in case there is also deforestation in this step: for the next step regrow...  
	      if (cell.remaining_forest_area > 0) then -- only if you have area to grow you grow... 
	               cell.AGBRegrowRate = cell.AGBRegrowRate*(1 - cell.D_Area/(cell.remaining_forest_area))
	      end

	      
	     if cell.AGBRegrowRate > 4 then print (year, cell.B_AGB, AGBupdated, cell.B_ActualAGB, 
	                                                 rate, rate2, cell.AGBRegrowRate) end

	      
	       model.DEGRAD_result[year].DEGRAD_Area = model.DEGRAD_result[year].DEGRAD_Area + cell.DEGRAD_Degrad
		
			-- Aggregating results at the regional level (summing cells)
			model.DEGRAD_result[year].DEGRAD_CO2_emission = model.DEGRAD_result[year].DEGRAD_CO2_emission + cell_CO2_emission_Degrad
			model.DEGRAD_result[year].DEGRAD_CO2_absorption = model.DEGRAD_result[year].DEGRAD_CO2_absorption + cell_CO2_absorption_Degrad 
			
			-- Aggregating results at the regional level (summing cells): considering only cell above Degrad Limiar
			if cell.countDegradYears >=  cell.DEGRAD_LimiarDegradYears and cell.DegradLoss >= cell.DEGRAD_LimiarDegradLoss then
				model.DEGRAD_result[year].DEGRAD_CO2_emission_aboveDegradLimiar = model.DEGRAD_result[year].DEGRAD_CO2_emission_aboveDegradLimiar + cell_CO2_emission_Degrad
				model.DEGRAD_result[year].DEGRAD_CO2_absorption_aboveDegradLimiar = model.DEGRAD_result[year].DEGRAD_CO2_absorption_aboveDegradLimiar + cell_CO2_absorption_Degrad 
			end
			
			if (model.save == true) then 
				cell[model.componentDEGRAD.attrActualAGB..year] = cell.B_ActualAGB  
				cell[model.componentDEGRAD.attrCountDegradYears..year] = cell.countDegradYears  

			end 
			
			
		end
	--	print (sum_cell_loss, num_cell_loss)
		
	    if (num_cell_loss > 0) then model.DEGRAD_result[year].DEGRAD_AveLoss = sum_cell_loss/num_cell_loss end

end

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentDEGRAD_createNullComponent (model)
  if model ~= nil then
    model.componentDEGRAD = 
    {
      name = "undefined",
      description = "",
      averAGB_loss = 0,
      averBGB_loss  = 0,
      averDeadWood_loss = 0,
      averLitter_loss  = 0,
      averDegrad  = 0,
      PeriodRegrow = 1,
      LimiarDegradYears = 1,
      LimiarDegradLoss = 0
    }
  end
end

------------------------------------------------------------------------------------------- 
-------------------------------------------------------------------------------------------  
function componentDEGRAD_init (model)
  -- init output attributes
  model.componentDEGRAD.saveAttrs = {}
  model.componentDEGRAD.saveCount = 0
  
  model.componentDEGRAD.attrActualAGB = "AGB_"
  model.componentDEGRAD.attrCountDegradYears = "Count_"
				   
  if (model.save == true) then 
    for year= model.yearInit, model.yearFinal, 1 do                            
  	  model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
      model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrActualAGB..year  
      model.componentDEGRAD.saveCount = model.componentDEGRAD.saveCount + 1
      model.componentDEGRAD.saveAttrs[model.componentDEGRAD.saveCount] = model.componentDEGRAD.attrCountDegradYears..year   
 
	end	    
  end
     
	 -- init (run time) future cellattribute names
  model.componentDEGRAD.attrAGB_loss = model.componentDEGRAD.name.."AGB_loss_"  
  model.componentDEGRAD.attrBGB_loss = model.componentDEGRAD.name.."BGB_loss_"  
  model.componentDEGRAD.attrDeadWood_loss = model.componentDEGRAD.name.."DeadWood_loss_"    
  model.componentDEGRAD.attrLitter_loss = model.componentDEGRAD.name.."Litter_loss_"   
  model.componentDEGRAD.attrPeriodRegrow = model.componentDEGRAD.name.."PeriodRegrow_"   
	
  
	forEachCell(model.cs,function(cell)
		 cell.DEGRAD_AGB_loss = 0
		 cell.DEGRAD_BGB_loss = 0
		 cell.DEGRAD_DeadWood_loss   = 0
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
	end)

	componentDEGRAD_initCellAttrNames (model)
end

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentDEGRAD_initCellAttrNames (model)
  -- Initialize cell space attr names 
	model.componentDEGRAD.attrAGB_loss = model.componentDEGRAD.name.."AGB_loss_"
	model.componentDEGRAD.attrBGB_loss = model.componentDEGRAD.name.."BGB_loss_"
	model.componentDEGRAD.attrDeadWood_loss = model.componentDEGRAD.name.."DeadWood_loss_"
	model.componentDEGRAD.attrLitter_loss = model.componentDEGRAD.name.."Litter_loss_"
	--model.componentDEGRAD.attrDegrad = model.componentDEGRAD.name.."Degrad_"	TOA
	model.componentDEGRAD.attrDegrad = "Degrad"	
	model.componentDEGRAD.attrPeriodRegrow = model.componentDEGRAD.name.."PeriodRegrow_"	
	model.componentDEGRAD.attrLimiarDegradYears = model.componentDEGRAD.name.."LimiarDegradYears_"	
	model.componentDEGRAD.attrLimiarDegradLoss = model.componentDEGRAD.name.."LimiarDegradLoss_"	
	
end	

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentDEGRAD_initCellAverComponentValues (cell, model)
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

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentDEGRAD_verify (model)
  if (model.componentDEGRAD.name == nil)
  then error ("Missing DEGRAD parameter: name", 5) end

  if (model.componentDEGRAD.description == nil)
	then error ("Missing DEGRAD parameter: description", 5) end

	if (model.componentDEGRAD.averAGB_loss == nil)
	then error ("Missing DEGRAD parameter: averAGB_loss", 5) end
  
  if (model.componentDEGRAD.averBGB_loss == nil)
	then error ("Missing DEGRAD parameter: averBGB_loss", 5) end
	
	if (model.componentDEGRAD.averDeadWood_loss == nil)
	then error ("Missing DEGRAD parameter: averDeadWood_loss", 5) end
	
	if (model.componentDEGRAD.averLitter_loss == nil)
	then error ("Missing DEGRAD parameter: averLitter_loss", 5) end
  	
	if (model.componentDEGRAD.averPeriodRegrow == nil)
	then error ("Missing DEGRAD parameter: averPeriodRegrow", 5) end
	
	if (model.componentDEGRAD.averLimiarDegradYears == nil)
	then error ("Missing DEGRAD parameter: averLimiarDegradYears", 5) end
	
	if (model.componentDEGRAD.averLimiarDegradLoss == nil)
	then error ("Missing DEGRAD parameter: averLimiarDegradLoss", 5) end
	

	return true
end

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentDEGRAD_loadFromDB (model, cell_temp, cell, y)

  if cell_temp[model.componentDEGRAD.attrAGB_loss..y] ~= nil then
    cell.DEGRAD_AGB_loss 	= cell_temp[model.componentDEGRAD.attrAGB_loss..y]
  end

  if cell_temp[model.componentDEGRAD.attrBGB_loss..y] ~= nil then
    cell.DEGRAD_BGB_loss 	= cell_temp[model.componentDEGRAD.attrBGB_loss..y]
  end
  
 
  if cell_temp[model.componentDEGRAD.attrLitter_loss..y] ~= nil then
    cell.DEGRAD_Litter_loss 	= cell_temp[model.componentDEGRAD.attrLitter_loss..y]
  end
  
 
  if cell_temp[model.componentDEGRAD.attrDeadWood_loss..y] ~= nil then
    cell.DEGRAD_DeadWood_loss 	= cell_temp[model.componentDEGRAD.attrDeadWood_loss..y]
  end
 
  if cell_temp["Degrad"..y] ~= nil then
    cell.DEGRAD_Degrad 	= cell_temp["Degrad"..y]*model.cs.cellarea
  end
  
  if cell_temp[model.componentDEGRAD.PeriodRegrow] ~= nil then
    cell.DEGRAD_PeriodRegrow = cell_temp[model.componentDEGRAD.PeriodRegrow]
  end

  if cell_temp[model.componentDEGRAD.LimiarDegradYears] ~= nil then
    cell.DEGRAD_LimiarDegradYears = cell_temp[model.componentDEGRAD.LimiarDegradYears]
  end
  
  if cell_temp[model.componentDEGRAD.LimiarDegradLoss] ~= nil then
    cell.LimiarDegradLoss = cell_temp[model.componentDEGRAD.LimiarDegradLoss]
  end
  
end

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentDEGRAD_loadFromTable (model, cell, step)
 
  if (model.dataTable.AGB_loss ~= nil) then
    if (#model.dataTable.AGB_loss < step) then
      error ("Time required exceeds the input table size: AGB loss", 5) 
    end
    cell.DEGRAD_AGB_loss = model.dataTable.AGB_loss [step]
  end

  if (model.dataTable.BGB_loss ~= nil) then
    if (#model.dataTable.BGB_loss < step) then
      error ("Time required exceeds the input table size: BGB loss", 5) 
    end
    cell.DEGRAD_BGB_loss = model.dataTable.BGB_loss [step]
  end

  if (model.dataTable.Litter_loss ~= nil) then
    if (#model.dataTable.Litter_loss < step) then
      error ("Time required exceeds the input table size: Litter loss", 5) 
    end
    cell.DEGRAD_Litter_loss = model.dataTable.Litter_loss [step]
  end

  if (model.dataTable.DeadWood_loss ~= nil) then
    if (#model.dataTable.DeadWood_loss < step) then
      error ("Time required exceeds the input table size: Dead Wood loss", 5) 
    end
    cell.DEGRAD_DeadWood_loss = model.dataTable.DeadWood_loss [step]
  end

  if (model.dataTable.Degrad ~= nil) then
    if (#model.dataTable.Degrad < step) then
      error ("Time required exceeds the input table size: Degrad", 5) 
    end
    cell.DEGRAD_Degrad = model.dataTable.Degrad [step]
    

  end
  
  if (model.dataTable.PeriodRegrow ~= nil) then
    if (#model.dataTable.PeriodRegrow < step) then
      error ("Time required exceeds the input table size: PeriodRegrow", 5) 
    end
    cell.DEGRAD_PeriodRegrow = model.dataTable.PeriodRegrow [step]
  end
  
   if (model.dataTable.LimiarDegradYears ~= nil) then
    if (#model.dataTable.LimiarDegradYears < step) then
      error ("Time required exceeds the input table size: LimiarDegradYears", 5) 
    end
    cell.DEGRAD_LimiarDegradYears = model.dataTable.LimiarDegradYears [step]
  end
  
   if (model.dataTable.LimiarDegradLoss ~= nil) then
    if (#model.dataTable.LimiarDegradLoss < step) then
      error ("Time required exceeds the input table size: LimiarDegradLoss", 5) 
    end
    cell.DEGRAD_LimiarDegradLoss = model.dataTable.LimiarDegradLoss [step]
  end
  
end
 