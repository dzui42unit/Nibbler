#!/bin/sh

pkg="sdl2"
pkg2="sdl2_image"
pkg3="sdl2_ttf"
pkg4="sdl2_mixer"
pkg5="glfw"
pkg6="sfml"
pkg7="ftgl"
pkg8="freetype"

if brew list -1 | grep -q "^${pkg}\$"; then
    echo "Package '$pkg' is installed"
else
   echo "Package '$pkg' is not installed"
   brew install sdl2
fi

if brew list -1 | grep -q "^${pkg2}\$"; then
   echo "Package '$pkg2' is installed"
else
   echo "Package '$pkg2' is not installed"
   brew install sdl2 sdl2_image
fi

if brew list -1 | grep -q "^${pkg3}\$"; then
   echo "Package '$pkg3' is installed"
else
   echo "Package '$pkg3' is not installed"
   brew install sdl2 sdl2_ttf
fi

if brew list -1 | grep -q "^${pkg4}\$"; then
   echo "Package '$pkg4' is installed"
else
   echo "Package '$pkg4' is not installed"
   brew install sdl2 sdl2_mixer
fi

if brew list -1 | grep -q "^${pkg5}\$"; then
   echo "Package '$pkg5' is installed"
else
   echo "Package '$pkg5' is not installed"
   brew install glfw3
fi

if brew list -1 | grep -q "^${pkg6}\$"; then
    echo "Package '$pkg6' is installed"
else
   echo "Package '$pkg6' is not installed"
    brew install sfml
fi

if brew list -1 | grep -q "^${pkg7}\$"; then
    echo "Package '$pkg7' is installed"
else
   echo "Package '$pkg7' is not installed"
    brew install ftgl
fi

if brew list -1 | grep -q "^${pkg8}\$"; then
    echo "Package '$pkg8' is installed"
else
   echo "Package '$pkg8' is not installed"
    brew install freetype
fi

echo "*** WELL DONE ***"
