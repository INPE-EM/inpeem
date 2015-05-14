
-----------------------------------------------------
----------------------- EMISSION FACTORS
-----------------------------------------------------

       
-- Global Warming Potential (GWP) (source: 2nd Brazil's National COmmunication to UNFCCC, Table 2.8)
      
--        gwp_CO2 = 1.0
--        gwp_CH4 = 21.0
--        gwp_N2O = 310.0
--        gwp_NOx = 0.0
--        gwp_CO = 0.0
         

 -- Global Warming Potential (GWP) (without carbon feedback - source: IPCC AR5 2013 - cap 8, p 713 )
      
        gwp_CO2 = 1.0
        gwp_CH4 = 28.0
        gwp_N2O = 265.0
        gwp_NOx = 0.0
        gwp_CO = 0.0

-- MATH Functions

E = 2.718



function computeAreaExpDecay (area_init, meia_vida, t_final)
    prev = area_init
    diff = 0
    if meia_vida > 0 and area_init > 0 and t_final >=0 then
        k = (math.log(50)-math.log(100))/meia_vida
	    for t = 1, t_final, 1 do
	    		x = area_init*E^(k*t)
	   		    diff = prev - x
	   		    prev = prev - diff
	    end
    end
	return diff
end


function compute_exp (xo, k, t)
     local x = xo*E^(k*t)
     return x
end


--t=	21	-0.033007009
--t=	6	-0.11552453
--t=	5	-0.138629436
--t=	4	-0.173286795
--t=	6	-0.11552453
--t=	4	-0.173286795
--t=	3	-0.23104906
--t=	5	-0.138629436

function compute_k (t)
     --print (t)
     if (t > 0) then
        k = (math.log(50)-math.log(100))/t
     end
     --print (t, k)
     return k
end

function compute_t_final (k)
    if (k < 0) then
        t = (math.log(1)-math.log (100))/k
    end
    --print ("final time 1%", k, t)
    return t
end


function compute_meia_vida_hist (y, y0, x0, x2004)
     t = y - y0
     --print (t, y, y0, x0, x2004)
     
     if (t > 0) then
        k = (math.log(x2004)-math.log(x0))/(2006-1961)
     end
     meia_vida = compute_exp (x0, k, t)
     --print ("Y0", y0, "Y", y, "X0", x0, "x2004", x2004, "T", t, "K", k, meia_vida)
     
     return meia_vida
end

--meia_vida1 = compute_meia_vida_hist (1970, 1961, 20, 5)
--meia_vida2 = compute_meia_vida_hist (2000, 1961, 20, 5)
--meia_vida2 = compute_meia_vida_hist (1970, 1961, 10, 5)
--meia_vida2 = compute_meia_vida_hist (2000, 1961, 10, 5)
--meia_vida2 = compute_meia_vida_hist (2004, 1961, 10, 5)



