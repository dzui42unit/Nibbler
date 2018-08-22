#include "Game.h"

// http://www.andrespagella.com/snake-game

/*
 *	Max map size variables
 */

const int Game::MAX_SIZE = 50;
const int Game::MIN_SIZE = 10;

/*
 *	Method that runs a game
 */

void	Game::RunGame(void)
{
	char ch;
	while (true)
	{
		std::cin >> ch;
		if (ch == 'w')
			snake->SetSnakeDirection(Directions::UP);
		if (ch == 's')
			snake->SetSnakeDirection(Directions::DOWN);
		if (ch == 'a')
			snake->SetSnakeDirection(Directions::LEFT);
		if (ch == 'd')
			snake->SetSnakeDirection(Directions::RIGHT);
		if (ch == '1')
			break ;
		snake->MoveSnake();
		PrintGameMap();
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

	snake = std::make_shared<Snake>(Snake(height, width));

	/*
	 *	Create SDL wrapper
	 */

	lib_wrap = std::make_shared<SdlLibraryWrap>(SdlLibraryWrap());
}

/*
 *	Copy constructor
 */

Game::Game(const Game &game) : width(game.width), height(game.height), game_map(game.game_map), snake(game.snake)
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
	return (*this);
}

/*
 * 	Destructor
 */

Game::~Game()
{

}
