#include "SdlLibraryWrap.h"

/*
 *	A method to render a map
 */

void 		 SdlLibraryWrap::RenderMap(const std::vector<std::vector<int>> &game_map)
{

	SDL_SetRenderDrawColor( ren, 0, 0, 0, 0 );


	SDL_Rect r;
	r.w = 32;
	r.h = 32;

//	SDL_RenderClear(ren);

	SDL_RenderClear(ren);
	for (size_t i = 0; i < game_map.size(); i++)
	{
		for (size_t j = 0; j < game_map[i].size(); j++)
		{
			r.x = i * r.h;
			r.y = j * r.w;
			if (game_map[i][j] == 1) {
				SDL_SetRenderDrawColor(ren, 0, 255, 0, 255 );
			} else {
				SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
			}
			SDL_RenderFillRect(ren, &r);
//			SDL_RenderPresent(ren);
//			if (i == 0 || i == game_map.size() - 1) {
//				SDL_SetRenderDrawColor( ren, 0, 255, 255, 255 );
//			}
//			else if (j == 0 || j == game_map[i].size() - 1) {
//				SDL_SetRenderDrawColor( ren, 0, 255, 255, 255 );
//			}
//			else
//				SDL_SetRenderDrawColor( ren, 0, 255, 255, 255 );
		}
	}



	SDL_RenderPresent(ren);

	SDL_Delay(5000);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}


/*
 *	Default constructor for the SDL wrap
 */

SdlLibraryWrap::SdlLibraryWrap(int w, int h)
{
	/*
	 *	Perform initialization for the SDL
	 */

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERROR SDL_INIT" << std::endl;
		exit(0);
	}

	/*
	 *	Create a window
	 */

	if (!(win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w * 32, h * 32, SDL_WINDOW_OPENGL)))
	{
		std::cout << "ERROR SDL CREATE WINDOW" << std::endl;
		exit(0);
	}

	/*
	 *	Check if it was created
	 */

	if (SDL_GetWindowID(win) == 0)
	{
		std::cout << "ERROR SDL GET WINDOW ID" << std::endl;
		exit(0);
	}

	/*
	 *	Create render
	 */

	if (!(ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		std::cout << "ERROR SDL CREATE RENDER" << std::endl;
		exit(0);
	}

//	SDL_RenderClear(ren);
//	SDL_RenderPresent(ren);
//
//	SDL_Delay(5000);
}

/*
 *	Copy constructor
 */

SdlLibraryWrap::SdlLibraryWrap(const SdlLibraryWrap &sdl)
{
	win = sdl.win;
	ren = sdl.ren;
}

/*
 *	Copy assignment operator
 */

SdlLibraryWrap 	&SdlLibraryWrap::operator=(const SdlLibraryWrap &sdl)
{
	win = sdl.win;
	ren = sdl.ren;

	return (*this);
}