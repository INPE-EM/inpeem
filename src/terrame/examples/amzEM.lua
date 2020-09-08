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

local mainFile = filePath("amzEM_main.lua", "inpeem")
local submodelFile = filePath("amzEM_submodel.lua", "inpeem")
local nsdataFile = filePath("amzEM_nsdata.lua", "inpeem")
local csFile = filePath("amzCs5km_epsg29101.shp", "inpeem")

mainFile:copy(currentDir())
submodelFile:copy(currentDir())
nsdataFile:copy(currentDir())
csFile:copy(currentDir())

dofile("amzEM_main.lua")

checkResults("amzEM_results.txt")
checkResults("amzEMS_results.txt")
checkResults("amzEMNS_results.txt")

File("amzEM_main.lua"):delete()
File("amzEM_submodel.lua"):delete()
File("amzEM_nsdata.lua"):delete()
File("amzCs5km_epsg29101.shp"):delete()
