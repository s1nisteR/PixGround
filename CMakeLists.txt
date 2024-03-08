cmake_minimum_required(VERSION 3.20)
project(PixGround)

add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)

set(CMAKE_CXX_STANDARD 20)

add_executable(PixGround src/main.cpp
        src/Application.cpp
        include/Application.h)

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL3main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(PixGround PRIVATE SDL3::SDL3main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(PixGround PRIVATE SDL3::SDL3)