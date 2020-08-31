-- @example This example runs the greenhouse gases emission estimates model of the Amazon. 
-- The Lua files were created by INPE-EM software (http://inpe-em.ccst.inpe.br).

local function checkResults(resultsFileName)
	print("Checking "..resultsFileName)
	local resultsFile = filePath(resultsFileName, "inpeem")
	local resultsFileNew = File(resultsFileName)
	local resIOFile = io.open(tostring(resultsFile), "r")
	local resContent = resIOFile:read("*a")
	local resIOFileNew = io.open(tostring(resultsFileNew), "r")
	local resContentNew = resIOFileNew:read("*a")
	resIOFile:close()
	resIOFileNew:close()
	
	if resContent == resContentNew then
		print("Ok!")
		resultsFileNew:delete()		
	else
		print("Fail!")
	end
end

local mainFile = filePath("amzRegrowRates_main.lua", "inpeem")
local submodelFile = filePath("amzRegrowRates_submodel.lua", "inpeem")
local nsdataFile = filePath("amzRegrowRates_nsdata.lua", "inpeem")
local csFile = filePath("amzCs5km_netemissions_epsg5880.shp", "inpeem")

mainFile:copy(currentDir())
submodelFile:copy(currentDir())
nsdataFile:copy(currentDir())
csFile:copy(currentDir())

dofile("amzRegrowRates_main.lua")

checkResults("amzRegrowRates_results.txt")
checkResults("amzRegrowRatesS_results.txt")
checkResults("amzRegrowRatesNS_results.txt")

File("amzRegrowRates_main.lua"):delete()
File("amzRegrowRates_submodel.lua"):delete()
File("amzRegrowRates_nsdata.lua"):delete()
File("amzCs5km_netemissions_epsg5880.shp"):delete()
