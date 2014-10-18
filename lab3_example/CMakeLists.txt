cmake_minimum_required(VERSION 2.8.4)
project(lab3_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main.h)
add_executable(lab3_example ${SOURCE_FILES})