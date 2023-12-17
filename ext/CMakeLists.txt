cmake_minimum_required(VERSION 3.8)
include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 10.1.1
)

FetchContent_MakeAvailable(fmt)