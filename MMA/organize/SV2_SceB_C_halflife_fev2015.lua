--output_theme_name = "SV2_SceB_halflife_2014_"
--output_theme_name = "SV2_SceB2000_halflife_2014_"
--output_theme_name = "SV2_SceB3000_halflife_2014_"
--output_theme_name = "SV2_SceAB_halflife_2014_"
output_theme_name = "SV2_SceB1000_halflife_2014_"

cs = CellularSpace
{
    database = "D:\\_MMA\\bd\\2015_inpeem_estimativas_mma_v2.mdb",		
    --theme = "SceB"  -- tema ainda vazio
    --theme = "SceB2000"
    --theme = "SceB3000"
    theme = "SceB1000"
} 



function computeAlmeidaHalfLife ( cell, y, SF_component_name, attr_initial_forest, attrDef)
			 attr_HalfLife = SF_component_name.."_HalfLife"..y
	         local perc_def_original = 0
	        -- print (attrDef, attr_initial_forest, cell[attr_initial_forest], cell[attrDef])
	         --io.flush()
	         if (cell[attr_initial_forest] ~= 0) then
	             		perc_def_original = cell[attrDef]/(cell[attr_initial_forest])
	         end                
	        cell[attr_HalfLife] = computeHalfLife (perc_def_original)
           -- print (attr_HalfLife, cell[attr_initial_forest], cell[attr_HalfLife])
end
 
 
function computeHalfLife (perc)  
                       
                       
    local level = 8
    
    if (perc <= 0.01)then
       level = 1
    end
       
    if (perc > 0.01) and (perc <= 0.05)then
       level = 2
    end
    
    if (perc > 0.05) and (perc <= 0.10)then
       level = 3
    end
    
    if (perc > 0.10) and (perc <= 0.20) then
       level = 4
    end
    
    if (perc > 0.20) and (perc <= 0.30)then
       level = 5
    end
    
    if (perc > 0.30) and (perc <= 0.55)then
       level = 6
    end
    if (perc > 0.55) then
       level = 7
    end
    
     almeidaHalfLifeTable = 
   { 
                       20.93, --1
                       7.39,  --2
                       5.16,  --3
                       4.66,  --4
                       6.37,  --5
                       3.82,  --6
                       3.55,  --7
                       5.39   -- 8
   }
   -- print (perc, level, almeidaHalfLifeTable[level])
    return (almeidaHalfLifeTable[level])
    
 end

 

function createSF_halfLife (cs, init, final, theme, attrDef, attrOriginal, SFcomponent)
   local n = 1
   attrs = {}
   local last = final + 1
   
   for y = init, final do
		attrs[n] = SFcomponent.."_HalfLife"..y
		n = n + 1
	end
	
	--print (n)
	--io.flush()
	forEachCell(cs, function(cell)
	       for y = init, final do
	               -- print (y)
					computeAlmeidaHalfLife ( cell,  y, SFcomponent, attrOriginal, attrDef..y)
		    end
   end)
		    
		   
		       
    cs:save(final, theme, attrs)
 end
 
 
 
createSF_halfLife (cs, 2014, 2050, output_theme_name, "D_Ext", "pristine_forest", "SV2")
