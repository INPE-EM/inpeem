
output_theme_name = "SV2_SceC2_v5_percvegsec_2014_"

cs = CellularSpace
{
        dbType = "mysql",
    	host = "localhost",
		user = "root",
		password = "rw1311",
	    database = "2015_inpeem_estimativas_paper_final",		
	    theme = "cs"  -- tema ainda vazio
} 


percVegSec_SceB = 
   { 
                       0.13, --  0.50 - 1.00  , considerando original < 0.21
                       0.17,  -- 0.30 - 0.50  , considerando original < 0.5
                       0.21,  -- 0.01 - 0.30  , considerando original < 0.5
                      
   }



function createSF_ScenarioC (cs, init, final, theme, attrDef, attr_initial_forest, component)
     attrs = {}
     local n = 1

   for y = init, final do
   attrs[n] =	component.."_AreaPercVegSec"..y
		n = n + 1
	end

   forEachCell(cs, function(cell)
   	  	local prev = cell[component.."_AreaPercVegSec"..2002]   
 --print (prev)
       for y = init, final do
             attr = attrDef..y
            
               local perc_def_original = 0
	         if (cell[attr_initial_forest] ~= 0) then
	             		perc_def_original = cell[attr]/(cell[attr_initial_forest])
	         end    
	         cell[component.."_AreaPercVegSec"..y] = prev
      
           
                
            
              
              if (perc_def_original < 0.30 and prev > 0.21)   then
                 --cell[component.."_AreaPercVegSec"..y] = cell[component.."_AreaPercVegSec"..2002]
                 cell[component.."_AreaPercVegSec"..y] = 0.21
              end

              if (perc_def_original >= 0.30 and perc_def_original < 0.50 and prev > 0.17)  then
                  cell[component.."_AreaPercVegSec"..y] = 0.17
              end

		 if (perc_def_original >= 0.50   and prev > 0.13) then
                  cell[component.."_AreaPercVegSec"..y] = 0.13
              end
        prev = cell[component.."_AreaPercVegSec"..y]
        end
		
   end)
   
    cs:save(final, theme, attrs)
 end
 
 createSF_ScenarioC(cs, 2014, 2050, output_theme_name, "D_Ext",  "pristine_forest", "SV2")
