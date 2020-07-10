cmake_minimum_required(VERSION 3.12.2)

include(CSharpUtilities)

if(NOT WIN32 AND MSVC)
	message(FATAL_ERROR "This project works only on Windows and Visual Studio.")
endif()

project(INPE-EM)

set(INPEEM_VERSION_MAJOR 4)
set(INPEEM_VERSION_MINOR 0)
set(INPEEM_VERSION_PATCH 0)

set(INPEEM_VERSION "${INPEEM_VERSION_MAJOR}.${INPEEM_VERSION_MINOR}.${INPEEM_VERSION_PATCH}")

get_filename_component(INPEEM_ROOT_DIR "../../" ABSOLUTE)

set(INPEEM_SRC_DIR ${INPEEM_ROOT_DIR}/src/cppcli)
include_directories(${INPEEM_SRC_DIR})

set(INPEEM_RESOURCES_DIR ${INPEEM_ROOT_DIR}/resources)
include_directories(${INPEEM_RESOURCES_DIR})

file(GLOB INPEEM_SRC_CPP_FILES ${INPEEM_SRC_DIR}/*.cpp)
file(GLOB INPEEM_SRC_H_FILES ${INPEEM_SRC_DIR}/*.h)
file(GLOB INPEEM_SRC_RESX_FILES ${INPEEM_SRC_DIR}/*.resx)
source_group("Source Files" FILES ${INPEEM_SRC_CPP_FILES})
source_group("Header Files" FILES ${INPEEM_SRC_H_FILES})

file(GLOB INPEEM_APP_ICON ${INPEEM_RESOURCES_DIR}/icon.ico)
file(GLOB INPEEM_APP_ICON_RC ${INPEEM_RESOURCES_DIR}/LuccME.rc)

file(GLOB INPEEM_RESOURCE_FILES ${INPEEM_APP_ICON} ${INPEEM_APP_ICON_RC})
source_group("Resource Files" FILES ${INPEEM_RESOURCE_FILES})

set(INPEEM_FILES ${INPEEM_SRC_CPP_FILES} ${INPEEM_SRC_H_FILES} ${INPEEM_SRC_RESX_FILES}
				 ${INPEEM_RESOURCE_FILES})

add_executable(${PROJECT_NAME} WIN32 ${INPEEM_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:main")
set_target_properties(${PROJECT_NAME} PROPERTIES MINSIZEREL "/SUBSYSTEM:WINDOWS /ENTRY:main")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
set_target_properties(${PROJECT_NAME} PROPERTIES RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")

set_property(TARGET ${PROJECT_NAME} PROPERTY COMMON_LANGUAGE_RUNTIME "")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_GLOBAL_ROOTNAMESPACE "INPEEM")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_CONFIGURATION_CLRSupport "true")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_GLOBAL_CLRSupport "true")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_GLOBAL_KEYWORD "ManagedCProj")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.5.2")
set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE TRUE)
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES
	"System"
	"System.Data"
	"System.Drawing"
	"System.Windows.Forms"
	"System.Xml")

csharp_set_windows_forms_properties(
	${INPEEM_SRC_CPP_FILES}
	${INPEEM_SRC_H_FILES}
	${INPEEM_SRC_RESX_FILES}
)

set(CMAKE_INSTALL_DEFAULT_COMPONENT_NAME runtime)

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION . COMPONENT runtime
		LIBRARY DESTINATION . COMPONENT runtime
		ARCHIVE DESTINATION . COMPONENT runtime
		BUNDLE DESTINATION . COMPONENT runtime)

install(FILES ${INPEEM_APP_ICON}
		DESTINATION .
		COMPONENT runtime)

set(INPEEM_DOC_DIR ${INPEEM_ROOT_DIR}/doc)
file(GLOB INPEEM_DOC_FILES ${INPEEM_DOC_DIR}/*.chm)
install(FILES ${INPEEM_DOC_FILES}
		DESTINATION .
		COMPONENT runtime)

install(DIRECTORY ${INPEEM_TERRAME_DIR}
		DESTINATION .
		COMPONENT runtime)

set(INPEEM_LUA_DIR ${INPEEM_ROOT_DIR}/src/terrame/)
set(INPEEM_PACKAGE_DIR TerraME/bin/packages/inpeem)
install(DIRECTORY ${INPEEM_LUA_DIR}
		DESTINATION ${INPEEM_PACKAGE_DIR}
		COMPONENT runtime)

install(FILES ${INPEEM_RESOURCES_DIR}/inpeem.bat
		DESTINATION TerraME/bin
		COMPONENT runtime)

set(CMAKE_INSTALL_SYSTEM_RUNTIME_DESTINATION .)
include(InstallRequiredSystemLibraries)

if(INPEEM_BUILD_AS_BUNDLE)
	configure_file(${PROJECT_SOURCE_DIR}/fixup_bundle.cmake.in
				   ${CMAKE_BINARY_DIR}/fixup_bundle.cmake @ONLY)
	install(SCRIPT ${CMAKE_BINARY_DIR}/fixup_bundle.cmake COMPONENT runtime)
endif()

configure_file(${PROJECT_SOURCE_DIR}/terrame_package_description.cmake.in
               ${CMAKE_BINARY_DIR}/description.lua @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/description.lua
		DESTINATION ${INPEEM_PACKAGE_DIR}
		COMPONENT runtime)

get_filename_component(INPEEM_AMAZON_DATA ${INPEEM_ROOT_DIR}/data/amzCs5km_epsg29101.zip ABSOLUTE)
get_filename_component(INPEEM_AMAZON_REGROW_RATES_DATA ${INPEEM_ROOT_DIR}/data/amzCs5km_netemissions_epsg5880.zip ABSOLUTE)
set(INPEEM_DATA_DIR ${CMAKE_BINARY_DIR}/data)
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${INPEEM_DATA_DIR})
execute_process(
	COMMAND ${CMAKE_COMMAND} -E tar xzvf ${INPEEM_AMAZON_REGROW_RATES_DATA}
	WORKING_DIRECTORY ${INPEEM_DATA_DIR}
)
execute_process(
	COMMAND ${CMAKE_COMMAND} -E tar xzvf ${INPEEM_AMAZON_DATA}
	WORKING_DIRECTORY ${INPEEM_DATA_DIR}
)
install(DIRECTORY ${INPEEM_DATA_DIR}
		DESTINATION ${INPEEM_PACKAGE_DIR}
		COMPONENT runtime)

configure_file(${PROJECT_SOURCE_DIR}/inpeem_version.h.in
               ${INPEEM_SRC_DIR}/INPEEMVersion.h @ONLY)

configure_file(${PROJECT_SOURCE_DIR}/cpack_installer_generator.cmake.in
               ${CMAKE_BINARY_DIR}/cpack_installer_generator.cmake @ONLY)
set(CPACK_PROJECT_CONFIG_FILE ${CMAKE_BINARY_DIR}/cpack_installer_generator.cmake)
include(CPack)