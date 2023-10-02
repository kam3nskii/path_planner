set(EXAMPLE_TARGET ${PROJECT_NAME}_example_simple_path)

add_executable(${EXAMPLE_TARGET} src/main.cpp)

target_include_directories(${EXAMPLE_TARGET}
    PRIVATE ${${PROJECT_NAME}_INCLUDE_DIR})

target_link_libraries(${EXAMPLE_TARGET}
    ${PROJECT_NAME}
    fmt
)
