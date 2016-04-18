dofile(PROJECTDIR.."inpe_EM_2_0_1\\inpeEM_combine.lua")
dofile(PROJECTDIR.."inpe_EM_2_0_1\\inpeEM_componentDEGRAD.lua")
dofile(PROJECTDIR.."inpe_EM_2_0_1\\inpeEM_componentVR.lua")
dofile(PROJECTDIR.."inpe_EM_2_0_1\\inpeEM_componentSV.lua")
dofile(PROJECTDIR.."inpe_EM_2_0_1\\inpeEM_general.lua")

------------------------------------------------------------------------------------------- 
-- Functions in this file (inpeEM.lua)
------------------------------------------------------------------------------------------- 
-- function inpeEM_execute (model)  

-- function inpeEM_init (model)
-- function inpeEM_initComponents (model)
-- function inpeEM_initResults (model)


-- function inpeEM_load (year, model)
-- function inpeEM_loadFromTable (year, model)
-- function inpeEM_loadFromDB (year, model)

-- function inpeEM_computeNetEmission (year, model)

-- function inpeEM_printReport (model)
-- function inpeEM_saveCells (model, component)

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function inpeEM_execute (model)  
    if (model.mode == "combine") then  -- spatial and non-spatial model: recursive
        inpeEM_executeCombine (model, model.model_ns, model.model_s) 
    else   
	    inpeEM_init (model)
		for year= model.yearInit, model.yearFinal, 1 do
		             inpeEM_load (year, model)
		             if (model.DEGRAD_flag)then componentDEGRAD_execute(year, model) end
		             if (model.SV_flag)then componentSV_execute (year, model) end
		             if (model.VR_flag)then componentVR_execute (year, model) end
		             inpeEM_computeNetEmission (year, model)
		end  
	
	end
	
	model.run = true
 	if (model.verbose == true) then
		 inpeEM_printReport (model) 
	end
	
	if (model.mode == "spatial") then
			  if (model.DEGRAD_flag) then inpeEM_saveCells (model, model.componentDEGRAD) end
	          if (model.VR_flag) then inpeEM_saveCells (model, model.componentVR) end
	          if (model.SV_flag) then inpeEM_saveCells (model, model.componentSV) end	
	end
end
 
------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function inpeEM_init (model)
  error_flag = false
  
  if (model.verbose == nil) then model.verbose = false end
  
  if (model.verbose ~= true and model.verbose ~= false) then
  		error ("Combine model verbose must be true or false!")
  end
  
  if model.componentD == nil then
  	print ("\nModel definition error: componentD (disturbance)  missing")
  	error_flag = true
  else componentD_verify (model) end
	
	if model.componentB == nil then
		print ("\nModel definition error: componentB (biomass)  missing")
		error_flag = true
	else componentB_verify (model) end
	
	model.DEGRAD_flag = true --TOA
	if model.componentDEGRAD == nil then --TOA
		model.DEGRAD_flag = false --TOA
		componentDEGRAD_createNullComponent (model) --TOA
	else componentDEGRAD_verify (model) end --TOA
	
	model.VR_flag = true
	if model.componentVR == nil then
		model.VR_flag = false
		componentVR_createNullComponent (model)
	else componentVR_verify (model) end

	model.SV_flag = true
	if model.componentSV == nil then
		model.SV_flag = false
		componentSV_createNullComponent (model)
	else componentSV_verify (model) end
	
	if (model.SV_flag == false and model.VR_flag == false) and model.DEGRAD_flag == false then --TOA
		print ("\nModel definition error: componentVR AND/OR componentSV AND/OR componentDEGRAD must be defined")--TOA
		error_flag = true
  end
	
	if model.yearInit == nil then
		print ("\nModel definition error: initial year missing")
		error_flag = true
	end	 

  if model.yearFinal == nil then
		print ("\nModel definition error: initial year missing")
		error_flag = true
	end	 
    
  if model.yearInit > model.yearFinal then
    print ("\nModel definition error: initial year missing")
		error_flag = true
	end
				
  if model.mode == nil then
		print ("\nModel definition error: mode (spatial or non-spatial) missing")
		error_flag = true
	end	 
 
	if error_flag then
		error("\n    Please, complete your model definition before executing!")
	end
	
	error_flag = false
	
	if (model.mode == "spatial") then
	     if (model.databasePathName == nil or  model.inputThemeName == nil) then
				print ("\nModel definition error: database and base_theme missing")
				error_flag = true
	     else 
	       model.cs = CellularSpace{  dbType = model.dbtype,
            									    	host = model.host,
              											user = model.user,
              											password = model.password,
              											database = model.databasePathName, 
              											theme = model.inputThemeName,
              											cellarea = model.cellarea
            										  } 
            										  
				 model.cs_temp = CellularSpace{ dbType = model.dbtype,
                									    	host = model.host,
                  											user = model.user,
                  											password = model.password,
                  											database = model.databasePathName, 
                  											theme = model.inputThemeName,
                  											cellarea = model.cellarea
                                      }
	     end 
	end
		
	if (model.mode == "non_spatial") then
	     if (model.dataTable == nil) then
    			print ("\nModel definition error: dataTable missing")
    			error_flag = true
	     else
	     		model.cs = CellularSpace{xdim = 1,ydim = 1}
	     		model.cs.cellarea = model.area
	     		model.cs_temp = nil
	     		model.save = false
	     end
	     		
	end
	
  if error_flag then error("\nPlease, correct your database or file definition before executing!") end
	
  inpeEM_initResults (model)
  inpeEM_initComponents (model)
	
  io.flush()
