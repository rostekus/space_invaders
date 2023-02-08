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

#TESTs

find_package (Boost 1.65.0 COMPONENTS "unit_test_framework" REQUIRED)



include_directories(

        ${CMAKE_CURRENT_SOURCE_DIR}/include

        ${Boost_INCLUDE_DIRS}

)



#TESTs

find_package (Boost 1.65.0 COMPONENTS "unit_test_framework" REQUIRED)



include_directories(

        ${CMAKE_CURRENT_SOURCE_DIR}/include

        ${Boost_INCLUDE_DIRS}

)



#Test source files here

set(SOURCE_TEST_FILES

        test/master.cpp
        test/TestGame.cpp
        test/TestMissile.cpp
        test/TestEnemy.cpp
        test/TestPlayer.cpp
        test/TestBoard.cpp
        src/drawable.cpp
        src/enemy.cpp
        src/missile.cpp
        src/player.cpp
        src/gameboard.cpp
        src/game.cpp
        )



add_executable(TestProject ${SOURCE_TEST_FILES})
target_link_libraries(TestProject ncurses)


target_include_directories(TestProject PUBLIC include)



target_link_libraries (TestProject

        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})



enable_testing()



add_test(NAME Test COMMAND TestProject

        --report_level=detailed

        --log_level=all

        --color_output=yes)



add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all

        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose

        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
