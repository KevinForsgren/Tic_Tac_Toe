cmake_minimum_required(VERSION 4.3)
project(Terminal_Game)

set(CMAKE_CXX_STANDARD 23)

add_executable(Tic_Tac_Toe src/main.cpp
        src/terminal.cpp
        src/header/terminal.h
        src/tic_tac_toe.cpp
        src/header/tic_tac_toe.h
)
