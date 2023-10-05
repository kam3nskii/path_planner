include(GoogleTest)

set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(SRC_FILES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/grid.cpp
    ${SRC_DIR}/path_planner_factory.cpp
)

add_executable(${PROJECT_NAME}_tests ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}_tests
    ${PROJECT_NAME}
    GTest::gtest_main
)

gtest_discover_tests(${PROJECT_NAME}_tests)
