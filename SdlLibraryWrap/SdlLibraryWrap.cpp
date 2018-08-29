#include "SdlLibraryWrap.h"
#include "../Snake/Snake.h"

/*
 *	A function that renders a side menu in a simple manner
 */

void	SdlLibraryWrap::RenderSideMenu(int w, int h, size_t score, float time_left, std::vector<int> score_data)
{
	std::string message;

	/*
	 *	render score
	 */

	message = "Score: " + std::to_string(score);
	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255});
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	Message_rect.x = w + 32;
	Message_rect.y = 32;
	Message_rect.w = 250;
	Message_rect.h = 70;
	SDL_RenderCopy(ren, Message, NULL, &Message_rect);

	/*
	 *	Render time left
	 */

	message = "Time left: " + std::to_string(time_left);
	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255});
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	Message_rect.x = w + 32;
	Message_rect.y = 90;
	Message_rect.w = 350;
	Message_rect.h = 60;
	SDL_RenderCopy(ren, Message, NULL, &Message_rect);

	/*
	 *	Render Controls
	 */

	message = "BEST SCORES:";
	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255});
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	Message_rect.x = w + 32;
	Message_rect.y = 150;
	Message_rect.w = 350;
	Message_rect.h = 60;
	SDL_RenderCopy(ren, Message, NULL, &Message_rect);

	int k = 100;

	for (size_t i = 0; i < score_data.size(); i++)
	{
		message = std::to_string(i + 1) + ": " + std::to_string(score_data[i]);

		surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255});
		Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
		Message_rect.x = w + 32;
		Message_rect.y = 150 + k;
		Message_rect.w = 100;
		Message_rect.h = 60;
		SDL_RenderCopy(ren, Message, NULL, &Message_rect);

		k += 100;
	}
//
//	message = "ARROW_DOWN - to move snake down";
//	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255});
//	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
//	Message_rect.x = w + 32;
//	Message_rect.y = 250;
//	Message_rect.w = 350;
//	Message_rect.h = 60;
//	SDL_RenderCopy(ren, Message, NULL, &Message_rect);
//
//	message = "ARROW_LEFT - to move snake left";
//	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255});
//	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
//	Message_rect.x = w + 32;
//	Message_rect.y = 350;
//	Message_rect.w = 350;
//	Message_rect.h = 60;
//	SDL_RenderCopy(ren, Message, NULL, &Message_rect);
//
//	message = "ARROW_RIGHT - to move snake right";
//	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255});
//	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
//	Message_rect.x = w + 32;
//	Message_rect.y = 450;
//	Message_rect.w = 350;
//	Message_rect.h = 60;
//	SDL_RenderCopy(ren, Message, NULL, &Message_rect);
//
//	message = "SPACEBAR - to pause a game";
//	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255});
//	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
//	Message_rect.x = w + 32;
//	Message_rect.y = 550;
//	Message_rect.w = 350;
//	Message_rect.h = 60;
//	SDL_RenderCopy(ren, Message, NULL, &Message_rect);
}

/*
 *	Method that clears an image
 */

void	SdlLibraryWrap::ClearImage(void)
{
	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor( ren, 0, 0, 0, 0 );
}

/*
 *	Method that puts image to the window
 */

void	SdlLibraryWrap::RenderImage(void)
{
	SDL_RenderPresent(ren);
}

/*
 *	Method that renders a Snake
 */

void 			SdlLibraryWrap::RenderSnake(const std::vector<std::pair<int, int>> &snake_parts, int dir)
{
	SDL_Rect r;

	r.w = 32;
	r.h = 32;
	for (size_t i = 0; i < snake_parts.size(); i++)
	{
		r.x = snake_parts[i].second * r.w;
		r.y = snake_parts[i].first * r.h;
		if (i == 0)
		{
            switch (dir) {
                case 1: {
                    SDL_RenderCopy(ren, snake_head_texture, &head_up, &r);
                    break;
                }
                case 2: {
                    SDL_RenderCopy(ren, snake_head_texture, &head_down, &r);
                    break;

                }
                case 3: {
                    SDL_RenderCopy(ren, snake_head_texture, &head_left, &r);
                    break;

                }
                case 4: {
                    SDL_RenderCopy(ren, snake_head_texture, &head_right, &r);
                    break;

                }
                default: {
                    std::cout << "Error: incorrect dir" << dir << std::endl;
                    break;

                }
            }
		}
		else
		{
            SDL_RenderCopy(ren, snake_body_texture, &rect_snake_body, &r);
		}
	}
}


/*
 *	Key hook handler for user input
 *	Movement of the snake UP, DOWN, LEFT, RIGHT and ESC
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
			if (event.key.keysym.sym == SDLK_SPACE && event.key.repeat == 0)
				return (Directions::PAUSE);
		}
	}
	return (Directions::NOTHING_PRESSED);
}


/*
 *	A method to render a map
 */

