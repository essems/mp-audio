set(SOURCES
    mp-audio.cpp
)

add_library(
    mp-audio
    SHARED
    ${SOURCES}
)

target_include_directories(
    mp-audio
    PUBLIC
        ./
)