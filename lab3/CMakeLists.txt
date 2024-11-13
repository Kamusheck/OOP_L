cmake_minimum_required(VERSION 3.10)
project(lab3)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)

# Включение папки include в пути для заголовочных файлов
include_directories(include)

# Подключение всех исходников
add_executable(lab3
    src/hexagon.cpp
    src/method.cpp
    src/pentagon.cpp
    src/romb.cpp
    main.cpp
)

# Подключение тестов, если они присутствуют
add_executable(tests tests.cpp)

# Добавляем все необходимые зависимости для работы с тестами
enable_testing()
add_test(NAME tests COMMAND tests)

# Настройка Docker контейнера для разработки
add_custom_target(devcontainer DEPENDS lab3 tests)
