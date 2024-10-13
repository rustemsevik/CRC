cmake_minimum_required(VERSION 3.5)
project(crc VERSION 1.0)

add_library(crc src/crc.c)

target_include_directories(crc PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/src/"
                            "${PROJECT_SOURCE_DIR}/include/"
                            )
target_sources(crc PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/crc.c")
target_sources(crc PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/crc_util.c")

# option for static and shared build
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# optionally build examples
option(BUILD_EXAMPLE "Build the examples" OFF)

if (BUILD_EXAMPLE)
    add_subdirectory(example)
endif()

# compiler specific options 
if(UNIX)
#     do somthing
elseif(WIN32)
#     do somthing
elseif (MSVC)
#     do somthing
endif()