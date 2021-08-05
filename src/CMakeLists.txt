# Optionally glob, ut only for CMake 3.12 or later:
set(
    HEADER_LIST
    "${CMAKE_SOURCE_DIR}/include/gpx/gpx-parser.h"
    )

add_library(
    gpx-parser
    STATIC
    gpx-parser.cc
    ${HEADER_LIST}
    )

target_include_directories(
    gpx-parser
    PUBLIC ${CMAKE_SOURCE_DIR}/include
    )

target_compile_features(
    gpx-parser
    PRIVATE cxx_std_11
    )

target_compile_options(
    gpx-parser
    PRIVATE -Wall -Wextra -O2
    )
