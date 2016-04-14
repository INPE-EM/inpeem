--- MODEL teste1 
--  Author: Ana Paula Aguiar
--  Date (last update): 10 april 2013


PROJECTDIR = "D:\\_MMA\\"
dofile(PROJECTDIR.."inpe_EM_2_0_1\\inpeEM.lua")

MODELDIR = "D:\\_MMA\\"

dofile(MODELDIR.."inpe_EM_2_0_1_BRAmz_cenarios_submodels_fev2015.lua")
dofile(MODELDIR.."inpe_EM_2_0_1_BRAmz_cenarios_non_spatial_data.lua")

--  B 	    = B_N08
--  B 	    = B_S11
--  B 	    = B_B12
  B =         B_MCTI2nd


BRAmz_2_0_1_ns = 
{ 
   name = "BRAmz_2_0_1_ns",
   componentD 		= D_PRODES2013,
   componentB 	  = B,
   componentVR 	  = BRAmz_VR1,
   componentSV	 	= BRAmz_SV2,
 
    mode = "non_spatial",
    dataTable = BRAmz_1960_2100_prodes2013_SceAB_no_def,
    area = 8450*625,
    
    yearInit =  1960,
    yearFinal = 2050,	
    verbose = true
  
}   
   
inpeEM_execute (BRAmz_2_0_1_ns)
