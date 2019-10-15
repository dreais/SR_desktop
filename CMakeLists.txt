cmake_minimum_required(VERSION 3.13)
project(SR_desktop C)

set(CMAKE_C_STANDARD 11)

add_executable(SR_desktop Sources/main.c Header/core_sr_desktop.h Header/soundio.h Header/endian.h)

if (WIN32)
    target_link_libraries(SR_desktop ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/libsoundio.a
            ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/liblatency.dll.a
            ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/libsoundio.dll.a
            ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/libunit_tests.dll.a)
endif(WIN32)

if (UNIX)
    target_compile_options(SR_desktop PRIVATE -Wall -Wextra -g -O0)
    target_link_libraries(SR_desktop soundio)
endif (UNIX)