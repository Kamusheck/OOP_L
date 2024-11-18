cmake_minimum_required(VERSION 3.10)
project(LabWork1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

find_package(GTest QUIET)
if(NOT GTest_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
    TLS_VERIFY false
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif()

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${INCLUDE_DIR})

file(GLOB_RECURSE LIB_HEADERS "${INCLUDE_DIR}/*.hpp")
file(GLOB_RECURSE LIB_SOURCES "${SRC_DIR}/*.cpp")

add_library(lab3_lib ${LIB_HEADERS} ${LIB_SOURCES})

add_executable(main_file_exe main.cpp)
target_link_libraries(main_file_exe PRIVATE lab3_lib)

enable_testing()

function(add_gtest_executable TEST_NAME TEST_SRC)
    add_executable(${TEST_NAME} ${TEST_SRC})
    target_link_libraries(${TEST_NAME} GTest::GTest GTest::Main lab3_lib)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction()

add_gtest_executable(shape_tests ${TEST_DIR}/shape_tests.cpp)