cmake_minimum_required(VERSION 3.20)
project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

add_executable(GameEngine src/main.cpp)

# Adicionaremos bibliotecas externas aqui futuramente

add_subdirectory(third_party/glfw)
target_link_libraries(GameEngine glfw)
target_link_libraries(GameEngine glfw OpenGL::GL)
