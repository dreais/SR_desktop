cmake_minimum_required(VERSION 3.13)
project(SR_desktop C)

set(CMAKE_C_STANDARD 11)

add_executable(SR_desktop Sources/main.c)

if (WIN32)
    target_link_libraries(SR_desktop ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/libsoundio.a)
endif(WIN32)

if (UNIX)
    target_compile_options(SR_desktop PRIVATE -Wall -Wextra -g -O0)
    target_link_libraries(SR_desktop soundio)
endif (UNIX)