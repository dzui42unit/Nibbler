cmake_minimum_required(VERSION 3.9)
project(Nibbler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Nibbler main.cpp Game/Game.cpp Game/Game.h Snake/Snake.cpp Snake/Snake.h InterfaceLibrary/InterfaceLibrary.h InterfaceSoundLib/InterfaceSoundLib.h libs/sdl/SdlLibraryWrap/SdlLibraryWrap.cpp libs/sdl/SdlLibraryWrap/SdlLibraryWrap.h Fruit/Fruit.cpp Fruit/Fruit.h libs/SoundWrapper/SoundWrapper.cpp libs/SoundWrapper/SoundWrapper.h libs/glfw3/Glfw3Wrapper.cpp libs/glfw3/Glfw3Wrapper.h)