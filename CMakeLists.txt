cmake_minimum_required (VERSION 2.8)
project (arduino_protobuf)

message ("building arduino_protobuf")
file(GLOB SRC *.c *.cpp *.h *.hpp)

add_library(arduino_protobuf STATIC ${SRC})

set_target_properties( arduino_protobuf
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin"
)

target_link_libraries(arduino_protobuf)
