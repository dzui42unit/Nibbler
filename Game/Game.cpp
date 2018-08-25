#include "Game.h"

/*
 *	Max map size variables
 */

const int Game::MAX_SIZE = 40;
const int Game::MIN_SIZE = 10;

/*
 *	Method that calculates collision
 */

bool	Game::CheckCollision(void) const
{
	std::pair<int, int>	head_coords;

	/*
	 *	get snake head coordinates
	 */

	head_coords = snake->GetSnakeParts()[0];

	// second is a row, first is a col
//	std::cout << head_coords.first << " " << head_coords.second << std::endl;

	/*
	 *	if the head coordinates are on the map obstacle
	 *	send a signal about it
	 */

	if (game_map[head_coords.first][head_coords.second] == 1)
		return (true);

	return (false);
}

/*
 *	Method that runs a game
 */

void	Game::RunGame(void)
{
	bool 	game_run;
	int 	direction;

	game_run = true;
	begin = std::chrono::high_resolution_clock::now();

	while (game_run)
	{
		direction = lib_wrap->RunLib(game_map, snake->GetSnakeParts(), 0, 0);
		if (!direction)
			game_run = false;
		else
		{
			if (direction != -1)
			{
				snake->SetSnakeDirection(static_cast<Directions>(direction));
				if (direction != snake->GetSnakeDirection() && (direction - snake->GetSnakeDirection() != 1 && direction - snake->GetSnakeDirection() != -1))
					snake->MoveSnake();
			}
			else if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - begin).count() >= 200)
			{
				begin = std::chrono::high_resolution_clock::now();
				snake->MoveSnake();
			}
		}
		if (CheckCollision())
		{
			exit(0);
			std::cout << "HIT THAT WALL, BEACH!!!" << std::endl;
		}
	}
}

/*
 * 	Method that prints a map
 */

void	Game::PrintGameMap()
{
	std::cout << "GAME MAP" << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (snake->CheckSnakePartCoordinate(i, j))
				std::cout << 2 << " ";
			else
				std::cout << game_map[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/*
 *	Method that generates the game map
 */

void	Game::GenerateMap(void)
{
	/*
	 * 	Set up for a map generation
	 */

	std::mt19937_64 rng(std::time(NULL));
	std::uniform_int_distribution<int> unif(0, 1);
	std::uniform_int_distribution<int> unif_range_w(1, width - 1);
	std::uniform_int_distribution<int> unif_range_h(1, height - 1);

	std::cout << height << " " << width << std::endl;
	for (int i = 0; i < height; i++)
	{
		std::vector<int>	temp;
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1)
				temp.push_back(1);
			else if (j == 0 || j == width - 1)
				temp.push_back(1);
			else
				temp.push_back(0);
		}
		game_map.push_back(temp);
	}
}

/*
 * 	Constructor that takes width and height parameters as strings
 */

Game::Game(char *w, char *h)
{
	std::regex numbers_pattern;

	/*
	 * 	Check the input width and height for being numbers
	 * 	Else throw an exception
	 */

	numbers_pattern = std::regex("([0-9])+");
	if (!std::regex_match(w, numbers_pattern) || !std::regex_match(h, numbers_pattern))
		throw (MapSizeException());

	/*
	 * 	Convert them to integers
	 */

	width = std::stoi(w);
	height = std::stoi(h);

	/*
	 *	Check for them to fit the ranges
	 */

	if (width > MAX_SIZE || width < MIN_SIZE|| height < MIN_SIZE || height > MAX_SIZE)
		throw (MapSizeException());

	/*
	 *	Generating of the map
	 */

	GenerateMap();

	/*
	 * 	Create a snake object
	 */

	snake = std::make_shared<Snake>(Snake(width, height));

	/*
	 *	Create SDL wrapper
	 */

	lib_wrap = std::make_shared<SdlLibraryWrap>(SdlLibraryWrap(width, height));
}

/*
 *	Copy constructor
 */

Game::Game(const Game &game) : width(game.width), height(game.height), game_map(game.game_map), snake(game.snake), lib_wrap(game.lib_wrap)
{

}

/*
 * 	Copy assignment operator
 */

Game& 	Game::operator=(const Game &game)
{
	width = game.width;
	height = game.height;
	game_map = game.game_map;
	snake = game.snake;
	lib_wrap = game.lib_wrap;
	return (*this);
}

/*
 * 	Destructor
 */

Game::~Game()
{

}
