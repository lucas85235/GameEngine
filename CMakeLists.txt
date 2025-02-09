cmake_minimum_required(VERSION 3.20)
project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameEngine
    src/main.cpp
    src/core/Engine.cpp
    src/core/Window.cpp
)

find_package(OpenGL REQUIRED)

add_subdirectory(third_party/glfw)

# Linkando bibliotecas necessárias
target_link_libraries(GameEngine glfw)
target_link_libraries(GameEngine glfw OpenGL::GL)
