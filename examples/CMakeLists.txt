cmake_minimum_required(VERSION 3.27)
project(examples C)

set(CMAKE_C_STANDARD 11)

add_executable(examples main.c)

target_link_libraries(examples PRIVATE liminal_engine)