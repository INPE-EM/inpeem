-- @example This example runs the greenhouse gases emission estimates model of the Amazon. 
-- The Lua files in created by INPE-EM software (http://inpe-em.ccst.inpe.br).

local mainFile = filePath("amzEM_main.lua", "inpeem")
local submodelFile = filePath("amzEM_submodel.lua", "inpeem")
local nsdataFile = filePath("amzEM_nsdata.lua", "inpeem")
local csFile = filePath("amzCs5km_epsg29101.shp", "inpeem")

mainFile:copy(currentDir())
submodelFile:copy(currentDir())
nsdataFile:copy(currentDir())
csFile:copy(currentDir())

dofile("amzEM_main.lua")
