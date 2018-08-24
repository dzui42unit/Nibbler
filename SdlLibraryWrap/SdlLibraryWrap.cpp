#include "SdlLibraryWrap.h"
#include "../Snake/Snake.h"

int		SdlLibraryWrap::RunLib(const std::vector<std::vector<int>> &game_map,
					   const std::vector<std::pair<int, int>> &snake_parts,
					   int x_food,
					   int y_food)
{

	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor( ren, 0, 0, 0, 0 );

	RenderMap(game_map);
	RenderSnake(snake_parts);

	SDL_RenderPresent(ren);

	return (HandleInput());
}

/*
 *	Method that renders a Snake
 */

void 			SdlLibraryWrap::RenderSnake(const std::vector<std::pair<int, int>> &snake_parts)
{
	SDL_Rect r;

	r.w = 32;
	r.h = 32;
	for (size_t i = 0; i < snake_parts.size(); i++)
	{
		r.x = snake_parts[i].first * r.h;
		r.y = snake_parts[i].second * r.w;
		if (i == 0) {
			SDL_SetRenderDrawColor(ren, 0, 255, 255, 0);
		} else {
			SDL_SetRenderDrawColor(ren, 0, 0, 255, 0);
		}
		SDL_RenderFillRect(ren, &r);
	}
}


/*
 *	Key hook handler
 */

int 			SdlLibraryWrap::HandleInput(void)
{
	if (SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT )
			return (0);
		if (event.key.keysym.sym == SDLK_ESCAPE && event.key.repeat == 0)
			return (0);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_UP && event.key.repeat == 0)
				return (Directions::UP);
			if (event.key.keysym.sym == SDLK_LEFT && event.key.repeat == 0)
				return (Directions::LEFT);
			if (event.key.keysym.sym == SDLK_DOWN && event.key.repeat == 0)
				return (Directions::DOWN);
			if (event.key.keysym.sym == SDLK_RIGHT && event.key.repeat == 0)
				return (Directions::RIGHT);
		}
	}
	return (-1);
}


/*
 *	A method to render a map
 */

void 		 SdlLibraryWrap::RenderMap(const std::vector<std::vector<int>> &game_map)
{
	SDL_Rect r;
	r.w = 32;
	r.h = 32;

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
		}
	}
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

	/*
	 *	Initialize some variables for timer
	 */
}

/*
 *	Copy constructor
 */

SdlLibraryWrap::SdlLibraryWrap(const SdlLibraryWrap &sdl) : win(sdl.win), ren(sdl.ren), now(sdl.now), last(sdl.last)
{

}

/*
 *	Copy assignment operator
 */

SdlLibraryWrap 	&SdlLibraryWrap::operator=(const SdlLibraryWrap &sdl)
{
	win = sdl.win;
	ren = sdl.ren;
	now = sdl.now;
	last = sdl.last;

	return (*this);
}

/*
 *	Destructor
 */

SdlLibraryWrap::~SdlLibraryWrap()
{

}
