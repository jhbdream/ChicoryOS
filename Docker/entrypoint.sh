#!/usr/bin/env bash

cd /root/Synestia || exit 1

rm -rf _build
mkdir _build
cd _build || exit 1

_BUILD_TYPE="${BUILD_TYPE:=Release}"
cmake -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_BUILD_TYPE="$_BUILD_TYPE" -DCMAKE_TOOLCHAIN_FILE=/root/Synestia/CMake/Toolchain/ToolchainClang.cmake ..
cmake --build . --config "$_BUILD_TYPE"
