#include "Game.h"

/*
 *	Max map size variables
 */

const int Game::MAX_SIZE = 40;
const int Game::MIN_SIZE = 10;

/*
 *	Method that calculates collision
 */

Events	Game::CheckCollision(void) const
{
	std::vector<std::pair<int, int>>	snake_p;
	std::pair<int, int>	head_coords;

	/*
	 *	get snake head coordinates
	 */

	snake_p = snake->GetSnakeParts();
	head_coords = snake_p[0];

	/*
	 *	If the head touched a fruit
	 */

	if (head_coords.first == fruit->GetFruitPosition().first
		&& head_coords.second == fruit->GetFruitPosition().second)
		return (Events::PICKED_FRUIT);

	/*
	 *	if the head coordinates are on the map obstacle
	 *	send a signal about it
	 */

	snake_p.erase(snake_p.begin());
	if (game_map[head_coords.first][head_coords.second] == 1)
		return (Events ::WALL_HIT);
	if (std::find(snake_p.begin(), snake_p.end(), head_coords) != snake_p.end())
		return (Events::SELF_HIT);
	return (Events::OK);
}

/*
 *	Method that runs a game
 */

void	Game::RunGame(void)
{
	bool 	game_run;
	int 	direction;
	bool	disable_movement;
	Events 	collision_status;

	disable_movement = false;
	game_run = true;
	fruit_timer = std::chrono::high_resolution_clock::now();
	while (game_run)
	{
		collision_status = CheckCollision();
		if (collision_status == Events::SELF_HIT || collision_status == Events::WALL_HIT)
			exit(0);
		direction = lib_wrap->RunLib(game_map, snake->GetSnakeParts(), fruit->GetFruitPosition().first, fruit->GetFruitPosition().second, snake->GetSnakeDirection(), score, fruit_timer);
		if (!direction)
			game_run = false;
		else
		{
			if (direction != -1 && !disable_movement)
			{
				snake->SetSnakeDirection(static_cast<Directions>(direction));
				disable_movement = true;
			}
			if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - begin).count() >= game_speed)
			{
				disable_movement = false;
				begin = std::chrono::high_resolution_clock::now();
				if (collision_status == Events::PICKED_FRUIT)
				{
					fruit_timer = std::chrono::high_resolution_clock::now();
					fruit->SetFruitPosition(game_map, snake->GetSnakeParts(), width, height);
					score += 10;
					snake->MoveSnake(true);
					if (score % 10 == 0 && game_speed > 100)
						game_speed -= 50;
				}
				else
					snake->MoveSnake(false);
			}
		}
		if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - fruit_timer).count() >= 15000)
		{
			fruit_timer = std::chrono::high_resolution_clock::now();
			fruit->SetFruitPosition(game_map, snake->GetSnakeParts(), width, height);
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

	if (width > MAX_SIZE || width < MIN_SIZE || height < MIN_SIZE || height > MAX_SIZE)
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

	/*
	 *	Create Fruit
	 */

	fruit = std::make_shared<Fruit>(Fruit());
	fruit->SetFruitPosition(game_map, snake->GetSnakeParts(), width, height);

	/*
	 *	Set score value
	 */

	score = 0;

	/*
	 *	Set game speed
	 */

	game_speed = 700;
}

/*
 *	Copy constructor
 */

Game::Game(const Game &game) :
		width(game.width),
		height(game.height),
		game_map(game.game_map),
		snake(game.snake),
		lib_wrap(game.lib_wrap),
		fruit(game.fruit),
		score(game.score),
		game_speed(game.game_speed)
{

}

/*
 * 	Copy assignment operator
 */

Game& 	Game::operator=(const Game &game)
{
	width = game.width;
	height = game.height;
	score = game.score;
	game_map = game.game_map;
	snake = game.snake;
	lib_wrap = game.lib_wrap;
	fruit = game.fruit;
	game_speed = game.game_speed;
	return (*this);
}

/*
 * 	Destructor
 */

Game::~Game()
{

}
