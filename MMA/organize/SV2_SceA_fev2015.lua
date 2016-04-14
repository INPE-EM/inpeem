
output_theme_name = "SV2_SceA_2014_"

cs = CellularSpace
{
    database = "D:\\_MMA\\bd\\2015_inpeem_estimativas_mma_v2.mdb",    
    theme = "SceA"
} 





function createSF_ScenarioA (cs, init, year_change, final,  theme, attrDef, component)
   local n = 1
   local attrs = {}

	
	for y = year_change, year_change + 15 do
		attrs[n] = component.."_AreaAccPercVegSec"..y
		n = n + 1 --30
	end
	
   print (year_change, year_change+15, n,  #attrs)
   io.flush()
    local year_change2 = year_change + 5
    attrs[n] = component.."_HalfLife"..year_change2
    n = n + 1  --31

    attrs[n] = component.."_AreaPercVegSec"..year_change2
	n = n + 1  --32


	forEachCell(cs, function(cell)
	
	          
		    
		    cell[component.."_HalfLife"..year_change2] = 100000
		    cell[component.."_AreaPercVegSec"..year_change2] = 0
		    
		    local incr_prev = cell[component.."_AreaPercVegSec"..2002]
		   	--local incr_prev = 0.20

		    print (incr_prev)
			local diff = 0.4 - incr_prev
			local rate = 0
			if (diff > 0) then rate = diff/15 end
			--print (rate)
			for y = year_change, year_change + 14 do
                   cell[component.."_AreaAccPercVegSec"..y] = rate
            end
            y = year_change + 15
            cell[component.."_AreaAccPercVegSec"..y] = 0
	    end)
	   
	print (n, # attrs)
	print (n) io.flush()
    cs:save(final, theme, attrs)
 end





createSF_ScenarioA (cs, 2014, 2015, 2050, output_theme_name, "D_Ext", "SV2")
