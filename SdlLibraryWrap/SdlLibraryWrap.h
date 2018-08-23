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
	SDL_Event		event;
	Uint32			ticks;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
public:
					SdlLibraryWrap() = delete;
					SdlLibraryWrap(int w, int h);
					~SdlLibraryWrap();
					SdlLibraryWrap(const SdlLibraryWrap &sdl);
	SdlLibraryWrap	&operator=(const SdlLibraryWrap &sdl);

	void 			RenderMap(const std::vector<std::vector<int>> &game_map) final;
	int				RunLib(const std::vector<std::vector<int>> &game_map,
						   const std::vector<std::pair<int, int>> &snake_parts,
						   int x_food,
						   int y_food) final;
	int 			HandleInput(void) final;
	void 			RenderSnake(const std::vector<std::pair<int, int>> &snake_parts);


};


#endif //NIBBLER_SDLLIBRARYWRAP_H
