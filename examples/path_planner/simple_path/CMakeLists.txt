set(EXAMPLE_TARGET ${PROJECT_NAME}_example_simple_path)

add_executable(${EXAMPLE_TARGET} src/main.cpp)

target_link_libraries(${EXAMPLE_TARGET}
    ${PROJECT_NAME}
    fmt::fmt
)
