cmake_minimum_required(VERSION 3.10)

project(ElevenSystem)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0135 NEW)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main 
    main.cpp            
    src/elevenclass.cpp   
)

add_executable(tests
    tests.cpp           
    src/elevenclass.cpp    
)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)


enable_testing()

target_link_libraries(tests gtest gtest_main)

add_test(NAME ElevenTests COMMAND tests)

