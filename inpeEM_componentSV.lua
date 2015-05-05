--INPE-EM - A spatially explicit GHG emission modeling framework for land use/land cover change processes
--Copyright © 2014 INPE.
--
--This code is part of the INPE-EM framework.
--This framework is a free software; you can redistribute and/or
--modify it under the terms of the GNU Lesser General Public
--License as published by the Free Software Foundation; either
--version 3 of the License, or (at your option) any later version.
--
--You should have received a copy of the GNU Lesser General Public
--License along with this library.
--
--The authors reassure the license terms regarding the warranties.
--They specifically disclaim any warranties, including, but not limited to,
--the implied warranties of merchantability and fitness for a particular purpose.
--The framework provided hereunder is on an "as is" basis, and the authors have no
--obligation to provide maintenance, support, updates, enhancements, or modifications.
--In no event shall INPE be held liable to any part for direct,
--indirect, special, incidental, or consequential damages arising out of the use
--of this library and its documentation.
--
-------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------
--- INPE-EM Framework: inpeEM_componentSV.lua (Secondary Vegetation submodel is not available in this version)
--  Author: Ana Paula Aguiar
--  Date (last update): 24 October 2014

------------------------------------------------------------------------------------------- 
-- Functions in this file (inpeEM_componentSV.lua)
------------------------------------------------------------------------------------------- 
-- function componentSV_execute (model, year)


-- function componentSV_createNullComponent (model)
-- function componentSV_init (cell, model)
-- function componentSV_initCellAverComponentValues (cell, model)
-- function componentSV_initCellAttrNames (cell, model, year)

-- function componentSV_loadFromTable
-- function componentSV_loadFromDB


------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------
function componentSV_execute (year, model)
             
end


------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentSV_createNullComponent (model)
if model ~= nil then
	model.componentSV = 
	{
			name = "undefined",
			description = "",
			averAreaPercVegSec = 0,
			averAreaAccPercVegSec  = 0,
			averAgriculturalUseCycle = 0,
						       
			averRecoveryPeriod1Perc  = 0,
		    averRecoveryPeriod1  = 0, -- years
			averRecoveryPeriod2Perc  = 0, 
			averRecoveryPeriod2  = 0, --years,
						       
			averInitialAbandonmentCycle = 0,
			averHalfLife = 0,
			averBGBpercBGB = 0
			}
				
    end
end

 
function componentSV_init (model)
          
    -- init output attributes
    model.componentSV.saveAttrs = {}
    model.componentSV.saveCount = 0
    model.componentSV.attrOutAreaVS 			    = model.componentSV.name.."_OutAreaVS"
	model.componentSV.attrOutAreaAGR 				= model.componentSV.name.."_OutAreaAGR"

   	if (model.save == true) then 
            for year= model.yearInit, model.yearFinal, 1 do                            
		      			model.componentSV.saveCount = model.componentSV.saveCount + 1
		      			model.componentSV.saveAttrs[model.componentSV.saveCount] =model.componentSV.attrOutAreaVS..year
		      			model.componentSV.saveCount = model.componentSV.saveCount + 1
		      			model.componentSV.saveAttrs[model.componentSV.saveCount] =model.componentSV.attrOutAreaAGR..year
		        end
	end	    
     
	-- init (run time) past cell attribute names
     model.componentSV.attr_initial_area 					= model.componentSV.name.."initial_area_regrow_"
     model.componentSV.attr_initial_rate_acc_biomass_period1= model.componentSV.name.."rate_regrow_period1_"
     model.componentSV.attr_initial_rate_acc_biomass_period2= model.componentSV.name.."rate_regrow_period2_"  
     model.componentSV.attr_rate_regrowth 					= model.componentSV.name.."rate_regrow_"
     model.componentSV.attr_area_regrowth 					= model.componentSV.name.."area_regrow_"
     model.componentSV.attr_biomass_regrowth                = model.componentSV.name.."biomass_regrow_"
	
	forEachCell(model.cs,function(cell)
			 cell.area_cleared = 0
			 cell.rel_area_cleared = 0
			 cell.biomass_lost   = 0
			 cell.area_total = 0
			 cell.area_growing = 0
             cell.biomass_acc    = 0	
             
             componentSV_initCellAverComponentValues (cell, model)

	end)
	componentSV_initCellAttrNames (model)
end
------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentSV_initCellAttrNames (model)

