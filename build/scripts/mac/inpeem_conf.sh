#!/bin/bash

if [ "$_INPEEM_BUILD_DIR" == "" ]; then
	_INPEEM_BUILD_DIR=$(pwd)/build
fi
export _INPEEM_BUILD_DIR=$_INPEEM_BUILD_DIR

if [ "$_INPEEM_INSTALL_DIR" == "" ]; then
	_INPEEM_INSTALL_DIR=$(pwd)/install
fi
export _INPEEM_INSTALL_DIR=$_INPEEM_INSTALL_DIR

if [ "$_INPEEM_BUILD_TYPE" == "" ]; then
	_INPEEM_BUILD_TYPE=Release
fi
export _INPEEM_BUILD_TYPE=$_INPEEM_BUILD_TYPE

if [ "$_INPEEM_BUILD_AS_BUNDLE" == "" ]; then
	_INPEEM_BUILD_AS_BUNDLE=ON
fi
export _INPEEM_BUILD_AS_BUNDLE=$_INPEEM_BUILD_AS_BUNDLE

if [ "$_INPEEM_CREATE_INSTALLER" == "" ]; then
	_INPEEM_CREATE_INSTALLER=OFF
fi
export _INPEEM_CREATE_INSTALLER=$_INPEEM_CREATE_INSTALLER

if [ "$_INPEEM_TERRAME_DIR" == "" ]; then
	_INPEEM_TERRAME_DIR=/Users/developer/inpeem/3rdparty/terrame
fi
export _INPEEM_TERRAME_DIR=$_INPEEM_TERRAME_DIR

if [ "$_Qt5_DIR" == "" ]; then
	_Qt5_DIR=/Users/developer/Qt5.6.0/5.6/clang_64/lib/cmake
fi
export _Qt5_DIR=$_Qt5_DIR

if ! command -v qmake &> /dev/null; then
    export PATH=$PATH:/Users/developer/Qt5.6.0/5.6/clang_64/bin
fi

if ! command -v cmake &> /dev/null; then
    export PATH=$PATH:export PATH=$PATH:/Applications/CMake.app/Contents/bin
fi

export _INPEEM_SOLUTION_DIR=$(pwd)

mkdir $_INPEEM_BUILD_DIR
cd $_INPEEM_BUILD_DIR

if [ "$_INPEEM_GIT_DIR" == "" ]; then
	_INPEEM_GIT_DIR=../../git/inpeem
fi
export _INPEEM_GIT_DIR=$_INPEEM_GIT_DIR

cmake -G "Xcode" -C $_INPEEM_GIT_DIR/build/cmake/inpeem_build_conf.cmake $_INPEEM_GIT_DIR/build/cmake
cmake --build . --target install --config $_INPEEM_BUILD_TYPE

if [ "$_INPEEM_CREATE_INSTALLER" == "ON" ]; then
	cpack -D CPACK_GENERATOR="DragNDrop" -C Release --config ./CPackConfig.cmake
fi

cd $_INPEEM_SOLUTION_DIR
