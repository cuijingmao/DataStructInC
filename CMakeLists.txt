cmake_minimum_required(VERSION 3.16)
project(C)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        List/*.cpp
        List/*.h
        Applications/*/*.cpp
        Applications/*/*.h
        Stack/*.cpp
        Stack/*.h
        Queue/*.cpp
        Queue/*.h
        String/*.cpp
        String/*.h
        Array/*.cpp
        Array/*.h
        )

add_executable(C main.cpp  ${SOURCES})