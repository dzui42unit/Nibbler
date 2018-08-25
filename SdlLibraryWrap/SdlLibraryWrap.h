#ifndef NIBBLER_SDLLIBRARYWRAP_H
#define NIBBLER_SDLLIBRARYWRAP_H

#include "../InterfaceLibrary/InterfaceLibrary.h"
#include "../libs/sdl/sdl2/SDL2/SDL.h"
#include "../libs/sdl/sdl2_image/SDL2/SDL_image.h"
#include <iostream>

class SdlLibraryWrap : public InterfaceLibrary
{
private:
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		event;
	Uint32			now;
	Uint32 			last;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
    SDL_Rect        image_texture_part;
    SDL_Texture     *border_texture;
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
