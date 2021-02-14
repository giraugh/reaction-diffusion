cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

project(reaction_diffusion CXX C)

add_library(core
    ./src/core.cpp)

add_executable(main
    ./src/main.cpp)

target_link_libraries(main
    core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
