cmake_minimum_required(VERSION 3.2)
project(GameEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB ROOT_SOURCE
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/core/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/graphics/*.cpp"
)

add_executable(GameEngine
    ${ROOT_SOURCE}
)

add_subdirectory(deps)

# copy all files on assets on the build folder
# file(COPY assets/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Link libraries
target_link_libraries(GameEngine 
    glfw
    glad
    tinyobjloader
)
