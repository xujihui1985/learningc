project(unittest)

set(HEADER_FILES lib.h)
set(SOURCE_FILES lib.c)

option(UNDER_TEST "compile for testing" OFF)

add_library(unittest_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
add_library(unittest_lib_test STATIC ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(unittest_lib_test PROPERTIES COMPILE_FLAGS "-DUNDER_TEST")