end

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function inpeEM_initComponents (model)
  forEachCell(model.cs,function(cell)
    cell.D_Area = 0
    cell.D_AreaAcc = 0
    cell.D_NoData = 0
    cell.B_AGB = model.componentB.averAGB
    cell.B_ActualAGB = cell.B_AGB
    cell.B_BGBPercAGB = model.componentB.averBGBPercAGB
    cell.B_LitterPercAGB = model.componentB.averLitterPercAGB
    cell.B_DeadWoodPercAGB = model.componentB.averDeadWoodPercAGB
    cell.B_PercCarbon = model.componentB.averFactorB_C
    cell.B_FactorB_CO2 = model.componentB.averFactorB_CO2
    cell.B_FactorB_CO2_fire = model.componentB.averFactorB_CO2_fire
    cell.B_FactorB_CH4_fire = model.componentB.averFactorB_CH4_fire
    cell.B_FactorB_N2O_fire = model.componentB.averFactorB_N2O_fire
    cell.B_FactorB_NOx_fire = model.componentB.averFactorB_NOx_fire
    cell.B_FactorB_CO_fire  = model.componentB.averFactorB_CO_fire
  end)
	 
  model.componentD.attrArea = model.componentD.name.."_Area"
  model.componentD.attrInitialArea = model.componentD.name.."_InitialArea"
  model.componentD.attNoData = model.componentD.name.."_NoData"
  model.componentB.attrAGB = model.componentB.name.."_AGB"
  model.componentB.attrBGBPercAGB = model.componentB.name.."_BGBPercAGB"
  model.componentB.attrLitterPercAGB = model.componentB.name.."_LitterPercAGB"
  model.componentB.attrDeadWoodPercAGB = model.componentB.name.."_DeadWoodPercAGB"
  model.componentB.attrPercCarbon = model.componentB.name.."_PercCarbon"
  model.componentB.attrFactorB_CO2 = model.componentB.name.."_FactorB_CO2"
  model.componentB.attrFactorB_CO2_fire = model.componentB.name.."_FactorB_CO2_fire"
  model.componentB.attrFactorB_CH4_fire = model.componentB.name.."_FactorB_CH4_fire"
  model.componentB.attrFactorB_N2O_fire = model.componentB.name.."_FactorB_N2O_fire"
  model.componentB.attrFactorB_CO_fire = model.componentB.name.."_FactorB_CO_fire"
  model.componentB.attrFactorB_NOx_fire = model.componentB.name.."_FactorB_NOx_fire"

  if (model.DEGRAD_flag)then componentDEGRAD_init (model)end
  if (model.VR_flag)then componentVR_init (model)end
  if (model.SV_flag)then componentSV_init (model)end
  
end
 
