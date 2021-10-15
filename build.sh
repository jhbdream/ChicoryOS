#!/usr/bin/env bash

export CC=clang
export CXX=clang++
export LD=lld

rm -rf Build
mkdir Build
cd Build || exit 1

_BUILD_TYPE="${BUILD_TYPE:=Release}"
cmake -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_BUILD_TYPE="$_BUILD_TYPE" -DCMAKE_TOOLCHAIN_FILE=./CMake/Toolchain/ToolchainClang.cmake ..
cmake --build . --config "$_BUILD_TYPE"
