if "%_INPEEM_GIT_DIR%" == "" (
	set _INPEEM_GIT_DIR=..\..\git\inpeem
)

if "%_INPEEM_BUILD_DIR%" == "" (
	set _INPEEM_BUILD_DIR=%CD%\build
)

if "%_INPEEM_INSTALL_DIR%" == "" (
  set _INPEEM_INSTALL_DIR=%CD%\install
)

if "%_INPEEM_BUILD_TYPE%" == "" (
  set _INPEEM_BUILD_TYPE=Release
)

if "%_INPEEM_BUILD_AS_BUNDLE%" == "" (
  set _INPEEM_BUILD_AS_BUNDLE=ON
)

if "%_INPEEM_CREATE_INSTALLER%" == "" (
  set _INPEEM_CREATE_INSTALLER=ON
)

if "%_INPEEM_TERRAME_DIR%" == "" (
  set _INPEEM_TERRAME_DIR=D:/inpe-em/3rdparty/terrame
)

if "%_Qt5_DIR%" == "" (
  set _Qt5_DIR=C:\Qt\5.14\5.14.2\msvc2017_64
)

set _INPEEM_SOLUTION_DIR=%CD%

mkdir %_INPEEM_BUILD_DIR%
cd %_INPEEM_BUILD_DIR%

xcopy /Y %_INPEEM_GIT_DIR%\build\scripts\win\inpeem-conf.cmake %_INPEEM_BUILD_DIR%

cmake -G "Visual Studio 15 2017 Win64" -C inpeem-conf.cmake %_INPEEM_GIT_DIR%\build\cmake
cmake --build . --target INSTALL --config %_INPEEM_BUILD_TYPE%

if "%_INPEEM_CREATE_INSTALLER%" == "ON" (
	cmake --build . --target PACKAGE --config Release
)

cd %_INPEEM_SOLUTION_DIR%
