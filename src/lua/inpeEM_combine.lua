-- Handles with the execution of combine model.
-- @arg model_out A INPE-EM model.
-- @arg model_ns A non-spatial INPE-EM model.
-- @arg model_s A spatial INPE-EM model.
-- @usage --DONTRUN
-- inpeEM_combineResultsVR(model_ns, model_s)
function inpeEM_executeCombine(model_out, model_ns, model_s)
	if (model_out == nil) then 
		print("Error - No output model defined!")
		os.exit()
	end

	-- Execute non-spatial and spatial submodels
	if ((model_ns == nil) or (model_s == nil)) then 
		print("Error - Please, define and execute your models before combining them!")
		os.exit()
	end
	
	print("\nExecuting non-spatial mode...")
	
	if (model_ns.run ~= true) then
		inpeEM_execute(model_ns) 
	end

	print("\nExecuting spatial mode...")

	if (model_s.run ~= true) then
		inpeEM_execute(model_s) 
	end

	if (((model_ns.SV_flag == false) or (model_s.SV_flag == false)) and ((model_ns.VR_flag == false) or (model_s.VR_flag == false)) and ((model_ns.DEGRAD_flag == false) or (model_s.DEGRAD_flag == false))) then
		print("Error - No model PF or SF or DEGRAD model results to combine!")
		os.exit()
    end

	if (model_out.verbose == nil) then
		model_out.verbose = false 
	end
	
	if ((model_out.verbose ~= true) and (model_out.verbose ~= false)) then
		print("Error - Combine model verbose must be true or false!")
		os.exit()
	end

	model_out.componentD = model_s.componentD
	model_out.componentB = model_s.componentB
	model_out.componentDEGRAD = model_s.componentDEGRAD
	model_out.componentSV = model_s.componentSV
	model_out.componentVR = model_s.componentVR
	model_out.yearInit = model_ns.yearInit
	model_out.yearFinal = model_s.yearFinal

	inpeEM_initResults(model_out)

	print("\nCombining spatial and non-spatial results...")
	io.flush()

	if (model_ns.DEGRAD_flag and model_s.DEGRAD_flag) then 
		model_out.DEGRAD_Result = inpeEM_combineResultsDEGRAD(model_ns, model_s)
		model_out.DEGRAD_flag = true
    else
        model_out.DEGRAD_flag = false  
    end 
	
	if (model_ns.SV_flag and model_s.SV_flag) then 
		model_out.SV_Result = inpeEM_combineResultsSV(model_ns, model_s)
		model_out.SV_flag = true
	else
		model_out.SV_flag = false 
	end 

	if (model_ns.VR_flag and model_s.VR_flag) then 
		model_out.VR_Result = inpeEM_combineResultsVR(model_ns, model_s)
		model_out.VR_flag = true
	else
		model_out.VR_flag = false 
	end 

	model_out.NET_Result = inpeEM_combineResultsNET(model_ns, model_s)
	model_out.D_Result = inpeEM_combine_D(model_ns, model_s)
end

-- Handles with the results of Vegetation Removal component for combine model.
-- @arg model_ns A non-spatial INPE-EM model.
-- @arg model_s A spatial INPE-EM model.
-- @usage --DONTRUN
-- inpeEM_combineResultsVR(model_ns, model_s)
function inpeEM_combineResultsVR(model_ns, model_s)
	local VR_Result = {}
	
	for y = model_ns.yearInit, model_s.yearInit - 1, 1 do
		VR_Result[y] = {
							VR_CO2_1stOrder = model_ns.VR_Result[y].VR_CO2_1stOrder,
							VR_CO2_2ndOrder = model_ns.VR_Result[y].VR_CO2_2ndOrder,
							VR_CO2_2ndOrderFire = model_ns.VR_Result[y].VR_CO2_2ndOrderFire,
							VR_CO2_2ndOrderDecay = model_ns.VR_Result[y].VR_CO2_2ndOrderDecay,
							VR_CH42Eq_2ndOrderFire = model_ns.VR_Result[y].VR_CH42Eq_2ndOrderFire,
							VR_N2OEq_2ndOrderFire = model_ns.VR_Result[y].VR_N2OEq_2ndOrderFire,
							VR_CO2Eq_2ndOrderFire = model_ns.VR_Result[y].VR_CO2Eq_2ndOrderFire,
							VR_NOxEq_2ndOrderFire = model_ns.VR_Result[y].VR_NOxEq_2ndOrderFire
						}
	end

	for y = model_s.yearInit, model_s.yearFinal, 1 do
		VR_Result[y] = {
							VR_CO2_1stOrder = model_ns.VR_Result[y].VR_CO2_1stOrder + model_s.VR_Result[y].VR_CO2_1stOrder,
							VR_CO2_2ndOrder = model_ns.VR_Result[y].VR_CO2_2ndOrder + model_s.VR_Result[y].VR_CO2_2ndOrder,
							VR_CO2_2ndOrderFire = model_ns.VR_Result[y].VR_CO2_2ndOrderFire + model_s.VR_Result[y].VR_CO2_2ndOrderFire,
							VR_CO2_2ndOrderDecay = model_ns.VR_Result[y].VR_CO2_2ndOrderDecay + model_s.VR_Result[y].VR_CO2_2ndOrderDecay,
							VR_CH42Eq_2ndOrderFire = model_ns.VR_Result[y].VR_CH42Eq_2ndOrderFire + model_s.VR_Result[y].VR_CH42Eq_2ndOrderFire,
							VR_N2OEq_2ndOrderFire = model_ns.VR_Result[y].VR_N2OEq_2ndOrderFire + model_s.VR_Result[y].VR_N2OEq_2ndOrderFire,
							VR_CO2Eq_2ndOrderFire = model_ns.VR_Result[y].VR_CO2Eq_2ndOrderFire + model_s.VR_Result[y].VR_CO2Eq_2ndOrderFire,
							VR_NOxEq_2ndOrderFire = model_ns.VR_Result[y].VR_NOxEq_2ndOrderFire + model_s.VR_Result[y].VR_NOxEq_2ndOrderFire 
						}
	end
	
	return VR_Result
