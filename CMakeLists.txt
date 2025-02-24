cmake_minimum_required(VERSION 3.20)
project(GameEngine C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameEngine
    src/main.cpp
    src/core/Engine.cpp
    src/core/Window.cpp
    src/graphics/Camera.cpp
    src/graphics/Renderer.cpp
    src/graphics/Shader.cpp
    src/graphics/Mesh.cpp
)

find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/libs/glad/include)
add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)

# add_subdirectory(third_party/glfw)

# Link libraries
target_link_libraries(GameEngine 
    glfw
    OpenGL::GL
    glad
)
