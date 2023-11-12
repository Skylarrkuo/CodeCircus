cmake_minimum_required(VERSION 3.26)
project()

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        ALGraph.h
        AMGraph.h
        main.cpp)