end

-- Handles with the results of Secondary Vegetation component for combine model.
-- @arg model_ns A non-spatial INPE-EM model.
-- @arg model_s A spatial INPE-EM model.
-- @usage --DONTRUN
-- inpeEM_combineResultsSV(model_ns, model_s)
function inpeEM_combineResultsSV(model_ns, model_s)
	local SV_Result = {}
	
	for y = model_ns.yearInit, model_s.yearInit - 1, 1 do
		SV_Result[y] = {
							SV_AreaTotal = model_ns.SV_Result[y].SV_AreaTotal,
							SV_AreaCleared = model_ns.SV_Result[y].SV_AreaCleared,
							SV_CO2Emission = model_ns.SV_Result[y].SV_CO2Emission,
							SV_CO2Absorption = model_ns.SV_Result[y].SV_CO2Absorption
						}
	end

	for y = model_s.yearInit, model_s.yearFinal, 1 do
		SV_Result[y] = {
							SV_AreaTotal = model_s.SV_Result[y].SV_AreaTotal,
							SV_AreaCleared = model_ns.SV_Result[y].SV_AreaCleared + model_s.SV_Result[y].SV_AreaCleared,
							SV_CO2Emission = model_ns.SV_Result[y].SV_CO2Emission + model_s.SV_Result[y].SV_CO2Emission,
							SV_CO2Absorption = model_ns.SV_Result[y].SV_CO2Absorption + model_s.SV_Result[y].SV_CO2Absorption
						}
	end
	
	return SV_Result
end

