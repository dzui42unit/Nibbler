#include "SdlLibraryWrap.h"
#include "../../Snake/Snake.h"

#include <map>

/*
 *	A method that renders a game over screen
 */

void	SdlLibraryWrap::RenderGameOverScreen(void)
{
	SDL_RenderCopy(ren, game_over_screen_texture, NULL, &game_over_rect);
}

/*
 *	A function that renders a side menu in a simple manner
 */

void	SdlLibraryWrap::RenderSideMenu(int w, int , size_t score, float time_left, std::vector<int> score_data)
{
	std::string message;

	/*
	 *	render score
	 */

	message = "Score:       " + std::to_string(score);
	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255, 0});
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	Message_rect.x = w + 20;
	Message_rect.y = 20;
	Message_rect.w = 200;
	Message_rect.h = 60;
	SDL_RenderCopy(ren, Message, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);


	/*
	 *	Render time left
	 */

	message = "Time left:";
	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255, 0});
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	Message_rect.x = w + 20;
	Message_rect.y = 80;
	Message_rect.w = 150;
	Message_rect.h = 60;
	SDL_RenderCopy(ren, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

	message = std::to_string(time_left);
	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255, 0});
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	Message_rect.x = w + 210;
	Message_rect.y = 80;
	Message_rect.w = 150;
	Message_rect.h = 60;
	SDL_RenderCopy(ren, Message, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

	/*
	 *	Render Controls
	 */

	message = "BEST SCORES:";
	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255, 0});
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
	Message_rect.x = w + 20;
	Message_rect.y = 140;
	Message_rect.w = 200;
	Message_rect.h = 60;
	SDL_RenderCopy(ren, Message, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

	int k = 180;
	int step = 30;

	for (size_t i = 0; i < score_data.size(); i++)
	{
		message = std::to_string(i + 1) + ": " + std::to_string(score_data[i]);

		surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), {255, 255, 255, 0});
		Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
		Message_rect.x = w + 20;
		Message_rect.y = k + step;
		Message_rect.w = 120;
		Message_rect.h = 30;
		SDL_RenderCopy(ren, Message, NULL, &Message_rect);
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);

		k += step;
	}
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
	for (size_t i = 1; i < snake_parts.size(); i++)
	{
		r.x = snake_parts[i].second * r.w;
		r.y = snake_parts[i].first * r.h;
		SDL_RenderCopy(ren, snake_body_texture, &rect_snake_body, &r);
	}
	r.x = snake_parts[0].second * r.w;
	r.y = snake_parts[0].first * r.h;
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
			break;
		}
	}
}


/*
 *	Key hook handler for user input
 *	Movement of the snake UP, DOWN, LEFT, RIGHT and ESC
 */

