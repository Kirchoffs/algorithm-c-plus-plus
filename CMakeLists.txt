cmake_minimum_required(VERSION 2.8.12)

project(algorithm-c-plus-plus)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

include_directories(${INCLUDE_DIR})

file(GLOB SRC_FILES ${SRC_DIR}/*.cpp)
add_library(algorithm_library ${SRC_FILES})

enable_testing()

add_executable(binary_search_tree_test ${TEST_DIR}/binary_search_tree_test.cpp)
target_link_libraries(binary_search_tree_test algorithm_library)
add_test(
    NAME binary_search_tree_test
    COMMAND $<TARGET_FILE:binary_search_tree_test>
)
