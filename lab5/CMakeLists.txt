cmake_minimum_required(VERSION 3.10)
project(Lab5)

# Установка стандартов C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Укажите директорию с заголовочными файлами
include_directories(include)

# Добавьте исполняемый файл для основного приложения
add_executable(main_file main.cpp)

# Добавьте исполняемый файл для тестов
enable_testing()
add_executable(test_file test.cpp)

# Подключаем Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Линкуем Google Test с тестами
target_link_libraries(test_file GTest::GTest GTest::Main)

# Если вы хотите автоматически запускать тесты после сборки, добавьте:
add_test(NAME MyTests COMMAND test_file)
