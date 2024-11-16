cmake_minimum_required(VERSION 3.10)
project(Lab5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
add_executable(main_file main.cpp)

enable_testing()
add_executable(test_file test.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(test_file GTest::GTest GTest::Main)

add_test(NAME MyTests COMMAND test_file)
