cmake_minimum_required(VERSION 3.20.0)

project(path_planner CXX)

set(${PROJECT_NAME}_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
add_subdirectory(src)

add_subdirectory(examples/${PROJECT_NAME})
