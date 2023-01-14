cmake_minimum_required(VERSION 3.20)
project(space_invaders)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(space_invaders
        include/enemy.h
        include/game.h
        include/missile.h
        include/player.h
        include/ship.h
        src/enemy.cpp
        src/game.cpp
        src/main.cpp
        src/missile.cpp
        src/player.cpp
        src/ship.cpp)