int 			SdlLibraryWrap::HandleInput(void)
{
//	static std::map<int, int>	key_events = { {SDLK_KP_1, SDL_KEYUP}, {SDLK_KP_2, SDL_KEYUP}, {SDLK_KP_3, SDL_KEYUP} };

	SDL_PollEvent(&event);
	if(event.type == SDL_QUIT)
		return (0);
	if (event.key.keysym.sym == SDLK_ESCAPE)
		return (0);
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
	{
		if (event.key.keysym.sym == SDLK_UP)
			return (Directions::UP);
		if (event.key.keysym.sym == SDLK_LEFT)
			return (Directions::LEFT);
		if (event.key.keysym.sym == SDLK_DOWN)
			return (Directions::DOWN);
		if (event.key.keysym.sym == SDLK_RIGHT)
			return (Directions::RIGHT);
		if (event.key.keysym.sym == SDLK_SPACE)
			return (Directions::PAUSE);
//		if (event.key.keysym.sym == SDLK_KP_1)
//			return (Directions::SDL_LIB);
//		if (event.key.keysym.sym == SDLK_KP_2 && key_events[SDLK_KP_2] == SDL_KEYDOWN)
//		{
//			key_events[SDLK_KP_2] = SDL_KEYUP;
//			return (Directions::SDL_LIB);
//		}
//		key_events[SDLK_KP_2] = SDL_KEYDOWN;
//
//		if (event.key.keysym.sym == SDLK_KP_3 && key_events[SDLK_KP_3] == SDL_KEYDOWN)
//		{
//			key_events[SDLK_KP_3] = SDL_KEYUP;
//			return (Directions::SDL_LIB);
//		}
//		key_events[SDLK_KP_3] = SDL_KEYDOWN;
//
		if (event.key.keysym.sym == SDLK_KP_2)
			return (Directions::SFML_LIB);
		if (event.key.keysym.sym == SDLK_KP_3)
		{
			std::cout << "Call from sdl\n\n";
			return (Directions::OPENGL_LIB);
		}

//		state = glfwGetKey(window, GLFW_KEY_KP_2);
//		if (state == GLFW_PRESS && key_events[GLFW_KEY_KP_2] == GLFW_PRESS)
//		{
//			key_events[GLFW_KEY_KP_2] = state;
//			return (Directions::SFML_LIB);
//		}
//		key_events[GLFW_KEY_KP_2] = state;
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

			switch (game_map[i][j]) {
				case 1:
					image_texture_part = {32, 0, 32, 32};
					SDL_RenderCopy(ren, border_texture, &image_texture_part, &r);
					break ;
				case 2:
					image_texture_part = {0, 0, 32, 32};
					SDL_RenderCopy(ren, border_texture, &image_texture_part, &r);
					break;
				case 3:
					image_texture_part = {0, 32, 32, 32};
					SDL_RenderCopy(ren, border_texture, &image_texture_part, &r);
					break;
				case 4:
					image_texture_part = {32, 32, 32, 32};
					SDL_RenderCopy(ren, border_texture, &image_texture_part, &r);
					break;
			}

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

	if (!(win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w * 32 + SIDE_MENU_WIDTH, h * 32, SDL_WINDOW_OPENGL)))
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

	SDL_Surface *image_border = IMG_Load("libs/sdl/cube.png");
	SDL_Surface *image_grass = IMG_Load("libs/sdl/background5.jpg");
	SDL_Surface *image_snake_head = IMG_Load("libs/sdl/all.png");
	SDL_Surface *image_snake_body = IMG_Load("libs/sdl/all.png");
	SDL_Surface *image_super_fruit_texture = IMG_Load("libs/sdl/apple.png");
	SDL_Surface *image_game_over_texture = IMG_Load("libs/sdl/game_over.png");

	Sans = TTF_OpenFont("libs/sdl/10.ttf", 100);

	if (!image_border || !image_grass || !image_snake_head || !image_snake_body || !image_game_over_texture || !image_super_fruit_texture)
	{
		std::cout << "ERROR upload texture" << std::endl;
		exit(0);
	}
	if (!Sans)
	{
		std::cout << "ERROR SANS" << std::endl;
		exit(0);
	}

	/*
	 *	Creating of the textures
	 */

	border_texture = SDL_CreateTextureFromSurface(ren, image_border);
	grass_texture = SDL_CreateTextureFromSurface(ren, image_grass);
	snake_head_texture = SDL_CreateTextureFromSurface(ren, image_snake_head);
	snake_body_texture = SDL_CreateTextureFromSurface(ren, image_snake_body);
	super_fruit_texture = SDL_CreateTextureFromSurface(ren, image_super_fruit_texture);
	game_over_screen_texture = SDL_CreateTextureFromSurface(ren, image_game_over_texture);

	if (!border_texture || !grass_texture || !snake_head_texture || !snake_body_texture || !game_over_screen_texture || !super_fruit_texture) {
		std::cout << "ERROR border texture" << std::endl;
		exit(1);
	}

	SDL_FreeSurface(image_border);
	SDL_FreeSurface(image_grass);
	SDL_FreeSurface(image_snake_head);
	SDL_FreeSurface(image_snake_body);
	SDL_FreeSurface(image_super_fruit_texture);
	SDL_FreeSurface(image_game_over_texture);


	surfaceMessage = nullptr;
	Message = nullptr;

	/*
	 *	Getting parts of the texture for the snake parts
	 */

	head_up = {64, 0, 32, 32};
	head_right = {0, 0, 32, 32};
	head_down = {96, 0, 32, 32};
	head_left = {32, 0, 32, 32};


	rect_background = {0, 0, w * 32, h * 32};
	rect_snake_body = {0, 32, 32, 32};
	rect_food = {96, 32, 32, 32};
	rect_super_fruit = {0, 0, 50, 50};
	game_over_rect = { 0, 0, w * 32 + SIDE_MENU_WIDTH, h * 32};

	/*
	 *	Initialize some variables for timer
	 */

	now = 0;
	last = 0;
}

