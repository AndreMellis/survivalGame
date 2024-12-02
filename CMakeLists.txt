cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("bin/headers" "bin/sources")

project(survivalGame VERSION 1.0)

set(SOURCES bin/sources/MainMap.cpp bin/sources/Plant.cpp bin/sources/Tree.cpp bin/sources/Forest.cpp bin/sources/Engine.cpp bin/sources/Menus.cpp bin/sources/Actions.cpp bin/sources/Inventory.cpp)
add_executable(survivalGame.out main.cpp ${SOURCES})
