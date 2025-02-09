cmake_minimum_required(VERSION 3.20)
project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 REQUIRED)

add_library(game_engine MODULE src/bindings.cpp src/core/Engine.cpp)

target_link_libraries(game_engine PRIVATE pybind11::module)