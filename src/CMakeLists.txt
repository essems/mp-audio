set(SOURCES
    mp-audio.cpp
)

add_library(
    mp-audio
    SHARED
    ${SOURCES}
)

if(WIN32)
    add_definitions(-D_USE_MATH_DEFINES)
endif()

target_include_directories(
    mp-audio
    PUBLIC
        ./
)