----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function inpeEM_initResults (model)
  model.D_result = {}
  model.D_result_acc = 0
  model.DEGRAD_result = {}
  model.SV_result = {}
  model.VR_result = {}
  model.net_result = {}

  for y = model.yearInit, model.yearFinal, 1 do
    model.D_result[y] = { D_Area = 0,
                          D_AreaAcc = 0
                     
                        }
    	
    model.SV_result[y] = { SV_area_total = 0,
                           SV_area_cleared = 0,
                           SV_CO2_emission = 0,
                            SV_CO2_absorption =  0,
	                       }
	
	  model.VR_result[y] = { VR_CO2_1stOrder = 0,
             	             VR_CO2_2ndOrder = 0,
            	             VR_CO2_2ndOrder_fire = 0,
             	             VR_CO2_2ndOrder_decay = 0,
                           	 VR_CH4_CO2Eq_2ndOrder_fire = 0,
                    	     VR_N2O_CO2Eq_2ndOrder_fire = 0,
                    	     VR_CO_CO2Eq_2ndOrder_fire = 0,
                    	     VR_NOx_CO2Eq_2ndOrder_fire = 0
                         }
    
      model.DEGRAD_result[y] = { 
      						DEGRAD_Area = 0,
      						
      						DEGRAD_CO2_emission = 0,
             	            DEGRAD_CO2_absorption = 0,
             	            
             	            DEGRAD_CO2_emission_aboveDegradLimiar = 0,
             	            DEGRAD_CO2_absorption_aboveDegradLimiar = 0,
             	            
             	            DEGRAD_CO2_BALANCE = 0, 
							DEGRAD_CO2_BALANCE2 = 0,
							
							DEGRAD_AveLoss = 0,
             	            
                         }
                         
	  model.net_result[y] = {	net_CO2_1stOrder = 0,
		                        net_CO2_2ndOrder = 0,
		                        
	                        }
  end	
end

----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function inpeEM_load (year, model)
  --print (year, "loading...") io.flush()
  if (model.mode == "spatial") then
     inpeEM_loadFromDB (year, model)
  else
     inpeEM_loadFromTable (year, model)
  end
end        
 
