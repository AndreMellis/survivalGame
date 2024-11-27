cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("bin/headers" "bin/source")

project(survivalGame VERSION 1.0)
add_executable(survivalGame.out main.cpp)
