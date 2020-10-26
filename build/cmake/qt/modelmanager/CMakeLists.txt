cmake_minimum_required(VERSION 3.12.2)

set(INPEEM_SRC_DIR ${INPEEM_ROOT_DIR}/src/qt/modelmanager)

file(GLOB INPEEM_SRC_CPP_FILES ${INPEEM_SRC_DIR}/*.cpp)
file(GLOB INPEEM_SRC_H_FILES ${INPEEM_SRC_DIR}/*.h)
file(GLOB INPEEM_SRC_UI_FILES ${INPEEM_SRC_DIR}/ui/*.ui)
file(GLOB INPEEM_SRC_TS_FILES ${INPEEM_SRC_DIR}/ts/*.ts)
source_group("Source Files" FILES ${INPEEM_SRC_CPP_FILES})
source_group("Header Files" FILES ${INPEEM_SRC_H_FILES})
source_group("UI Files" FILES ${INPEEM_SRC_UI_FILES})
source_group("TS Files" FILES ${INPEEM_SRC_TS_FILES})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

qt5_wrap_ui(INPEEM_GEN_UI_FILES ${INPEEM_SRC_UI_FILES})

qt5_add_translation(INPEEM_QM_FILES ${INPEEM_SRC_TS_FILES})
add_custom_target(translations DEPENDS ${INPEEM_QM_FILES})
get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
execute_process(COMMAND ${QT5_QMAKE_EXECUTABLE} -query QT_INSTALL_TRANSLATIONS
				OUTPUT_VARIABLE qt_translations_dir OUTPUT_STRIP_TRAILING_WHITESPACE)
file(TO_CMAKE_PATH "${qt_translations_dir}" qt_translations_dir)
set(QT_TRANSLATIONS_DIR ${qt_translations_dir} CACHE PATH "The location of the Qt translations" FORCE)			

set(INPEEM_LIBRARIES ${INPEEM_LIBRARIES} Qt5::Widgets)

file(GLOB INPEEM_APP_ICON ${INPEEM_RESOURCES_DIR}/icon.ico)
file(GLOB INPEEM_APP_IMAGE ${INPEEM_RESOURCES_DIR}/inpeem.png)

file(GLOB INPEEM_RESOURCE_FILES ${INPEEM_APP_ICON} ${INPEEM_APP_IMAGE})
source_group("Resource Files" FILES ${INPEEM_RESOURCE_FILES})

include_directories(${INPEEM_SRC_DIR}
					#${INPEEM_RESOURCES_DIR}
					${Qt5Network_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})

set(INPEEM_FILES ${INPEEM_SRC_CPP_FILES} ${INPEEM_SRC_H_FILES}
				 ${INPEEM_GEN_UI_FILES}
				 ${INPEEM_RESOURCE_FILES}
				 ${INPEEM_QM_FILES})

add_executable(${PROJECT_NAME} ${INPEEM_FILES})
target_link_libraries(${PROJECT_NAME} ${INPEEM_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

if(WIN32 AND MSVC)
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
	set_target_properties(${PROJECT_NAME} PROPERTIES RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
	set_target_properties(${PROJECT_NAME} PROPERTIES MINSIZEREL "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif()

set(CMAKE_INSTALL_DEFAULT_COMPONENT_NAME runtime)

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION . COMPONENT runtime
		LIBRARY DESTINATION . COMPONENT runtime
		ARCHIVE DESTINATION . COMPONENT runtime
		BUNDLE DESTINATION . COMPONENT runtime)

install(FILES ${INPEEM_RESOURCE_FILES}
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
set(INPEEM_PACKAGE_DIR terrame/bin/packages/inpeem)
install(DIRECTORY ${INPEEM_LUA_DIR}
		DESTINATION ${INPEEM_PACKAGE_DIR}
		COMPONENT runtime)

# install(FILES ${INPEEM_RESOURCES_DIR}/inpeem.bat
		# DESTINATION terrame/bin
		# COMPONENT runtime)

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

if(WIN32)		
	install(FILES ${Qt5_DIR}/../../../plugins/platforms/qwindowsd.dll
			DESTINATION ./platforms
			COMPONENT runtime
			CONFIGURATIONS Debug)

	install(FILES ${Qt5_DIR}/../../../plugins/platforms/qwindows.dll
			DESTINATION ./platforms
			COMPONENT runtime
			CONFIGURATIONS Release)
endif()		
		
install(FILES ${INPEEM_QM_FILES}
	DESTINATION ./langs
	COMPONENT runtime)		

configure_file(${PROJECT_SOURCE_DIR}/inpeem_version.h.in
               ${INPEEM_SRC_DIR}/Version.h @ONLY)

# configure_file(${PROJECT_SOURCE_DIR}/cpack_installer_generator.cmake.in
               # ${CMAKE_BINARY_DIR}/cpack_installer_generator.cmake @ONLY)
# set(CPACK_PROJECT_CONFIG_FILE ${CMAKE_BINARY_DIR}/cpack_installer_generator.cmake)
# include(CPack)