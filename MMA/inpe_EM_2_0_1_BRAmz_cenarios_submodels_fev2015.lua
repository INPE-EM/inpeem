-- Name: Biomass, Primary and Secondary model parameter
-- First order estimates
-- Author: Bruna Leal, Talita Assis
-- Date (last update): 30 jun 2015
---------------------------------------------------------------------------
------------------------------ EMISSION PARAMETERS
---------------------------------------------------------------------------

---------------------------------------------------------------------------
------------------------------ DEFORESTATION PARAMETERS
---------------------------------------------------------------------------

D  = 
{
	   name 		    	= "D",  
	   description 			= "Peru deforestation",
	   initialArea 			= 0  

}



---------------------------------------------------------------------------
------------------------------ VEGETATION REMOVAL PARAMETERS
---------------------------------------------------------------------------
PeruAmz_VR1  = 
{
	   name 						= "VR1",
	   description 					= "50% burn first year, 15% wood",
	   save 						= false,
 
	   averAGBPercAGB               = 0,
     averAGBPercWoodProducts 		= 0,
	   averAGBPercInstantaneous 	= 1, 
     averAGBPercDecomposition     = 0, 

	   
	   averBGBPercBGB 					= 0,
	   averBGBPercInstantaneous			= 0, 
	   averBGBPercDecompositionAbove    = 0, 
	   averBGBPercDecompositionUnder    = 1, 
	   
	   averLitterPercInstantaneous 	= 1,
	   averLitterPercDecomposition 	= 0,
	   averDeadWoodPercInstantaneous   = 1,
	   averDeadWoodPercDecomposition  	= 0,
		
		averDecompositionFireCyclePeriod 			= 3,
		averDecompositonPercElementalCarbon 	= 0,
	   
-- Decay rates
	   
	   averDecayRateWoodProducts 				= 0.0, 
       averDecayRateElementalCarbon 	    	=  0.0, 
       averDecayRateAGBDecomposition 			=  0.0, 
       averDecayRateBGBDecompositionAbove 		=  0.0, 
       averDecayRateBGBDecompositionUnder 		=  0.0, 
  	   averDecayRateLitterDecomposition			=  0.0,
	   averDecayRateDeadWoodDecomposition       = .0,
     
}
---------------------------------------------------------------------------
------------------------------ SECONDARY VEGETATION  PARAMETERS
---------------------------------------------------------------------------


PeruAmz_SV1 =
{
 	   	description = "Almeida 2009 and TerraClass",
     	name = "SV1",
     	save = false,

	   	averHalfLife 					= 5,
	   	averAreaPercVegSec 				= 0.21,
	   	averAreaAccPercVegSec 			= 0,
        averRecoveryPeriod1Perc 		= 0.70,
        averRecoveryPeriod1 			= 25, -- years
        averRecoveryPeriod2Perc 		= 0.30, 
        averRecoveryPeriod2 			= 50, --years,
        averAgriculturalUseCycle        = 8,
       	averInitialAbandonmentCycle      = 3,
       	averBGBpercBGB                   = 0,


}
---------------------------------------------------------------------------
------------------------------ BIOMASS PARAMETERS
---------------------------------------------------------------------------


Biomass = 
{
	   name 			    = "Peru",  
	   description 			= "Dado Oficial Peru",

	   averAGB 				= 117.7,
	   averBGBPercAGB 		= 0.258,  
	   averLitterPercAGB 		= 0.049,  
	   averDeadWoodPercAGB 		= 0.088,  

	    averFactorB_C = 0.47,
	    averFactorB_CO2 = 1.7249, -- carbon_perc*factor_C_CO2 (0.47 x 3.67)
        averFactorB_CO2_fire = 1.601,   --dioxido de carbono
        averFactorB_CH4_fire = 0.00625,--metano
        averFactorB_N2O_fire = 0.0002, --oxido nitroso
        averFactorB_NOx_fire = 0.0017,  --oxidos de nitrogenio
        averFactorB_CO_fire = 0.1078  --monoxido de carbono 
	   
	   }
---------------------------------------------------------------------------
------------------------------ EMISSION FACTOR PARAMETERS
---------------------------------------------------------------------------

-- Longo, K.M. et. al. 2009. In: Amazonia and Global Change. (Keller et. al. Eds.)
-- valido para floresta amazonica. Unidade: tonelada do gas para cada tonelada de biomassa (seca)

FL09 = 
{	   
        averFactorB_C = 0.47,
	    averFactorB_CO2 = 1.7249, -- carbon_perc*factor_C_CO2 (0.48 x 3.67)
        averFactorB_CO2_fire = 1.601,   --dioxido de carbono
        averFactorB_CH4_fire = 0.00625,--metano
        averFactorB_N2O_fire = 0.0002, --oxido nitroso
        averFactorB_NOx_fire = 0.0017,  --oxidos de nitrogenio
        averFactorB_CO_fire = 0.1078  --monoxido de carbono

}







