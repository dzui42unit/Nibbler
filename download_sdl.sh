#!/bin/sh

pkg="sdl2"

if brew list -1 | grep -q "^${pkg}\$"; then
    echo "Package '$pkg' is installed"
else
   # echo "Package '$pkg' is not installed"
    brew install sdl2
fi

echo " debug ------ next step -----"

ln -s ~/.brew/Cellar/sdl2/*/include/SDL2 libs/sdl
ln -s ~/.brew/Cellar/sdl2/*/lib/ libs/sdl

#cp -R  ~/.brew/Cellar/sdl2/2.0.8/include/ myproject/include




