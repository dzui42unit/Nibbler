#!/bin/sh

pkg="sdl2"

if brew list -1 | grep -q "^${pkg}\$"; then
    echo "Package '$pkg' is installed"
else
  # echo "Package '$pkg' is not installed"
   brew install sdl2
fi

ln -f -s ~/.brew/Cellar/sdl2/*/include/SDL2 libs/sdl/sdl2
ln -f -s ~/.brew/Cellar/sdl2/*/lib/ libs/sdl/sdl2

pkg2="sdl2_image"
pkg3="sdl2_ttf"
pkg4="sdl2_mixer"

if brew list -1 | grep -q "^${pkg2}\$"; then
    echo "Package '$pkg2' is installed"
else
   # echo "Package '$pkg2' is not installed"
   brew install sdl2 sdl2_image
fi

if brew list -1 | grep -q "^${pkg3}\$"; then
    echo "Package '$pkg3' is installed"
else
   # echo "Package '$pkg3' is not installed"
   brew install sdl2 sdl2_ttf
fi

if brew list -1 | grep -q "^${pkg4}\$"; then
    echo "Package '$pkg4' is installed"
else
   # echo "Package '$pkg4' is not installed"
   brew install sdl2 sdl2_mixer
fi



ln -f -s ~/.brew/Cellar/sdl2_image/*/include/SDL2 libs/sdl/sdl2_image
ln -f -s ~/.brew/Cellar/sdl2_image/*/lib/ libs/sdl/sdl2_image

ln -f -s ~/.brew/Cellar/sdl2_ttf/*/include/SDL2 libs/sdl/sdl2_ttf
ln -f -s ~/.brew/Cellar/sdl2_ttf/*/lib/ libs/sdl/sdl2_ttf

ln -f -s ~/.brew/Cellar/sdl2_mixer/*/include/SDL2 libs/sdl/sdl2_mixer
ln -f -s ~/.brew/Cellar/sdl2_mixer/*/lib/ libs/sdl/sdl2_mixer

echo "*** WELL DONE ***"
