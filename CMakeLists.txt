cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(survivalGame VERSION 1.0)

include_directories("bin/headers" "bin/sources")

#link sdl2 libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

set(SOURCES bin/sources/MainMap.cpp bin/sources/Plant.cpp bin/sources/Tree.cpp bin/sources/Forest.cpp bin/sources/Engine.cpp bin/sources/Menus.cpp bin/sources/Actions.cpp bin/sources/Inventory.cpp bin/sources/Animal.cpp bin/sources/Fish.cpp bin/sources/WindowRendering.cpp bin/sources/GameEngine.cpp)

add_executable(survivalGame.out main.cpp ${SOURCES})
target_link_libraries(survivalGame.out SDL2::SDL2 SDL2_image SDL2_ttf)