void 		 SdlLibraryWrap::RenderMap(const std::vector<std::vector<int>> &game_map)
{
	SDL_Rect r;
	r.w = 32;
	r.h = 32;

    SDL_RenderCopy(ren, grass_texture, &rect_background, &rect_background);
	for (size_t i = 0; i < game_map.size(); i++)
	{
		for (size_t j = 0; j < game_map[i].size(); j++)
		{
			r.x = j * r.h;
			r.y = i * r.w;
			if (game_map[i][j] == 1) {
                SDL_RenderCopy(ren, border_texture, &image_texture_part, &r);
            }
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

	TTF_Init();

	/*
	 *	Create a window
	 */

	if (!(win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w * 32 + 32 * 15, h * 32, SDL_WINDOW_OPENGL)))
	{
		std::cout << "ERROR SDL CREATE WINDOW" << std::endl;
		exit(0);
	}

	/*
	 * 	Init audio device
	 */

	SDL_Init(SDL_INIT_AUDIO);

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
    * 	Init IMG
    */

    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    if ((initted & flags) != flags) {
        std::cout << "IMG_Init: Failed to init required jpg and png support!\n" << std::endl;
        std::cout << "IMG_Init: %s\n" <<  IMG_GetError() << std::endl;
    }


	/*
	 *	Reading textures
	 */

    SDL_Surface *image_border = IMG_Load("libs/sdl/texture1.jpg");
    SDL_Surface *image_grass = IMG_Load("libs/sdl/background3.jpg");
    SDL_Surface *image_snake_head = IMG_Load("libs/sdl/snake_head.png");
    SDL_Surface *image_snake_body = IMG_Load("libs/sdl/snake_body3.png");

	Sans = TTF_OpenFont("libs/sdl/2211.ttf", 12);
	surfaceMessage = TTF_RenderText_Solid(Sans, "0", {255, 255, 255});

	if (!image_border || !image_grass || !image_snake_head || !image_snake_body)
    {
        std::cout << "ERROR upload texture" << std::endl;
        exit(0);
    }

	/*
	 *	Creating of the textures
	 */

    border_texture = SDL_CreateTextureFromSurface(ren, image_border);
    grass_texture = SDL_CreateTextureFromSurface(ren, image_grass);
    snake_head_texture = SDL_CreateTextureFromSurface(ren, image_snake_head);
    snake_body_texture = SDL_CreateTextureFromSurface(ren, image_snake_body);

    if (!border_texture || !grass_texture || !snake_head_texture || !snake_body_texture) {
        std::cout << "ERROR border texture" << std::endl;
        exit(1);
    }

    SDL_FreeSurface(image_border);
    SDL_FreeSurface(image_grass);

    image_texture_part = {0, 0, 100, 100};

	/*
	 *	Getting parts of the texture for the snake parts
	 */

    head_up = {196, 0, 60, 60};
    head_right = {256, 0, 60, 60};
    head_down = {256, 65, 60, 60};
    head_left = {195, 65, 60, 60};
    rect_background = {0, 0, w * 32, h * 32};
    rect_snake_body = {160, 0, 960, 960};
    rect_food = {0, 192, 60, 60};

	/*
	 *	Initialize some variables for timer
	 */

	now = 0;
	last = 0;
}

/*
 *	Method that renders a fruit
 */

void	SdlLibraryWrap::RenderFood(int i_pos, int j_pos)
{
	SDL_Rect r;
	r.w = 32;
	r.h = 32;

	r.x = j_pos * r.h;
	r.y = i_pos * r.w;

    SDL_RenderCopy(ren, snake_head_texture, &rect_food, &r);
}

/*
 *	Copy constructor
 */

SdlLibraryWrap::SdlLibraryWrap(const SdlLibraryWrap &sdl)
        : win(sdl.win),
          ren(sdl.ren),
          now(sdl.now),
          last(sdl.last),
          image_texture_part(sdl.image_texture_part),
          border_texture(sdl.border_texture),
          grass_texture(sdl.grass_texture),
          snake_head_texture(sdl.snake_head_texture),
          head_up(sdl.head_up),
          head_right(sdl.head_right),
          head_down(sdl.head_down),
          head_left(sdl.head_left),
          rect_background(sdl.rect_background),
          snake_body_texture(sdl.snake_body_texture),
          rect_snake_body(sdl.rect_snake_body),
          rect_food(sdl.rect_food),
		  Message(sdl.Message),
		  surfaceMessage(sdl.surfaceMessage),
		  Sans(sdl.Sans)
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
    image_texture_part = sdl.image_texture_part;
    border_texture = sdl.border_texture;
    grass_texture = sdl.grass_texture;
    snake_head_texture = sdl.snake_head_texture;
    head_up = sdl.head_up;
    head_right = sdl.head_right;
    head_down = sdl.head_down;
    head_left = sdl.head_left;
    rect_background = sdl.rect_background;
    rect_snake_body = sdl.rect_snake_body;
    snake_body_texture = sdl.snake_body_texture;
    rect_food = sdl.rect_food;
	Message = sdl.Message;
	Sans = sdl.Sans;
	surfaceMessage = sdl.surfaceMessage;
	return (*this);
}

/*
 *	Destructor
 */

SdlLibraryWrap::~SdlLibraryWrap()
{
	IMG_Quit();
}
