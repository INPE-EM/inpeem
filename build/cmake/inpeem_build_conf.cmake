set(CMAKE_BUILD_TYPE "$ENV{_INPEEM_BUILD_TYPE}" CACHE PATH "Build Type" FORCE)
set(CMAKE_INSTALL_PREFIX "$ENV{_INPEEM_INSTALL_DIR}" CACHE PATH "INPE-EM install path" FORCE)
set(INPEEM_BUILD_AS_BUNDLE $ENV{_INPEEM_BUILD_AS_BUNDLE} CACHE BOOL "Generate a bundle application" FORCE)
set(INPEEM_CREATE_INSTALLER $ENV{_IMPEEM_CREATE_INSTALLER} CACHE BOOL "Create the installer" FORCE)
set(INPEEM_TERRAME_DIR $ENV{_INPEEM_TERRAME_DIR} CACHE BOOL "TerraME directory" FORCE)
set(Qt5_DIR "$ENV{_QT5_DIR}" CACHE PATH "Qt5" FORCE)
set(CMAKE_PREFIX_PATH "${Qt5_DIR}" CACHE PATH "Dependencies of INPE-EM" FORCE)