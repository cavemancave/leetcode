# cd build; cmake ..; make; ./runTests

cmake_minimum_required(VERSION 2.6)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
project(gtest)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
AUX_SOURCE_DIRECTORY(. SRC_LIST)
ADD_EXECUTABLE(runTests ${SRC_LIST} ../28_implement-strstr/test.cpp ../28_implement-strstr/main3.c)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
