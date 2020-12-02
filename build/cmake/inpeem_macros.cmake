MACRO(install_plugins plugins location)
	set(_files)

	foreach(plugin ${plugins})
		get_target_property(_loc ${plugin} LOCATION)
		list(APPEND _files ${_loc})
	endforeach()

	install(FILES ${_files}
	        DESTINATION "${location}"
	        CONFIGURATIONS Release
	        COMPONENT runtime)
ENDMACRO(install_plugins)

MACRO(install_qt5_plugins location)
	find_package(Qt5 COMPONENTS Sql Svg PrintSupport)

	# Installing image plugins
	set(_plugins Qt5::QGifPlugin Qt5::QICOPlugin Qt5::QJpegPlugin Qt5::QSvgPlugin Qt5::QTiffPlugin)
	install_plugins("${_plugins}" "${location}/imageformats")

	# Installing svg plugins
	set(_plugins Qt5::QSvgPlugin Qt5::QSvgIconPlugin)
	install_plugins("${_plugins}" "${location}/iconengines")

	# Installing sql plugins
	set(_plugins Qt5::QSQLiteDriverPlugin)
	install_plugins("${_plugins}" "${location}/sqldrivers")

	# Installing printer support plugin
	if(WIN32)
		set(_plugins Qt5::QWindowsPrinterSupportPlugin)
		install_plugins("${_plugins}" "${location}/printsupport")
	endif()

	# Installing platform plugins
	if(WIN32)
		set(_plugins Qt5::QWindowsIntegrationPlugin Qt5::QMinimalIntegrationPlugin)
		install_plugins("${_plugins}" "platforms")
	elseif(APPLE)
		set(_plugins Qt5::QCocoaIntegrationPlugin Qt5::QMinimalIntegrationPlugin)
		install_plugins("${_plugins}" "${location}/platforms")
	endif()
ENDMACRO(install_qt5_plugins)

#
# Macro installQtPlugins
#
# Description: Installs the required Qt plugins.
#
# param plugs List of the names of plugins to be installed.
#
MACRO(install_qt_plugins plgs destination)
	if("${QT_PLUGINS_DIR}" STREQUAL "")
		set (QT_PLUGINS_DIR "${Qt5_DIR}/../../../plugins")
	endif()

	set(_regex_exp "")

	set(_first TRUE)

	foreach(plg ${plgs})
		if(NOT _first)
			set (_regex_exp ${_regex_exp}|${plg})
		else()
			set(_regex_exp ${plg})
			set(_first FALSE)
		endif()
	endforeach()

	set(_regex_exp "(${_regex_exp})?(${CMAKE_SHARED_LIBRARY_SUFFIX})$")

	set(_dest "${destination}")

	set(_plugin_dirs "imageformats;iconengines;sqldrivers;platforms")

	foreach(_plugin_dir ${_plugin_dirs})
		install(DIRECTORY ${QT_PLUGINS_DIR}/${_plugin_dir}
		        DESTINATION ${_dest}  COMPONENT runtime
		        FILES_MATCHING REGEX "${_regex_exp}")
	endforeach()
ENDMACRO(install_qt_plugins)
