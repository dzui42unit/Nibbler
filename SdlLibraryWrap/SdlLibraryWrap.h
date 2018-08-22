#ifndef NIBBLER_SDLLIBRARYWRAP_H
#define NIBBLER_SDLLIBRARYWRAP_H

#include "../InterfaceLibrary/InterfaceLibrary.h"
#include "../libs/sdl/SDL2/SDL.h"
#include <iostream>

class SdlLibraryWrap : public InterfaceLibrary
{
private:
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		e;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
public:
			SdlLibraryWrap();

	SdlLibraryWrap(const SdlLibraryWrap &sdl)
	{
		win = sdl.win;
		ren = sdl.ren;
	}

	SdlLibraryWrap	&operator=(const SdlLibraryWrap &sdl)
	{
		win = sdl.win;
		ren = sdl.ren;

		return (*this);
	}
};


#endif //NIBBLER_SDLLIBRARYWRAP_H
