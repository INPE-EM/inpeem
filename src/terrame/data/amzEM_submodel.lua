---------------------------------------------------------------
--       This file contains the COMPONENTS definition        --
--              Compatible with INPE-EM 3.0                  --
--       Generated with INPE-EM Model Configurator           --
--                 20/12/2019 at 09:59:55                    --
---------------------------------------------------------------

--------------------------------------------------------------
-- BIOMASS COMPONENT DEFINITION                             --
--------------------------------------------------------------
B1 = 
{
	name = "b3",
	description = "Componente de biomassa 3 inventario ",
	
	averAGB = 233,
	averBGBPercAGB = 0.2,
	averLitterPercAGB = 0.04,
	averDeadWoodPercAGB = 0.07,
	
	averFactorB_C = 0.47,
	averFactorB_CO2 = 1.7249,
	averFactorB_CO2_fire = 1.601,
	averFactorB_CH4_fire = 0.00625,
	averFactorB_N2O_fire = 0.0002,
	averFactorB_NOx_fire = 0.0017,
	averFactorB_CO_fire = 0.1078
}

--------------------------------------------------------------
-- DEFOREST COMPONENT DEFINITION                            --
--------------------------------------------------------------
D1 = 
{
	name = "d",
	description = "Componente de desmatamento",
	initialArea = 0,
	initialForest = 403844099
}

--------------------------------------------------------------
-- VEGETATION REMOVAL COMPONENT DEFINITION                  --
--------------------------------------------------------------
VR1 = 
{
	name = "vr",
	description = "Componente de vegetacao primaria",
	save = false,
	
	averAGBPercAGB = 0,
	averAGBPercWoodProducts = 0.15,
	averAGBPercInstantaneous = 0.425,
	averAGBPercDecomposition = 0.425,
	
	averBGBPercBGB = 0,
	averBGBPercInstantaneous = 0,
	averBGBPercDecompositionAbove = 0,
	averBGBPercDecompositionUnder = 1,
	
	averDecompositionFireCyclePeriod = 3,
	averDecompositonPercElementalCarbon = 0.02,
	
	averLitterPercInstantaneous = 1,
	averLitterPercDecomposition = 0,
	averDeadWoodPercInstantaneous = 0.5,
	averDeadWoodPercDecomposition = 0.5,
	
	averDecayRateWoodProducts = 0.1,
	averDecayRateElementalCarbon = 0.001,
	averDecayRateAGBDecomposition = 0.4,
	averDecayRateBGBDecompositionAbove = 0.4,
	averDecayRateBGBDecompositionUnder = 0.7,
	averDecayRateLitterDecomposition = 0.4,
	averDecayRateDeadWoodDecomposition = 0.4
}

--------------------------------------------------------------
-- SECONDARY VEGETATION COMPONENT DEFINITION                --
--------------------------------------------------------------
SV1 = 
{
	name = "sv",
	description = "Componente vegetacao secundaria",
	save = false,
	
	averHalfLife = 5,
	averAreaPercVegSec = 0.21,
	averAreaAccPercVegSec = 0,
	averRecoveryPeriod1Perc = 0.7,
	averRecoveryPeriod1 = 25,
	averRecoveryPeriod2Perc = 0.3,
	averRecoveryPeriod2 = 50,
	averAgriculturalUseCycle = 2,
	averInitialAbandonmentCycle = 3
}

--------------------------------------------------------------
-- DEGRADATION COMPONENT DEFINITION                         --
--------------------------------------------------------------
DG1 = 
{
	name = "dg",
	description = "Componente de degradacao",
	save = false,
	
	averAGB_loss = 0.54,
	averBGB_loss = 0,
	averDeadWood_loss = 0,
	averLitter_loss = 0,
	
	averAGB_percReduction = 0.00291,
	averPeriodRegrow = 200,
	averLimiarDegradYears = 0,
	averLimiarDegradLoss = 0
}

