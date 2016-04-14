--- MODEL teste1 
--  Author: Ana Paula Aguiar
--  Date (last update): 10 april 2013

--C:\MMA\inpe_EM_2_0_1
PROJECTDIR = "C:\\MMA\\"
dofile(PROJECTDIR.."inpe_EM_2_0_1\\inpeEM.lua")

MODELDIR = "C:\\MMA\\"

dofile(MODELDIR.."inpe_EM_2_0_1_BRAmz_cenarios_submodels_fev2015.lua")
dofile(MODELDIR.."inpe_EM_2_0_1_BRAmz_cenarios_non_spatial_data.lua")


B =   Biomass

PeruAmz_2_0_1_ns = 
{ 
   name = "PeruAmz_2_0_1_ns",
   componentD 		= D,
   componentB 	    = B,
   componentVR 	    = PeruAmz_VR1,
   componentSV	 	= PeruAmz_SV1,
 
    mode = "non_spatial",
    dataTable = PeruAmz_2000_2013,
    area = 8450*625,
    
    yearInit =  2000,
    yearFinal = 2013,	
    verbose = true
  
}   
inpeEM_execute (PeruAmz_2_0_1_ns)



