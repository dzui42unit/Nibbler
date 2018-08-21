cmake_minimum_required(VERSION 3.9)
project(Nibbler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Nibbler main.cpp Game/Game.cpp Game/Game.h Snake/Snake.cpp Snake/Snake.h)