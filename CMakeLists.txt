cmake_minimum_required(VERSION 3.28)

project(
    mp-audio
    VERSION 0.0.1
    DESCRIPTION "MP Audio process library"
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
add_subdirectory(example)
