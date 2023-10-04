#!/bin/bash

BUILD_TYPE=${1:-Debug}

SCRIPT_DIR=$(dirname $(realpath ${0}))
BUILD_DIR=${SCRIPT_DIR}/build

cmake \
    -S ${SCRIPT_DIR} \
    -B ${BUILD_DIR} \
    -G "Unix Makefiles" \
    -D CMAKE_BUILD_TYPE:STRING=${BUILD_TYPE} \
    -D CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
    && cmake --build ${BUILD_DIR}
