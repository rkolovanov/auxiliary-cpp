cmake_minimum_required(VERSION 3.21)
project(auxiliary_cpp)

set(CMAKE_CXX_STANDARD 23)

add_library(auxiliary_cpp SHARED library.cpp)
