output_theme_name = "SV2_half_life_2002_"

cs = CellularSpace
{
        dbType = "mysql",
    	host = "localhost",
		user = "root",
		password = "rw1311",
	    database = "2015_inpeem_estimativas_paper_final",		
	    theme = "Prodes2013_correto"  -- tema ainda vazio
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
 
 
 
createSF_halfLife (cs, 2002, 2013, output_theme_name, "D_Ext", "pristine_forest", "SV2")
