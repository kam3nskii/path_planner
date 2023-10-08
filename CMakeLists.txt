cmake_minimum_required(VERSION 3.20.0)

project(path_planner CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -Werror -Wall -Wextra -Wpedantic
)

if(FIND_PACKAGES)
    find_package(fmt REQUIRED)
    find_package(GTest REQUIRED)
else()
    add_subdirectory(third_party)
endif()

if(CODE_COVERAGE)
    if(${CMAKE_BUILD_TYPE} MATCHES Debug)
        add_compile_options(-O0 --coverage)
        add_link_options(--coverage)
        message(STATUS "CODE_COVERAGE enabled")
    else()
        message(FATAL_ERROR "CODE_COVERAGE can be enabled only for Debug build")
    endif()
endif()

set(${PROJECT_NAME}_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
add_subdirectory(src)

add_subdirectory(examples/${PROJECT_NAME})

enable_testing()
add_subdirectory(tests)
