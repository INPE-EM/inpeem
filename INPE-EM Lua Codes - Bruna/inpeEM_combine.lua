------------------------------------------------------------------------------------------- 
-- Functions in this file (inpeEM_combine.lua)
------------------------------------------------------------------------------------------- 
--  function inpeEM_executeCombine (model_out, model_ns, model_s)

-- function inpeEM_combineResultsNET (model_ns,  model_s)
-- function inpeEM_combineResultsVR (model_ns,  model_s)
-- function inpeEM_combineResultsSV (model_ns,  model_s)
-- function inpeEM_combineResultsD  (model_ns,  model_s)

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function inpeEM_executeCombine (model_out, model_ns, model_s)
	
 
    if (model_out == nil) then 
		error ("No output model defined!")
    end
    
    -- Execute non-spatial and spatial submodels

	if (model_ns == nil or model_s == nil) then 
		error ("Please, define and execute your models before combining them!")
    end
    print ("\nExecuting non-spatial mode...")
    if (model_ns.run ~= true) then inpeEM_execute (model_ns) end
  
    print ("\nExecuting spatial mode...")

    if (model_s.run ~= true) then inpeEM_execute (model_s) end
    
     
	if (model_ns.SV_flag == false or model_s.SV_flag == false) 
	and (model_s.VR_flag == false or model_s.VR_flag == false )
	and (model_s.DEGRAD_flag == false or model_s.DEGRAD_flag == false ) then 
		error ("No model PF or SF or DEGRAD model results to combine!")
    end
	   
    
    if (model_out.verbose == nil) then model_out.verbose = false end
    if (model_out.verbose ~= true and model_out.verbose ~= false) then
    		error ("Combine model verbose must be true or false!")
    end

    
    model_out.componentD = model_s.componentD
    model_out.componentB = model_s.componentB
    model_out.componentSV = model_s.componentSV
    model_out.componentDEGRAD = model_s.componentDEGRAD
    model_out.componentVR = model_s.componentVR
    model_out.yearInit = model_ns.yearInit
    model_out.yearFinal = model_s.yearFinal
    inpeEM_initResults (model_out)

    
    print ("\nCombining spatial and non-spatial results...")     io.flush()

	if (model_ns.SV_flag and model_s.SV_flag) then 
		model_out.SV_result = inpeEM_combineResultsSV (model_ns,  model_s)
		model_out.SV_flag = true
    else
        model_out.SV_flag = false  
    end 
        
    if (model_ns.VR_flag and model_s.VR_flag) then 
	       model_out.VR_result = inpeEM_combineResultsVR (model_ns,  model_s)
	       model_out.VR_flag = true
    else
        model_out.VR_flag = false  
    end 
      
    
    if (model_ns.DEGRAD_flag and model_s.DEGRAD_flag) then 
	       model_out.DEGRAD_result = inpeEM_combineResultsDEGRAD (model_ns,  model_s)
	       model_out.DEGRAD_flag = true
    else
        model_out.DEGRAD_flag = false  
    end 
  
    
   model_out.net_result = inpeEM_combineResultsNET (model_ns,model_s )
   

   model_out.D_result = inpeEM_combine_D (model_ns,model_s )

end
  

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 


