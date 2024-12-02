# liminal_engine/examples/CMakeLists.txt
cmake_minimum_required(VERSION 3.27)
project(liminal_engine_workspace)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Add the liminal_engine library
add_subdirectory(liminal_engine)

# Add the examples
add_subdirectory(examples)