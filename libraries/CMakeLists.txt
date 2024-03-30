cmake_minimum_required(VERSION 3.23)

set(project "heroes and spells")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        h&s.cpp)

set(${project}_HEADERS
        heroes.h spells.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
