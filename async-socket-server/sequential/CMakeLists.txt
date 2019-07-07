cmake_minimum_required(VERSION 3.12)
project(socket-demo C)
set(CMAKE_C_STANDARD 99)

add_library(utils-objs OBJECT utils.h utils.c)

add_executable(sequential-server sequential-server.c)

add_library(utils STATIC $<TARGET_OBJECTS:utils-objs>)

target_link_libraries(sequential-server utils)


