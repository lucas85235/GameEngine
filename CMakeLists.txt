cmake_minimum_required(VERSION 3.2)
project(GameEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(GameEngine
    "${PROJECT_SOURCE_DIR}/apps/main.cpp"
)

add_subdirectory(src)
add_subdirectory(deps)

# Link libraries
target_link_libraries(GameEngine 
    EngineCore
)
