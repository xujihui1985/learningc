cmake_minimum_required(VERSION 3.17)
project(unittest C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib)
add_subdirectory(test)

add_executable(unittest main.c)
target_link_libraries(unittest unittest_lib)