------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function inpeEM_combineResultsVR (model_ns,  model_s)
           VR_result = {}
		   for y = model_ns.yearInit, model_s.yearInit - 1, 1 do

                VR_result[y] = 
		        {
				         VR_CO2_1stOrder = model_ns.VR_result[y].VR_CO2_1stOrder,
		   	             VR_CO2_2ndOrder = model_ns.VR_result[y].VR_CO2_2ndOrder,
		  	             VR_CO2_2ndOrder_fire = model_ns.VR_result[y].VR_CO2_2ndOrder_fire,
		   	             VR_CO2_2ndOrder_decay = model_ns.VR_result[y].VR_CO2_2ndOrder_decay,
		                 VR_CH4_CO2Eq_2ndOrder_fire = model_ns.VR_result[y].VR_CH4_CO2Eq_2ndOrder_fire,
			    	     VR_N2O_CO2Eq_2ndOrder_fire = model_ns.VR_result[y].VR_N2O_CO2Eq_2ndOrder_fire,
			    	     VR_CO_CO2Eq_2ndOrder_fire = model_ns.VR_result[y].VR_CO_CO2Eq_2ndOrder_fire,
			    	     VR_NOx_CO2Eq_2ndOrder_fire = model_ns.VR_result[y].VR_NOx_CO2Eq_2ndOrder_fire
                 }
          end
    
		for y = model_s.yearInit, model_s.yearFinal, 1 do

			   VR_result[y] = 
		        {
					  VR_CO2_1stOrder = model_ns.VR_result[y].VR_CO2_1stOrder + model_s.VR_result[y].VR_CO2_1stOrder  ,
		   	          VR_CO2_2ndOrder = model_ns.VR_result[y].VR_CO2_2ndOrder + model_s.VR_result[y].VR_CO2_2ndOrder ,
		  	          VR_CO2_2ndOrder_fire = model_ns.VR_result[y].VR_CO2_2ndOrder_fire + model_s.VR_result[y].VR_CO2_2ndOrder_fire ,
		   	          VR_CO2_2ndOrder_decay = model_ns.VR_result[y].VR_CO2_2ndOrder_decay + model_s.VR_result[y].VR_CO2_2ndOrder_decay ,
		              VR_CH4_CO2Eq_2ndOrder_fire = model_ns.VR_result[y].VR_CH4_CO2Eq_2ndOrder_fire + model_s.VR_result[y].VR_CH4_CO2Eq_2ndOrder_fire ,
			    	  VR_N2O_CO2Eq_2ndOrder_fire = model_ns.VR_result[y].VR_N2O_CO2Eq_2ndOrder_fire + model_s.VR_result[y].VR_N2O_CO2Eq_2ndOrder_fire ,
			    	  VR_CO_CO2Eq_2ndOrder_fire  = model_ns.VR_result[y].VR_CO_CO2Eq_2ndOrder_fire  + model_s.VR_result[y].VR_CO_CO2Eq_2ndOrder_fire ,
			    	  VR_NOx_CO2Eq_2ndOrder_fire = model_ns.VR_result[y].VR_NOx_CO2Eq_2ndOrder_fire + model_s.VR_result[y].VR_NOx_CO2Eq_2ndOrder_fire 
              }
		end
	    return VR_result
	    
end


------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function inpeEM_combineResultsSV (model_ns,  model_s)
           SV_result = {}
		   for y = model_ns.yearInit, model_s.yearInit - 1, 1 do

                SV_result[y] = 
		        {
				         SV_area_total = model_ns.SV_result[y].SV_area_total,
				         SV_area_cleared = model_ns.SV_result[y].SV_area_cleared,
		   	             SV_CO2_emission = model_ns.SV_result[y].SV_CO2_emission,
		  	             SV_CO2_absorption = model_ns.SV_result[y].SV_CO2_absorption,
                 }
          end
    
		for y = model_s.yearInit, model_s.yearFinal, 1 do

			   SV_result[y] = 
		        {
					  SV_area_total = model_s.SV_result[y].SV_area_total  ,
					  SV_area_cleared = model_ns.SV_result[y].SV_area_cleared + model_s.SV_result[y].SV_area_cleared  ,
		   	          SV_CO2_emission = model_ns.SV_result[y].SV_CO2_emission + model_s.SV_result[y].SV_CO2_emission ,
		  	          SV_CO2_absorption = model_ns.SV_result[y].SV_CO2_absorption + model_s.SV_result[y].SV_CO2_absorption ,
              }
		end
	    return SV_result
	    
end

