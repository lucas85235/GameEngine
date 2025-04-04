# Find all files
file(GLOB ROOT_SOURCE
    "${PROJECT_SOURCE_DIR}/src/core/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/graphics/*.cpp"
)

# Create lib
add_library(EngineCore ${ROOT_SOURCE})

# Find Includes
target_include_directories(EngineCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../includes)

# Link libraries
target_link_libraries(EngineCore 
    glfw
    glad
    tinyobjloader
)
