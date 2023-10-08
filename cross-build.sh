#!/bin/bash

SCRIPT_DIR=$(dirname $(realpath ${0}))
BUILD_DIR=${SCRIPT_DIR}/build

SUPPORTED_BUILD_TYPES=(Debug Release)

BUILD_TYPE=${SUPPORTED_BUILD_TYPES[0]}
CODE_COVERAGE=OFF
FIND_PACKAGES=OFF

while [[ $# -gt 0 ]]; do
  case $1 in
    --type)
      BUILD_TYPE=${2}
      if [[ ! "${SUPPORTED_BUILD_TYPES[@]}" =~ ${BUILD_TYPE} ]]; then
            echo "Unsupported build type ${2}"
            exit 1
      fi
      shift # past argument
      shift # past value
      ;;
    --build-dir)
      BUILD_DIR=${2}
      shift # past argument
      shift # past value
      ;;
    --coverage)
      CODE_COVERAGE=ON
      shift # past argument
      ;;
    --find-packages)
      FIND_PACKAGES=ON
      shift # past argument
      ;;
    --clean-first)
      CLEAN_FIRST=ON
      shift # past argument
      ;;
    *)
      echo "Unknown option ${1}"
      exit 1
      ;;
  esac
done

mkdir -p ${BUILD_DIR}

if [[ ${CLEAN_FIRST} == "ON" ]]; then
    rm -rf ${BUILD_DIR}/*
fi

if [[ ${CODE_COVERAGE} == "ON" ]]; then
    rm -f `find ${BUILD_DIR} -name "*.gcda"`
fi

cmake \
    -S ${SCRIPT_DIR} \
    -B ${BUILD_DIR} \
    -G "Unix Makefiles" \
    -D CMAKE_BUILD_TYPE:STRING=${BUILD_TYPE} \
    -D CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
    -D CODE_COVERAGE=${CODE_COVERAGE} \
    -D FIND_PACKAGES=${FIND_PACKAGES} \
    && cmake --build ${BUILD_DIR}
