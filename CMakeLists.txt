cmake_minimum_required(VERSION 3.12)
project(arm)

# compiler configurations
set(CMAKE_CXX_STANDARD 17)
add_definitions(-Wall -Wextra -Wpedantic)

# 3rd party dependencies
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/3rdparty)


# sources and targets
include_directories(include)
set(ARM_SOURCES
        include/arm/op/binary.hpp
        include/arm/digraph.hpp
        src/arm/digraph.cpp
        )

add_library(arm ${ARM_SOURCES})

# testing
add_subdirectory(${EXT_PROJECTS_DIR}/gtest)
add_subdirectory(tests)
