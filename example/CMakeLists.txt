find_package(portaudio CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS circular_buffer)

add_executable(example 
    example.cpp
)

target_link_libraries(
    example
    PRIVATE
        mp-audio portaudio_static Boost::circular_buffer
)