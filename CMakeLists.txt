cmake_minimum_required(VERSION 3.4)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project)
enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)
find_package(Curses REQUIRED)
set(SOURCE_FILES
        include/config.hpp
        include/missile.hpp
        include/player.hpp
        src/main.cpp
        src/missile.cpp
        src/player.cpp
        include/gameboard.hpp
        src/gameboard.cpp
        include/drawable.hpp
        src/drawable.cpp
        include/enemy.hpp
        src/enemy.cpp include/game.hpp src/game.cpp)
add_executable(Project ${SOURCE_FILES})
target_link_libraries(Project ncurses)
target_include_directories(Project PUBLIC include )
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)