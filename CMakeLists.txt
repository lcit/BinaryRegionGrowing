cmake_minimum_required(VERSION 2.8)

project(BinaryRegionGrowing_project)

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17 -O2")
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(main main.cpp BinaryRegionGrowing.hpp)
