---------------------------------------------------------------
-- This file contains a INPE-EM APPLICATION MODEL definition
--              Compatible with INPE-EM 4.0.0
--       Generated with INPE-EM Model Configurator
--                 7/9/2020 at 2:25:47 PM
---------------------------------------------------------------

import("inpeem")

local x = os.clock()
--------------------------------------------------------------
-- Creating Terraview Project                               --
--------------------------------------------------------------

import("gis")

proj = Project {
	file = "t3mp.tview",
	clean = true
}

l1 = Layer {
	project = proj,
	name = "layer_name",
	file = "amzCs5km_netemissions_epsg5880.shp"
}

--------------------------------------------------------------
-- INPE-EM Model                                            --
--------------------------------------------------------------

MODELDIR = currentDir()
dofile(MODELDIR.."amzregrowrates_submodel.lua")
dofile(MODELDIR.."amzregrowrates_nsdata.lua")

--------------------------------------------------------------
-- INPE-EM NON SPATIAL MODEL DEFINITION                     --
--------------------------------------------------------------
nonSpatialModel =
{
	name = "amzRegrowRatesNS",

	yearInit = 1960,
	yearFinal = 2016,

	componentB = B1,
	componentD = D1,
	componentVR = VR1,
	componentSV = SV1,
	componentDEGRAD = DG1,

	dataTable = NSDATA1,
	area = 511975000,

	mode = "non_spatial",
	verbose = true
}
--------------------------------------------------------------
-- INPE-EM SPATIAL MODEL DEFINITION                         --
--------------------------------------------------------------
spatialModel =
{
	name = "amzRegrowRatesS",

	yearInit = 2007,
	yearFinal = 2016,
	cellarea = 2500,

	componentB = B1,
	componentD = D1,
	componentVR = VR1,
	componentSV = SV1,
	componentDEGRAD = DG1,

	project = "t3mp.tview",
	layer = "layer_name",

	mode = "spatial",
	verbose = true,
	save = false
}
--------------------------------------------------------------
-- INPE-EM COMBINE MODEL DEFINITION                         --
--------------------------------------------------------------
combineModel =
{
	name = "amzRegrowRates",

	model_ns = nonSpatialModel,
	model_s = spatialModel,

	mode = "combine",
	verbose = true,
}

inpeEM_execute(combineModel)

local projFile = File("t3mp.tview")
if(projFile:exists()) then
	projFile:delete()
end

-- Calculating execution time --
local sTime = os.clock() - x
local days = math.floor(sTime / 86400)
local hours = math.floor(sTime % 86400 / 3600)
local minutes = math.floor(sTime % 3600 / 60)
local seconds = math.floor(sTime % 60)
if seconds < 59 then
	seconds = seconds + 1
end
print(string.format("\nElapsed time : %.2d : %.2d : %.2d hh : mm:ss", hours, minutes, seconds))
print("\nEnd of Script")

