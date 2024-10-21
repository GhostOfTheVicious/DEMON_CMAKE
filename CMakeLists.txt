cmake_minimum_required(VERSION 3.10)

# Название проекта
project(MyServiceProject)

# Добавляем флаги для компиляции (если нужно)
set(CMAKE_CXX_STANDARD 11)

# Создаем первый таргет для empty.cpp (empty.exe)
add_executable(empty empty.cpp)

# Создаем второй таргет для service.cpp (service.exe)
add_executable(service service.cpp)

# Задаем зависимость: сначала компилируется empty.exe, затем service.exe
add_dependencies(service empty)

# Устанавливаем флаги для линковки библиотеки advapi32 (необходимо для службы на Windows)
target_link_libraries(service advapi32)
