cmake_minimum_required (VERSION 2.8)
project (arduino-nanopb)

message ("building arduino-nanopb")
file(GLOB SRC *.c *.cpp *.h *.hpp)

add_library(arduino-nanopb STATIC ${SRC})

target_include_directories(PUBLIC .)

set_target_properties( arduino-nanopb
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin"
)

add_dependencies(arduino-nanopb)
add_library(arduino-nanopb)
target_link_libraries(arduino-nanopb)
