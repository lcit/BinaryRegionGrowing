# cmake needs this line
cmake_minimum_required(VERSION 2.8)

# Define project name
project(BinaryRegionGrowing_project)

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++14 -O2")
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include_directories(..)

# Declare the executable target built from your sources
add_executable(test_performance test_performance.cpp)

# Link your application with OpenCV libraries
target_link_libraries(test_performance)
