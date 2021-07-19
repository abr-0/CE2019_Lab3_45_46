cmake_minimum_required(VERSION 3.10)

project(arrayBST)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_executable(arrayBST src/main.cpp src/arrayBSTdef.cpp)