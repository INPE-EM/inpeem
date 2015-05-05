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


-------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------
--- INPE-EM Framework: inpeEM_general.lua 
--  Author: Ana Paula Aguiar
--  Date (last update): 24 October 2014



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

-----------------------------------------------------
-- MATH Functions
-----------------------------------------------------

E = 2.718


function compute_exp (xo, k, t)
     local x = xo*E^(k*t)
     return x
end