----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function inpeEM_loadFromTable (year, model)
  local step = year - model.yearInit + 1
  local cell = model.cs.cells[1]
  
  if (year == model.yearInit) then
    cell.D_AreaAcc = model.componentD.initialArea
    model.D_result_acc = cell.D_AreaAcc 
    if (model.mode == "non_spatial") then
       cell.D_NoData = model.componentD.TotalNoData
   end
  end
  
  

		  
  if (model.dataTable.Area == nil) then
    error ("Input table error: Area data missing", 5) 
  end
	
  if (#model.dataTable.Area < step) then
   	error ("Time required exceeds the input table size: Area", 5) 
  end
	
  cell.D_Area = model.dataTable.Area [step]
	cell.D_AreaAcc = cell.D_AreaAcc + cell.D_Area
	
	model.D_result[year].D_Area = model.D_result[year].D_Area + cell.D_Area
	model.D_result_acc = model.D_result_acc + cell.D_Area
 	model.D_result[year].D_AreaAcc = model.D_result_acc
 	
  if (model.DEGRAD_flag) then componentDEGRAD_loadFromTable (model, cell, step) end
  if (model.VR_flag) then componentVR_loadFromTable (model, cell, step) end
  if (model.SV_flag) then componentSV_loadFromTable (model, cell, step) end
end 
 
----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function inpeEM_loadFromDB (year, model) 
  -- initial year only
  local flagPrintAGB = true
  local flagPrintBGBPercAGB = true
  local flagPrintLitterPercAGB = true
  local flagPrintDeadWoodPercAGB = true
	    
  if (year == model.yearInit) then
    forEachCellPair(model.cs,model.cs_temp,function(cell,cell_temp)
  	  if cell_temp[model.componentD.attrInitialArea] ~= nil then
  		   cell.D_AreaAcc = cell_temp[model.componentD.attrInitialArea]
  		   model.D_result_acc = model.D_result_acc + cell.D_AreaAcc 
  	  else
  	     error ("Historical disturbance information missing: "..model.componentD.attrInitialArea)	
     end
    	
    	if cell_temp[model.componentD.attNoData] ~= nil then
  		   cell.D_NoData = cell_temp[model.componentD.attNoData]
  	  else
  	     error ("No data information missing: "..model.componentD.attNoData)	
       end
  	         
    	if cell_temp[model.componentB.attrAGB] ~= nil then
    		 cell.B_AGB = cell_temp[model.componentB.attrAGB]
    		 cell.B_ActualAGB = cell.B_AGB
    		 if (flagPrintAGB) then print (year,"Loading "..model.componentB.attrAGB) flagPrintAGB = false end
	    end 
  	
    	if cell_temp[model.componentB.attrBGBPercAGB] ~= nil then
    		 cell.B_BGBPercAGB = cell_temp[model.componentB.attrBGBPercAGB]
    		 if (flagPrintBGBPercAGB) then print (year,"Loading "..model.componentB.attrBGBPercAGB) flagPrintBGBPercAGB = false end
    	end 
  	
    	if cell_temp[model.componentB.attrLitterPercAGB] ~= nil then
		     cell.B_LitterPercAGB = cell_temp[model.componentB.attrLitterPercAGB]
		     if (flagPrintLitterPercAGB) then print (year,"Loading "..model.componentB.attrLitterPercAGB) flagPrintLitterPercAGB = false end
    	end 
  	
  	  if cell_temp[model.componentB.attrDeadWoodPercAGB] ~= nil then
  		   cell.B_DeadWoodPercAGB = cell_temp[model.componentB.attrDeadWoodPercAGB]
  		   if (flagPrintDeadWoodPercAGB) then print (year,"Loading "..model.componentB.attrDeadWoodPercAGB) flagPrintDeadWoodPercAGB = false end
			end 
  			
			if cell_temp[model.componentB.attrPercCarbon] ~= nil then
		     cell.B_PercCarbon = cell_temp[model.componentB.attrPercCarbon]
			end 
  			
			if cell_temp[model.componentB.attrFactorB_CO2] ~= nil then
		     cell.B_FactorB_CO2 = cell_temp[model.componentB.attrFactorB_CO2]
			end 
				
			if cell_temp[model.componentB.attrFactorB_CO2_fire] ~= nil then
		     cell.B_FactorB_CO2_fire = cell_temp[model.componentB.attrFactorB_CO2_fire]
			end 
				
			if cell_temp[model.componentB.attrFactorB_CH4_fire] ~= nil then
		     cell.B_FactorB_CH4_fire = cell_temp[model.componentB.attrFactorB_CH4_fire]
			end 

			if cell_temp[model.componentB.attrFactorB_N2O_fire] ~= nil then
		     cell.B_FactorB_N2O_fire = cell_temp[model.componentB.attrFactorB_N2O_fire]
			end 

			if cell_temp[model.componentB.attrFactorB_CO_fire] ~= nil then
  	     cell.B_FactorB_CO_fire = cell_temp[model.componentB.attrFactorB_CO_fire]
			end 

			if cell_temp[model.componentB.attrFactorB_NOx_fire] ~= nil then
		     cell.B_FactorB_NOx_fire = cell_temp[model.componentB.attrFactorB_NOx_fire]
			end 
  	end)
  end	
	
	--spatio-temporal attributes
  flagPrintAreaPercVegSec = true
  flagPrintHalfLife = true

  forEachCellPair(model.cs,model.cs_temp,function(cell,cell_temp)
		   if cell_temp[model.componentD.attrArea..year] ~= nil then
 		      cell.D_Area = cell_temp[model.componentD.attrArea..year]
 		      cell.D_AreaAcc = cell.D_AreaAcc + cell.D_Area
          model.D_result[year].D_Area = model.D_result[year].D_Area + cell.D_Area
          model.D_result_acc = model.D_result_acc + cell.D_Area
          model.D_result[year].D_AreaAcc =  model.D_result_acc
 		   else
 		      error ("Disturbance information missing: "..model.componentD.attrArea)
       end
       
       if (model.DEGRAD_flag)then componentDEGRAD_loadFromDB (model, cell_temp, cell, year) end
	   if (model.VR_flag)then componentVR_loadFromDB (model, cell_temp, cell, year) end
       if (model.SV_flag)then componentSV_loadFromDB (model, cell_temp, cell, year) end
		end)
end -- function
  
----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function inpeEM_computeNetEmission (year, model)
  if (model.verbose) then print (year, "Executing NET - mode:"..model.mode) end
  
  for y = model.yearInit, model.yearFinal, 1 do
  	--model.net_result[y].net_CO2_2ndOrder = model.VR_result[y].VR_CO2_2ndOrder + model.SV_result[y].SV_CO2_emission - model.SV_result[y].SV_CO2_absorption
  	--model.net_result[y].net_CO2_1stOrder = model.VR_result[y].VR_CO2_1stOrder + model.SV_result[y].SV_CO2_emission - model.SV_result[y].SV_CO2_absorption
  	
  	model.net_result[y].net_CO2_2ndOrder = model.VR_result[y].VR_CO2_2ndOrder  
  	                                       + model.SV_result[y].SV_CO2_emission 
  	                                       - model.SV_result[y].SV_CO2_absorption 
  	                                       + model.DEGRAD_result[y].DEGRAD_CO2_emission
  	                                       - model.DEGRAD_result[y].DEGRAD_CO2_absorption
  	                                      
--[[	model.net_result[y].net_CO2_2ndOrder_aboveDegradLimiar = model.VR_result[y].VR_CO2_2ndOrder  
  	                                       			 + model.SV_result[y].SV_CO2_emission 
  	                                       			 - model.SV_result[y].SV_CO2_absorption 
  	                                       			 + model.DEGRAD_result[y].DEGRAD_CO2_emission_aboveDegradLimiar
  	                                       			 - model.DEGRAD_result[y].DEGRAD_CO2_absorption_aboveDegradLimiar  	                                     
  	--]]										
   model.net_result[y].net_CO2_1stOrder = model.VR_result[y].VR_CO2_1stOrder 
  										   + model.SV_result[y].SV_CO2_emission 
  										   - model.SV_result[y].SV_CO2_absorption
  										   + model.DEGRAD_result[y].DEGRAD_CO2_emission
  	                                       - model.DEGRAD_result[y].DEGRAD_CO2_absorption
  	                                       
--[[	model.net_result[y].net_CO2_1stOrder_aboveDegradLimiar = model.VR_result[y].VR_CO2_1stOrder 
  										   			 + model.SV_result[y].SV_CO2_emission 
  										   			 - model.SV_result[y].SV_CO2_absorption
  										   			 + model.DEGRAD_result[y].DEGRAD_CO2_emission_aboveDegradLimiar
  	                                       			 - model.DEGRAD_result[y].DEGRAD_CO2_absorption_aboveDegradLimiar
  	            --]]                           
  end
end

----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function inpeEM_saveCells (model, component) 
  if (component.saveCount > 0)  then
    local name = model.inputThemeName.."_"..component.name.."_"..model.yearInit.."_"
    if (component.saveCount < 300) then 
      model.cs:save(model.yearFinal,name, component.saveAttrs) 
    else 
      print ("Sorry, number of attributes > 300, impossible to save, run with a shorter time period")
      io.flush()
    end
  end
end

----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function inpeEM_printReport (model)

  print ("\n_____________________________________________________________________________________________________________________________________")
  print ("\nINPE-EM TOTAL RESULTS")
  print ("\n_____________________________________________________________________________________________________________________________________")
  print ("      MODEL NAME = "..model.name)
  print ("      MODEL MODE = "..model.mode)
  print ("      SUBMODELS",  "B = ", model.componentB.name,"D  = ", model.componentD.name, "VR = ", model.componentVR.name, "SV = ", model.componentSV.name, "Degrad = ", model.componentDEGRAD.name)
  print ("_____________________________________________________________________________________________________________________________________")
  
  print ("\n    ", "D_AreaAcc", "D_Area", "DEGRAD_Area",
           "   -  ", 
           "      ", "VR_CO2_1stOrder", "VR_CO2_2ndOrder", "SV_CO2_emission", "SV_CO2_absorption",   
           "   -  ", 
           "      ", "DEGRAD_CO2_emission", "DEGRAD_CO2_absorption",  "DEGRAD_CO2_emission_aboveLimiar", "DEGRAD_CO2_absorption_aboveLimiar", "Percentage Loss",
           "   -  ", 
           "       ", "NET_1st_Order", "NET_2nd_Order")
  
  

   io.flush()
   
   for y = model.yearInit, model.yearFinal, 1 do
  	
     a = math.floor (model.D_result[y].D_Area)        
     b = math.floor (model.D_result[y].D_AreaAcc)        
     b1 = math.floor (model.DEGRAD_result[y].DEGRAD_Area)        
     c = math.floor (model.VR_result[y].VR_CO2_1stOrder/1000000)
     d = math.floor (model.VR_result[y].VR_CO2_2ndOrder/1000000)
     e = math.floor (model.VR_result[y].VR_CO2_2ndOrder_fire/1000000)
     f = math.floor (model.VR_result[y].VR_CO2_2ndOrder_decay/1000000)
     g = math.floor (model.VR_result[y].VR_CH4_CO2Eq_2ndOrder_fire/1000000)
     h = math.floor (model.VR_result[y].VR_N2O_CO2Eq_2ndOrder_fire/1000000)
     k1 = math.floor (model.SV_result[y].SV_area_total)  --km2 ANAP
     k = math.floor (model.SV_result[y].SV_area_cleared)  --km2 ANAP
     l = math.floor (model.SV_result[y].SV_CO2_emission/1000000)
     m = math.floor ( model.SV_result[y].SV_CO2_absorption/1000000)*(-1) 
     
     p = math.floor (model.DEGRAD_result[y].DEGRAD_CO2_emission/1000000) 
     q = math.floor (model.DEGRAD_result[y].DEGRAD_CO2_absorption/1000000)*(-1)
     
     o = math.floor (model.net_result[y].net_CO2_2ndOrder/1000000)
     r = math.floor (model.net_result[y].net_CO2_1stOrder/1000000)
     
     s = math.floor (model.DEGRAD_result[y].DEGRAD_CO2_emission_aboveDegradLimiar/1000000)
     t = math.floor (model.DEGRAD_result[y].DEGRAD_CO2_absorption_aboveDegradLimiar/1000000)*(-1)
     
     u = math.floor (model.DEGRAD_result[y].DEGRAD_CO2_BALANCE/1000000)
     
     u2 = math.floor (model.DEGRAD_result[y].DEGRAD_AveLoss*1000)
   
   --  o1 = math.floor (model.net_result[y].net_CO2_2ndOrder_aboveDegradLimiar/1000000)
    -- r1 = math.floor (model.net_result[y].net_CO2_1stOrder_aboveDegradLimiar/1000000)
                 
    print (y,   b, a, b1,"   -   ",  y, c, d, l, m, "   -   ", y,  p, q, s, t, u2, "   -   ",  r, o)    

        io.flush()
    end -- for
 
   print ("\n(OBS: area in hecatares, CO2 in MtonCO2(= 10 12 g), other gases in CO2Eq)")
end

----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------   
function componentD_verify (model)
  if (model.componentD.name == nil)
  then error ("Missing D parameter: name", 5) end
  
  if (model.componentB.description == nil)
  then error ("Missing D parameter: description", 5) end
  
  if (model.componentD.initialArea == nil)
  then error ("Missing D parameter: initialArea", 5) end
   
  return true
end	  	 
	  	 
----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function componentB_verify (model)
  if (model.componentB.name == nil)
  then error ("Missing B parameter: name", 5) end
   
  if (model.componentB.description == nil)
  then error ("Missing B parameter: description", 5) end
  
  if (model.componentB.averBGBPercAGB == nil)
  then error ("Missing B parameter: averBGBPercAGB", 5) end
   
  if (model.componentB.averLitterPercAGB == nil)
  then error ("Missing B parameter: averLitterPercAGB", 5) end
  
  if (model.componentB.averDeadWoodPercAGB == nil)
  then error ("Missing B parameter: averDeadWoodPercAGB", 5) end
   
  if (model.componentB.averFactorB_C == nil)
  then error ("Missing B parameter: averFactorB_C", 5) end
   
  if (model.componentB.averFactorB_CO2 == nil)
  then error ("Missing B parameter: averFactorB_CO2", 5) end
   
  if (model.componentB.averFactorB_CO2_fire == nil)
  then error ("Missing B parameter: averFactorB_CO2_fire", 5) end
   
  if (model.componentB.averFactorB_CH4_fire == nil)
  then error ("Missing B parameter: averFactorB_CH4_fire", 5) end
   
  if (model.componentB.averFactorB_N2O_fire == nil)
  then error ("Missing B parameter: averFactorB_N2O_fire", 5) end
  
  if (model.componentB.averFactorB_NOx_fire == nil)
  then error ("Missing B parameter: averFactorB_NOx_fire", 5) end
   
  if (model.componentB.averFactorB_CO_fire == nil)
  then error ("Missing B parameter: averFactorB_CO_fire", 5) end
   
  return true
end