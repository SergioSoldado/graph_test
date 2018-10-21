cmake_minimum_required(VERSION 3.10)
set(PROJECT_TEST_NAME unit_tests)
project(${PROJECT_TEST_NAME})


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()

set(TEST_SRC_FILES
        digraph.cpp
        op/binary.cpp
        )

add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})

target_link_libraries(${PROJECT_TEST_NAME} arm gtest gtest_main)
