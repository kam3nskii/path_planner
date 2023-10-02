set(SRC_FILES
    ${PROJECT_NAME}/grid.cpp
    ${PROJECT_NAME}/path_planner_factory.cpp
    ${PROJECT_NAME}/path_planner.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}
    fmt
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${${PROJECT_NAME}_INCLUDE_DIR}
            ${PROJECT_SOURCE_DIR}/private_include/${PROJECT_NAME})
