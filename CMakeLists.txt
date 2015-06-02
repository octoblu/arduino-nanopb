cmake_minimum_required (VERSION 2.8)
project (arduino-nanopb)
include(ExternalProject)
message ("building arduino-nanopb")
file(GLOB SRC *.c *.cpp *.h *.hpp)


ExternalProject_Add(gmock
    URL https://googlemock.googlecode.com/files/gmock-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gmock
    INSTALL_COMMAND ""
    UPDATE_COMMAND ""
)

ExternalProject_Add(gtest
    URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    INSTALL_COMMAND ""
    UPDATE_COMMAND ""
)

# Specify include dir
ExternalProject_Get_Property(gmock source_dir)
set(GMOCK_INCLUDE_DIR ${source_dir}/include)

ExternalProject_Get_Property(gtest source_dir)
set(GTEST_INCLUDE_DIR ${source_dir}/include)

ExternalProject_Add(arduino-mock
    GIT_REPOSITORY git@github.com:octoblu/arduino-mock
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}
)

# find_package(arduino-mock REQUIRED)

add_library(arduino-nanopb STATIC ${SRC})
set_target_properties( arduino-nanopb
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin"
)

include_directories(
  ${CMAKE_BINARY_DIR}/src/arduino-mock/include/arduino-mock/
  ${GMOCK_INCLUDE_DIR}
  ${GTEST_INCLUDE_DIR}
)
message("GMOCK_INCLUDES: ${GMOCK_INCLUDE_DIR}")
target_link_libraries(arduino-nanopb)
add_dependencies(arduino-nanopb arduino-mock gmock gtest)
