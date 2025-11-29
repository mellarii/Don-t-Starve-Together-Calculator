cmake_minimum_required(VERSION 3.12)

project(DSTCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main_app boss.cpp characters.cpp effects.cpp weapon.cpp main.cpp)

target_compile_options(main_app PRIVATE "-O2" "-Wall" "-Wextra")