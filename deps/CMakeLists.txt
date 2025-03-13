add_subdirectory(tinyobjloader)

include_directories(${CMAKE_SOURCE_DIR}/glad/include)
add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)
