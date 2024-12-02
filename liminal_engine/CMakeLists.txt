cmake_minimum_required(VERSION 3.27)
project(liminal_engine C)
set(CMAKE_C_STANDARD 11)

# Add GLAD
add_library(glad STATIC vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

# Add GLFW
add_subdirectory(vendor/glfw) # Assumes vendor/glfw has its own CMakeLists.txt

add_library(liminal_engine src/liminal.c)

# Include directories
target_include_directories(
        liminal_engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
        vendor/glfw/include
        vendor/glad/include
        src
)

# Link dependencies
if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(CORE_FOUNDATION_LIBRARY CoreFoundation)
    find_library(OPENGL_LIBRARY OpenGL REQUIRED)

    # Link Mac-specific frameworks along with OpenGL and other libraries
    target_link_libraries(liminal_engine PRIVATE
            glad
            glfw
            ${COCOA_LIBRARY}
            ${IOKIT_LIBRARY}
            ${CORE_FOUNDATION_LIBRARY}
            ${OPENGL_LIBRARY}
    )
else()
    # Fallback for non-Mac systems
    target_link_libraries(liminal_engine PRIVATE
            glad
            glfw
            OpenGL::GL
    )
endif()
