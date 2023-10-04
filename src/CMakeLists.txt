set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME})
set(SRC_FILES
    ${SRC_DIR}/grid.cpp
    ${SRC_DIR}/path_planner_factory.cpp
    ${SRC_DIR}/path_planner.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}
    fmt::fmt
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${${PROJECT_NAME}_INCLUDE_DIR}
            ${PROJECT_SOURCE_DIR}/private_include/${PROJECT_NAME})
