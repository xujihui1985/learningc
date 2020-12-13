project(unittest_tests LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)

add_executable(unittest_tests_run LibTests.cpp)
target_link_libraries(unittest_tests_run unittest_lib_test)