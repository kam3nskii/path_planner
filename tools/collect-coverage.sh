#!/bin/bash

set -e

SCRIPT_DIR=$(dirname $(realpath ${0}))

BUILD_DIR=${1}
if [[ -z ${BUILD_DIR} ]] ; then
    echo "Error: BUILD_DIR variable not specified"
    exit 1
fi

cd ${BUILD_DIR}
ctest --output-on-failure

COVERAGE_DIR=code_coverage
INFO_FILENAME=code_coverage.info

lcov --capture \
     --directory . \
     --gcov-tool ${SCRIPT_DIR}/llvm-gcov.sh \
     --output-file ${INFO_FILENAME} \
     --rc lcov_branch_coverage=1

lcov --remove ${INFO_FILENAME} \
    '/usr*' '*_deps*' '*tests*' \
    --output-file ${INFO_FILENAME} \
    --rc lcov_branch_coverage=1

genhtml ${INFO_FILENAME} \
    --output-directory ${COVERAGE_DIR} \
    --rc lcov_branch_coverage=1
