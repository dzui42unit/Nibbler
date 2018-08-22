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
					SdlLibraryWrap() = delete;
					SdlLibraryWrap(int w, int h);
					SdlLibraryWrap(const SdlLibraryWrap &sdl);
	void 			RenderMap(const std::vector<std::vector<int>> &game_map) final;
	SdlLibraryWrap	&operator=(const SdlLibraryWrap &sdl);
};


#endif //NIBBLER_SDLLIBRARYWRAP_H
