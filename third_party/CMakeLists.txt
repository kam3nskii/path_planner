include(FetchContent)

# set(FETCHCONTENT_FULLY_DISCONNECTED ON)

message(STATUS "Third-party: configuring fmt")
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.1.1
)
FetchContent_MakeAvailable(fmt)

message(STATUS "Third-party: configuring googletest")
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

message(STATUS "Third-party: all done")
