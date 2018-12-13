cmake_minimum_required(VERSION 2.6)
project(project4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -O2")

set(SOURCE_FILES main.cpp ladder.cpp ladder.h node.cpp node.h pair.cpp pair.h)
add_executable(project4 ${SOURCE_FILES})