/*
 *	Method that renders a fruit
 */

void	SdlLibraryWrap::RenderFood(int i_pos, int j_pos, bool isBonusFruit)
{
	SDL_Rect r;
	r.w = 32;
	r.h = 32;

	r.x = j_pos * r.h;
	r.y = i_pos * r.w;

	if (isBonusFruit) {
		SDL_RenderCopy(ren, super_fruit_texture, NULL, &r);
	}
	else {
		SDL_RenderCopy(ren, snake_head_texture, &rect_food, &r);
	}
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
		  snake_body_texture(sdl.snake_body_texture),
		  super_fruit_texture(sdl.super_fruit_texture),
		  game_over_screen_texture(sdl.game_over_screen_texture),
		  head_up(sdl.head_up),
		  head_right(sdl.head_right),
		  head_down(sdl.head_down),
		  head_left(sdl.head_left),
		  rect_background(sdl.rect_background),
		  rect_snake_body(sdl.rect_snake_body),
		  rect_food(sdl.rect_food),
		  rect_super_fruit(sdl.rect_super_fruit),
		  game_over_rect(sdl.game_over_rect),
		  Sans(sdl.Sans),
		  surfaceMessage(sdl.surfaceMessage),
		  Message(sdl.Message),
		  Message_rect(sdl.Message_rect)
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
	snake_body_texture = sdl.snake_body_texture;
	super_fruit_texture = sdl.super_fruit_texture;
	game_over_screen_texture = sdl.game_over_screen_texture;
	head_up = sdl.head_up;
	head_right = sdl.head_right;
	head_down = sdl.head_down;
	head_left = sdl.head_left;
	rect_background = sdl.rect_background;
	rect_snake_body = sdl.rect_snake_body;
	rect_food = sdl.rect_food;
	rect_super_fruit = sdl.rect_super_fruit;
	game_over_rect = sdl.game_over_rect;
	Sans = sdl.Sans;
	surfaceMessage = sdl.surfaceMessage;
	Message = sdl.Message;
	Message_rect = sdl.Message_rect;
	return (*this);
}

/*
 *	Destructor
 */

SdlLibraryWrap::~SdlLibraryWrap()
{
	SDL_DestroyRenderer(ren);
	TTF_CloseFont(Sans);
	SDL_DestroyTexture(border_texture);
	SDL_DestroyTexture(grass_texture);
	SDL_DestroyTexture(snake_head_texture);
	SDL_DestroyTexture(snake_body_texture);
	SDL_DestroyTexture(super_fruit_texture);
	SDL_DestroyTexture(game_over_screen_texture);
	SDL_PollEvent(nullptr);
	SDL_DestroyWindow(win);
	IMG_Quit();
}


extern "C" SdlLibraryWrap      *createWrapper(int w, int h)
{
	return (new SdlLibraryWrap(w, h));
}
extern "C" void                deleteWrapper(SdlLibraryWrap *lib)
{
	delete lib;
}