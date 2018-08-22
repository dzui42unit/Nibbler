#include "SdlLibraryWrap.h"

SdlLibraryWrap::SdlLibraryWrap()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERROR SDL_INIT" << std::endl;
		exit(0);
	}

	if (!(win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1000, SDL_WINDOW_OPENGL)))
	{
		std::cout << "ERROR SDL CREATE WINDOW" << std::endl;
		exit(0);
	}


	if (SDL_GetWindowID(win) == 0)
	{
		std::cout << "ERROR SDL GET WINDOW ID" << std::endl;
		exit(0);
	}

	if (!(ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		std::cout << "ERROR SDL CREATE RENDER" << std::endl;
		exit(0);
	}


	SDL_RenderClear(ren);
//	SDL_RenderCopy(>ren, sdl->texture, 0, 0);
	SDL_RenderPresent(ren);

	SDL_Delay(5000);
}