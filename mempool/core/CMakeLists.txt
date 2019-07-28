
add_library(core "" )

target_sources(
        core
        PRIVATE
            pool.c
            log.c
            mempool.c
        INTERFACE
            pool.h
            log.h
            mempool.h
)

target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