-- Handles with the results of DEGRAD component for combine model.
-- @arg model_ns A non-spatial INPE-EM model.
-- @arg model_s A spatial INPE-EM model.
-- @usage --DONTRUN
-- inpeEM_combineResultsDEGRAD(model_ns, model_s)
function inpeEM_combineResultsDEGRAD(model_ns, model_s)
	local DEGRAD_Result = {}
	for y = model_ns.yearInit, model_s.yearInit - 1, 1 do
		DEGRAD_Result[y] = {
								DEGRAD_Area = model_ns.DEGRAD_Result[y].DEGRAD_Area,
								DEGRAD_AveLoss = model_ns.DEGRAD_Result[y].DEGRAD_AveLoss,
								DEGRAD_CO2Emission = model_ns.DEGRAD_Result[y].DEGRAD_CO2Emission,
								DEGRAD_CO2Absorption = model_ns.DEGRAD_Result[y].DEGRAD_CO2Absorption,
								DEGRAD_CO2EmissionAboveDegradLimiar = model_ns.DEGRAD_Result[y].DEGRAD_CO2EmissionAboveDegradLimiar,
								DEGRAD_CO2AbsorptionAboveDegradLimiar = model_ns.DEGRAD_Result[y].DEGRAD_CO2AbsorptionAboveDegradLimiar,
								DEGRAD_CO2Balance = model_ns.DEGRAD_Result[y].DEGRAD_CO2Balance,
								DEGRAD_CO2Balance2 = model_ns.DEGRAD_Result[y].DEGRAD_CO2Balance2,
								DEGRAD_CH4Eq2ndOrderFire = model_ns.DEGRAD_Result[y].DEGRAD_CH4Eq2ndOrderFire,
								DEGRAD_N2OEq2ndOrderFire = model_ns.DEGRAD_Result[y].DEGRAD_N2OEq2ndOrderFire,
								DEGRAD_COEq2ndOrderFire = model_ns.DEGRAD_Result[y].DEGRAD_COEq2ndOrderFire,
								DEGRAD_NOxEq2ndOrderFire = model_ns.DEGRAD_Result[y].DEGRAD_NOxEq2ndOrderFire
							}
	end
    
	for y = model_s.yearInit, model_s.yearFinal, 1 do
		DEGRAD_Result[y] = {
								DEGRAD_Area = model_s.DEGRAD_Result[y].DEGRAD_Area,
								DEGRAD_AveLoss = model_s.DEGRAD_Result[y].DEGRAD_AveLoss,
								DEGRAD_CO2Emission = model_ns.DEGRAD_Result[y].DEGRAD_CO2Emission + model_s.DEGRAD_Result[y].DEGRAD_CO2Emission,
								DEGRAD_CO2Absorption = model_ns.DEGRAD_Result[y].DEGRAD_CO2Absorption + model_s.DEGRAD_Result[y].DEGRAD_CO2Absorption,
								DEGRAD_CO2EmissionAboveDegradLimiar = model_ns.DEGRAD_Result[y].DEGRAD_CO2EmissionAboveDegradLimiar + model_s.DEGRAD_Result[y].DEGRAD_CO2EmissionAboveDegradLimiar,
								DEGRAD_CO2AbsorptionAboveDegradLimiar = model_ns.DEGRAD_Result[y].DEGRAD_CO2AbsorptionAboveDegradLimiar + model_s.DEGRAD_Result[y].DEGRAD_CO2AbsorptionAboveDegradLimiar,
								DEGRAD_CO2Balance = model_ns.DEGRAD_Result[y].DEGRAD_CO2Balance + model_s.DEGRAD_Result[y].DEGRAD_CO2Balance,
								DEGRAD_CO2Balance2 = model_ns.DEGRAD_Result[y].DEGRAD_CO2Balance2 + model_s.DEGRAD_Result[y].DEGRAD_CO2Balance2, 
								DEGRAD_CH4Eq2ndOrderFire = model_ns.DEGRAD_Result[y].DEGRAD_CH4Eq2ndOrderFire + model_s.DEGRAD_Result[y].DEGRAD_CH4Eq2ndOrderFire,
								DEGRAD_N2OEq2ndOrderFire = model_ns.DEGRAD_Result[y].DEGRAD_N2OEq2ndOrderFire + model_s.DEGRAD_Result[y].DEGRAD_N2OEq2ndOrderFire,
								DEGRAD_COEq2ndOrderFire = model_ns.DEGRAD_Result[y].DEGRAD_COEq2ndOrderFire + model_s.DEGRAD_Result[y].DEGRAD_COEq2ndOrderFire,
								DEGRAD_NOxEq2ndOrderFire = model_ns.DEGRAD_Result[y].DEGRAD_NOxEq2ndOrderFire + model_s.DEGRAD_Result[y].DEGRAD_NOxEq2ndOrderFire
							}
	end

	return DEGRAD_Result
end

-- Handles with the carbon balance for combine model.
-- @arg model_ns A non-spatial INPE-EM model.
-- @arg model_s A spatial INPE-EM model.
-- @usage --DONTRUN
-- inpeEM_combineResultsNET(model_ns, model_s)
function inpeEM_combineResultsNET(model_ns, model_s)
	local NET_Result = {}

	for y = model_ns.yearInit, model_s.yearInit - 1, 1 do
		NET_Result[y] = {
							NET_CO2_1stOrder = model_ns.NET_Result[y].NET_CO2_1stOrder,
							NET_CO2_2ndOrder = model_ns.NET_Result[y].NET_CO2_2ndOrder
						}
	end

	for y = model_s.yearInit, model_s.yearFinal, 1 do
		NET_Result[y] = {
							NET_CO2_1stOrder = model_ns.NET_Result[y].NET_CO2_1stOrder + model_s.NET_Result[y].NET_CO2_1stOrder,
							NET_CO2_2ndOrder = model_ns.NET_Result[y].NET_CO2_2ndOrder + model_s.NET_Result[y].NET_CO2_2ndOrder
						}
	end

	return NET_Result
end

-- Handles with the Disturbance for combine model.
-- @arg model_ns A non-spatial INPE-EM model.
-- @arg model_s A spatial INPE-EM model.
-- @usage --DONTRUN
-- inpeEM_combine_D(model_ns, model_s)
function inpeEM_combine_D(model_ns, model_s)
	local D_Result = {}
	
	for y = model_ns.yearInit, model_s.yearInit - 1, 1 do
		D_Result[y] = {
						D_Area = model_ns.D_Result[y].D_Area,
						D_AreaAcc = model_ns.D_Result[y].D_AreaAcc
					  }
	end

	for y = model_s.yearInit, model_s.yearFinal, 1 do
		D_Result[y] = {
						D_Area = model_s.D_Result[y].D_Area,
						D_AreaAcc = model_s.D_Result[y].D_AreaAcc
					  }
	end
	
	return D_Result
end
