cmake_minimum_required(VERSION 2.6)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
project(test)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(test main3.c test.cpp )
target_link_libraries(test ${GTEST_LIBRARIES} pthread)
