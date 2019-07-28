cmake_minimum_required(VERSION 3.14)
project(mempool C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(core)

add_executable(mempool main.c)

target_link_libraries(mempool PRIVATE core)
