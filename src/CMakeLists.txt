# Fetch rapidxml
FetchContent_Declare(
    rapidxml
    URL https://sourceforge.net/projects/rapidxml/files/rapidxml/rapidxml%201.13/rapidxml-1.13.zip/download
    )
FetchContent_MakeAvailable(rapidxml)

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
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${rapidxml_SOURCE_DIR}
    )

target_compile_features(
    gpx-parser
    PRIVATE cxx_std_11
    )

target_compile_options(
    gpx-parser
    PRIVATE -Wall -Wextra -O2
    )
