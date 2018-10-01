#ifndef NIBBLER_SDLLIBRARYWRAP_H
#define NIBBLER_SDLLIBRARYWRAP_H

#include "InterfaceLibrary.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_audio.h"
#include "SDL2/SDL_mixer.h"

#include <iostream>

class SdlLibraryWrap : public InterfaceLibrary
{
private:
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		*event;
	Uint32			now;
	Uint32 			last;
    SDL_Rect        image_texture_part;
    SDL_Texture     *border_texture;
    SDL_Texture     *grass_texture;
    SDL_Texture     *snake_head_texture;
    SDL_Texture     *snake_body_texture;
    SDL_Texture     *super_fruit_texture;
	SDL_Texture		*game_over_screen_texture;

    SDL_Rect        head_up;
    SDL_Rect        head_right;
    SDL_Rect        head_down;
    SDL_Rect        head_left;
    SDL_Rect        rect_background;
    SDL_Rect        rect_snake_body;
    SDL_Rect        rect_food;
    SDL_Rect        rect_super_fruit;
	SDL_Rect		game_over_rect;

	TTF_Font* 		Sans;
	SDL_Surface* 	surfaceMessage;
	SDL_Texture* 	Message;
	SDL_Rect 		Message_rect;

public:
					SdlLibraryWrap() = delete;
					SdlLibraryWrap(int w, int h);
					~SdlLibraryWrap();
					SdlLibraryWrap(const SdlLibraryWrap &sdl);
	SdlLibraryWrap	&operator=(const SdlLibraryWrap &sdl);

	void 			RenderMap(const std::vector<std::vector<int>> &game_map) final;
	void			ClearImage(void) final;
	void			RenderImage(void) final;
	void 			RenderFood(int x, int y, bool isBonusFruit);
	int 			HandleInput(void) final;
	void 			RenderSnake(const std::vector<std::pair<int, int>> &snake_parts, int dir) final ;
	void			RenderSideMenu(int w, int h, size_t score, float time_left, std::vector<int> score_data) final ;
	void			RenderGameOverScreen(void) final;
};

#endif //NIBBLER_SDLLIBRARYWRAP_H
