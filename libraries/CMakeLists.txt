cmake_minimum_required(VERSION 3.23)

set(project "libraries")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        heroes.cpp 
        behaviour.cpp
        basic_actions.cpp)

set(${project}_HEADERS
        heroes.h 
        basic_actions.h 
        colors.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
