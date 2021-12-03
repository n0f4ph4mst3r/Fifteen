cmake_minimum_required(VERSION 3.22)

project(PuzzleProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
else()
    message(FATAL_ERROR "NO CONANBUILDINFO.CMAKE FILE FOUND")
endif()
conan_basic_setup()

add_subdirectory(PuzzleApp)