function inpeEM_combineResultsDEGRAD (model_ns,  model_s)


           DEGRAD_result = {}
		   for y = model_ns.yearInit, model_s.yearInit - 1, 1 do

                DEGRAD_result[y] = 
		        {
		        		 DEGRAD_Area      = model_ns.DEGRAD_result[y].DEGRAD_Area,
		        		 DEGRAD_AveLoss      = model_ns.DEGRAD_result[y].DEGRAD_AveLoss,
				         
		   	             DEGRAD_CO2_emission = model_ns.DEGRAD_result[y].DEGRAD_CO2_emission,
		  	             DEGRAD_CO2_absorption = model_ns.DEGRAD_result[y].DEGRAD_CO2_absorption,
		  	              DEGRAD_CO2_emission_aboveDegradLimiar = model_ns.DEGRAD_result[y].DEGRAD_CO2_emission_aboveDegradLimiar,
		  	             DEGRAD_CO2_absorption_aboveDegradLimiar = model_ns.DEGRAD_result[y].DEGRAD_CO2_absorption_aboveDegradLimiar,
		  	             DEGRAD_CO2_BALANCE = model_ns.DEGRAD_result[y].DEGRAD_CO2_BALANCE,
		  	             DEGRAD_CO2_BALANCE2 = model_ns.DEGRAD_result[y].DEGRAD_CO2_BALANCE2,
                 }
          end
    
		for y = model_s.yearInit, model_s.yearFinal, 1 do

			   DEGRAD_result[y] = 
		        {
		        	 --[[ DEGRAD_Area      = model_ns.DEGRAD_result[y].DEGRAD_Area + model_s.DEGRAD_result[y].DEGRAD_Area ,
		        		 DEGRAD_AveLoss      = model_s.DEGRAD_result[y].DEGRAD_AveLoss,
		   	          DEGRAD_CO2_emission   = model_ns.DEGRAD_result[y].DEGRAD_CO2_emission + model_s.DEGRAD_result[y].DEGRAD_CO2_emission ,
		  	          DEGRAD_CO2_absorption = model_ns.DEGRAD_result[y].DEGRAD_CO2_absorption + model_s.DEGRAD_result[y].DEGRAD_CO2_absorption ,
                      DEGRAD_CO2_emission_aboveDegradLimiar = model_ns.DEGRAD_result[y].DEGRAD_CO2_emission_aboveDegradLimiar + model_s.DEGRAD_result[y].DEGRAD_CO2_emission_aboveDegradLimiar,
		  	          DEGRAD_CO2_absorption_aboveDegradLimiar = model_ns.DEGRAD_result[y].DEGRAD_CO2_absorption_aboveDegradLimiar + model_s.DEGRAD_result[y].DEGRAD_CO2_absorption_aboveDegradLimiar,
		  	          DEGRAD_CO2_BALANCE = model_ns.DEGRAD_result[y].DEGRAD_CO2_BALANCE + model_s.DEGRAD_result[y].DEGRAD_CO2_BALANCE,
		  	          DEGRAD_CO2_BALANCE2 = model_ns.DEGRAD_result[y].DEGRAD_CO2_BALANCE2 + model_s.DEGRAD_result[y].DEGRAD_CO2_BALANCE2,             
		  	      }
		  	        --]] 
		  	    
		  	    DEGRAD_Area      = model_s.DEGRAD_result[y].DEGRAD_Area ,
		        		 DEGRAD_AveLoss    = model_s.DEGRAD_result[y].DEGRAD_AveLoss,
		   	          DEGRAD_CO2_emission   = model_s.DEGRAD_result[y].DEGRAD_CO2_emission ,
		  	          DEGRAD_CO2_absorption = model_s.DEGRAD_result[y].DEGRAD_CO2_absorption ,
                      DEGRAD_CO2_emission_aboveDegradLimiar = model_s.DEGRAD_result[y].DEGRAD_CO2_emission_aboveDegradLimiar,
		  	          DEGRAD_CO2_absorption_aboveDegradLimiar = model_s.DEGRAD_result[y].DEGRAD_CO2_absorption_aboveDegradLimiar ,
		  	          DEGRAD_CO2_BALANCE = model_s.DEGRAD_result[y].DEGRAD_CO2_BALANCE ,
		  	          DEGRAD_CO2_BALANCE2 = model_s.DEGRAD_result[y].DEGRAD_CO2_BALANCE2 
		  	          
		  	          }
		end
	    return DEGRAD_result
	    
end
------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function inpeEM_combineResultsNET (model_ns,  model_s)
           net_result = {}
		   for y = model_ns.yearInit, model_s.yearInit - 1, 1 do

                net_result[y] = 
		        {
			            net_CO2_1stOrder =  model_ns.net_result[y].net_CO2_1stOrder,
			            net_CO2_2ndOrder =  model_ns.net_result[y].net_CO2_2ndOrder,
			    }

          end
    
		for y = model_s.yearInit, model_s.yearFinal, 1 do

			   net_result[y] = 
		        {
		        
		        	    net_CO2_1stOrder =  model_ns.net_result[y].net_CO2_1stOrder + model_s.net_result[y].net_CO2_1stOrder,
			            net_CO2_2ndOrder =  model_ns.net_result[y].net_CO2_2ndOrder + model_s.net_result[y].net_CO2_2ndOrder,

              }
		end
	    return net_result
	    
end


----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------
function inpeEM_combine_D (model_ns,  model_s)
    D_result = {}
	for y = model_ns.yearInit, model_s.yearInit - 1, 1 do

			D_result[y] = 
			{
				    D_Area = model_ns.D_result[y].D_Area,
				    D_AreaAcc = model_ns.D_result[y].D_AreaAcc,
		
			}
	end
			
	for y = model_s.yearInit, model_s.yearFinal, 1 do

		  	D_result[y] = 
			{
				    D_Area 			=  model_s.D_result[y].D_Area,
				    D_AreaAcc 		=  model_s.D_result[y].D_AreaAcc,
				}
		end
	    return D_result
	    
end