-- Initialize cell space attr names 
	model.componentSV.attrAreaPercVegSec        = model.componentSV.name.."_AreaPercVegSec"
	model.componentSV.attrAreaAccPercVegSec     = model.componentSV.name.."_AreaAccPercVegSec"
	model.componentSV.attrAgriculturalUseCycle   = model.componentSV.name.."_AgriculturalUseCycle"
	model.componentSV.attrRecoveryPeriod1Perc  	= model.componentSV.name.."_RecoveryPeriod1Perc"
	model.componentSV.attrRecoveryPeriod1  		= model.componentSV.name.."_RecoveryPeriod1"
	model.componentSV.attrRecoveryPeriod2Perc  	= model.componentSV.name.."_RecoveryPeriod2Perc"
	model.componentSV.attrRecoveryPeriod2  		= model.componentSV.name.."_RecoveryPeriod2"
	model.componentSV.attrInitialAbandonmentCycle = model.componentSV.name.."_InitialAbandonmentCycle"
	model.componentSV.attrHalfLife 				= model.componentSV.name.."_HalfLife"
	model.componentSV.attrBGBpercBGB 			= model.componentSV.name.."_BGBpercBGB"
end	

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentSV_initCellAverComponentValues (cell, model)
      cell.SV_AreaPercVegSec        = model.componentSV.averAreaPercVegSec
	  cell.SV_AreaAccPercVegSec     = model.componentSV.averAreaAccPercVegSec
	  cell.SV_AgriculturalUseCycle  = model.componentSV.averAgriculturalUseCycle
	  cell.SV_RecoveryPeriod1Perc  	= model.componentSV.averRecoveryPeriod1Perc
	  cell.SV_RecoveryPeriod1  		= model.componentSV.averRecoveryPeriod1
	  cell.SV_RecoveryPeriod2Perc  	= model.componentSV.averRecoveryPeriod2Perc
	  cell.SV_RecoveryPeriod2  		= model.componentSV.averRecoveryPeriod2
	  cell.SV_InitialAbandonmentCycle 	= model.componentSV.averInitialAbandonmentCycle
	  cell.SV_HalfLife 					= model.componentSV.averHalfLife
	  cell.SV_BGBpercBGB 			    = model.componentSV.averBGBpercBGB

end

function componentSV_verify (model)


	     if (model.componentSV.name == nil)
	  	 then error ("Missing SV parameter: name", 5) end

	  	 if (model.componentSV.description == nil)
	  	 then error ("Missing SV parameter: description", 5) end

	if (model.componentSV.averAreaPercVegSec == nil)
	  then error ("Missing SV parameter: averAreaPercVegSec", 5) end
    if (model.componentSV.averAreaAccPercVegSec == nil)
	  then error ("Missing SV parameter: averAreaAccPercVegSec", 5) end
	if (model.componentSV.averAgriculturalUseCycle == nil)
	  then error ("Missing SV parameter: averAgriculturalUseCycle", 5) end
	if (model.componentSV.averRecoveryPeriod1Perc == nil)
	  then error ("Missing SV parameter: averRecoveryPeriod1Perc", 5) end
	if (model.componentSV.averRecoveryPeriod1 == nil)
	  then error ("Missing SV parameter: averRecoveryPeriod1", 5) end
   if (model.componentSV.averRecoveryPeriod2Perc == nil)
	  then error ("Missing SV parameter: averRecoveryPeriod2Perc", 5) end
   if (model.componentSV.averRecoveryPeriod2 == nil)
	  then error ("Missing SV parameter: averRecoveryPeriod2", 5) end
    if (model.componentSV.averInitialAbandonmentCycle == nil)
	  then error ("Missing SV parameter: averInitialAbandonmentCycle", 5) end
    if (model.componentSV.averHalfLife == nil)
	  then error ("Missing SV parameter: averHalfLife", 5) end
    if (model.componentSV.averBGBpercBGB == nil)
	  then error ("Missing SV parameter: averBGBpercBGB", 5) end
		  
	return true
end

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentSV_loadFromDB (model, cell_temp, cell, y)

    
	   if cell_temp[model.componentSV.attrAreaPercVegSec..y] ~= nil then
			      cell.SV_AreaPercVegSec 	= cell_temp[model.componentSV.attrAreaPercVegSec..y]
			      if (flagPrintAreaPercVegSec) then print (y, "Loading "..model.componentSV.attrAreaPercVegSec) flagPrintAreaPercVegSec = false end

	   end
	   
	   if cell_temp[model.componentSV.attrAreaAccPercVegSec..y] ~= nil then
			      cell.SV_AreaAccPercVegSec 	= cell_temp[model.componentSV.attrAreaAccPercVegSec..y]
	   end
	   if cell_temp[model.componentSV.attrAgriculturalUseCycle..y] ~= nil then
			      cell.SV_AgriculturalUseCycle 	= cell_temp[model.componentSV.attrAgriculturalUseCycle..y]
	   end
	   if cell_temp[model.componentSV.attrRecoveryPeriod1Perc..y] ~= nil then
			      cell.SV_RecoveryPeriod1Perc 	= cell_temp[model.componentSV.attrRecoveryPeriod1Perc..y]
	   end
	   if cell_temp[model.componentSV.attrRecoveryPeriod1..y] ~= nil then
			      cell.SV_RecoveryPeriod1 	= cell_temp[model.componentSV.attrRecoveryPeriod1..y]
	   end

	   if cell_temp[model.componentSV.attrRecoveryPeriod2Perc..y] ~= nil then
			      cell.SV_RecoveryPeriod2Perc 	= cell_temp[model.componentSV.attrRecoveryPeriod2Perc..y]
	   end
	   
	   if cell_temp[model.componentSV.attrRecoveryPeriod2..y] ~= nil then
			      cell.SV_RecoveryPeriod2 	= cell_temp[model.componentSV.attrRecoveryPeriod2..y]
	   end

	   if cell_temp[model.componentSV.attrInitialAbandonmentCycle..y] ~= nil then
			      cell.SV_InitialAbandonmentCycle 	= cell_temp[model.componentSV.attrInitialAbandonmentCycle..y]
	   end
	   if cell_temp[model.componentSV.attrHalfLife..y] ~= nil then
			      cell.SV_HalfLife 	= cell_temp[model.componentSV.attrHalfLife..y]
			      if (flagPrintHalfLife) then print (y,"Loading "..model.componentSV.attrHalfLife) flagPrintHalfLife = false end

	   end
	   
	   if cell_temp[model.componentSV.attrBGBpercBGB..y] ~= nil then
			      cell.SV_BGBpercBGB 	= cell_temp[model.componentSV.attrBGBpercBGB..y]
	   end
	   
