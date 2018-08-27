cmake_minimum_required(VERSION 3.9)
project(Nibbler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Nibbler main.cpp Game/Game.cpp Game/Game.h Snake/Snake.cpp Snake/Snake.h InterfaceLibrary/InterfaceLibrary.h SdlLibraryWrap/SdlLibraryWrap.cpp SdlLibraryWrap/SdlLibraryWrap.h Fruit/Fruit.cpp Fruit/Fruit.h SoundWrapper/SoundWrapper.cpp SoundWrapper/SoundWrapper.h)