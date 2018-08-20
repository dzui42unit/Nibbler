#include "Game.h"

// http://www.andrespagella.com/snake-game

/*
 *	Max map size variables
 */

const int Game::MAX_SIZE = 50;
const int Game::MIN_SIZE = 10;

/*
 * 	Method that prints a map
 */

void	Game::PrintGameMap() const
{
	std::cout << "GAME MAP" << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
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

}

/*
 *	Copy constructor
 */

Game::Game(const Game &game) : width(game.width), height(game.height), game_map(game.game_map)
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
	return (*this);
}

/*
 * 	Destructor
 */

Game::~Game()
{

}