end

------------------------------------------------------------------------------------------- 
------------------------------------------------------------------------------------------- 
function componentSV_loadFromTable (model, cell, step)
    if (model.dataTable.AreaPercVegSec ~= nil) then
	             if (#model.dataTable.AreaPercVegSec < step) then
	             	error ("Time required exceeds the input table size: AreaPercVegSec", 5) 
		         end
		         cell.SV_AreaPercVegSec = model.dataTable.AreaPercVegSec [step]
    end
    
        if (model.dataTable.AreaAccPercVegSec ~= nil) then
	             if (#model.dataTable.AreaAccPercVegSec < step) then
	             	error ("Time required exceeds the input table size: AreaAccPercVegSec", 5) 
		         end
		         cell.SV_AreaAccPercVegSec = model.dataTable.AreaAccPercVegSec [step]
    end

   
    if (model.dataTable.AgriculturalUseCycle ~= nil) then
	             if (#model.dataTable.AgriculturalUseCycle < step) then
	             	error ("Time required exceeds the input table size: AgriculturalUseCycle", 5) 
		         end
		         cell.SV_AgriculturalUseCycle = model.dataTable.AgriculturalUseCycle [step]
   end
   if (model.dataTable.RecoveryPeriod1Perc ~= nil) then
	             if (#model.dataTable.RecoveryPeriod1Perc < step) then
	             	error ("Time required exceeds the input table size: RecoveryPeriod1Perc", 5) 
		         end
		         cell.SV_RecoveryPeriod1Perc = model.dataTable.RecoveryPeriod1Perc [step]
   end
   if (model.dataTable.RecoveryPeriod1 ~= nil) then
	             if (#model.dataTable.RecoveryPeriod1 < step) then
	             	error ("Time required exceeds the input table size: RecoveryPeriod1", 5) 
		         end
		         cell.SV_RecoveryPeriod1 = model.dataTable.RecoveryPeriod1 [step]
   end
   if (model.dataTable.RecoveryPeriod2Perc ~= nil) then
	             if (#model.dataTable.RecoveryPeriod2Perc < step) then
	             	error ("Time required exceeds the input table size: RecoveryPeriod2Perc", 5) 
		         end
		         cell.SV_RecoveryPeriod2Perc = model.dataTable.RecoveryPeriod2Perc [step]
   end
   if (model.dataTable.RecoveryPeriod2 ~= nil) then
	             if (#model.dataTable.RecoveryPeriod2 < step) then
	             	error ("Time required exceeds the input table size: RecoveryPeriod2", 5) 
		         end
		         cell.SV_RecoveryPeriod2 = model.dataTable.RecoveryPeriod2 [step]
   end
   if (model.dataTable.InitialAbandonmentCycle ~= nil) then
	             if (#model.dataTable.InitialAbandonmentCycle < step) then
	             	error ("Time required exceeds the input table size: InitialAbandonmentCycle", 5) 
		         end
		         cell.SV_InitialAbandonmentCycle = model.dataTable.InitialAbandonmentCycle [step]
   end
   if (model.dataTable.HalfLife ~= nil) then
	             if (#model.dataTable.HalfLife < step) then
	             	error ("Time required exceeds the input table size: HalfLife", 5) 
		         end
		         cell.SV_HalfLife = model.dataTable.HalfLife [step]
   end
   if (model.dataTable.BGBpercBGB ~= nil) then
	             if (#model.dataTable.BGBpercBGB < step) then
	             	error ("Time required exceeds the input table size: BGBpercBGB", 5) 
		         end
		         cell.SV_BGBpercBGB = model.dataTable.BGBpercBGB [step]
   end
 
end



