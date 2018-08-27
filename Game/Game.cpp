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

	/*
	 *	In case of any event did not take place we return OK status
	 */

	return (Events::OK);
}

/*
 *	Method that runs a game
 */

void	Game::RunGame(void)
{
	/*
	 *	Disable movement is a flag from preventing a change direction spamming
	 *	Once a direction was changed, it will be impossible to change it before the movement will take place
	 */

	bool	disable_movement;

	/*
	 *	Game run indicates is the game is still running
	 */

	bool 	game_run;

	/*
	 *	Direction holds a current snake head direction
	 */

	int 	direction;

	/*
	 *	Collision status holds the current possible event
	 *
	 *	1. WALL_HIT - if the wall or some obstacle on the map was hit
	 *	2. SELF_HIT - if the snake bites itself
	 *	3. PICKED_FRUIT - if the fruit was picked
	 */

	Events 	collision_status;

	/*
	 *	Time left indicates how many time before fruit respawn is left
	 */

	double 	time_left;

	/*
	 *	initialize variables
	 */
	game_run = true;
	disable_movement = false;
	fruit_timer = std::chrono::high_resolution_clock::now();

	while (game_run)
	{
		/*
		 *	Render all the image with the RunLib method and get the input from the user
		 *	if direction == 0, it means ESC was pressed and exit the game
		 *	if direction == PAUSE the game stops, PRESS P to pause the game and continue
		 */
		direction = lib_wrap->RunLib(game_map, snake->GetSnakeParts(), fruit->GetFruitPosition().first, fruit->GetFruitPosition().second, snake->GetSnakeDirection(), score, time_left);
		if (direction == Directions::PAUSE)
			pause = !pause;
		if (!direction)
			game_run = false;
		else
		{
			/*
			 *	Do some action if the pause is not pressed
			 */
			if (!pause)
			{

				/*
				 *	If the WALL_HIT or SELF_HIT event occurred - exit the game
				 */
				collision_status = CheckCollision();
				if (collision_status == Events::SELF_HIT || collision_status == Events::WALL_HIT)
					exit(0);

				/*
				 * 	Calculate the time left for the rendering purposes
				 */
				time_left = fruit_respawn - static_cast<double >(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - fruit_timer).count()) / 1000.0;

				/*
				 *	if the key was pressed, we set a new direction for the snake
				 *	and disable changing of the direction until a move of snake will occur
				 *	an
				 */
				if (direction != Directions::NOTHING_PRESSED && direction != Directions ::PAUSE
					&& !disable_movement)
				{
					snake->SetSnakeDirection(static_cast<Directions>(direction));
					disable_movement = true;
				}

				/*
				 *	The movement of snake is performed in some period of time
				 *	The ability to change the direction is unable
				 */
				if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - begin).count() >= game_speed)
				{
					disable_movement = false;
					begin = std::chrono::high_resolution_clock::now();

					/*
					 * 	if the fruit was picked
					 * 	we increase the score and change the fruit position
					 *
					 * 	if there was not fruit picked up, we move the snake in a usual manner
					 * 	without extending it
					 */
					if (collision_status == Events::PICKED_FRUIT)
					{
						fruit_timer = std::chrono::high_resolution_clock::now();
						fruit->SetFruitPosition(game_map, snake->GetSnakeParts(), width, height);
						score += 10;
						sound_wrap->playEatSound();

						/*
						 *	we pass TRUE to the move method to indicate that the size of snake should be increased
						 */
						snake->MoveSnake(true);

						/*
						 *	Increase the speed of the game if some score value is reached
						 */
						if (score % 50 == 0 && game_speed > 150)
						{
							fruit_respawn -= fruit_respawn / 10.0;
							game_speed -= 50;
						}
					}
					else
						snake->MoveSnake(false);
				}

				/*
				 *	If the time for fruit spawn passed -> we change its position and reset the timer
				 */
				if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - fruit_timer).count() >=
					static_cast<int>(fruit_respawn * 1000))
				{
					fruit_timer = std::chrono::high_resolution_clock::now();
					fruit->SetFruitPosition(game_map, snake->GetSnakeParts(), width, height);
				}
			}
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

void	Game::GenerateMap(const std::vector<std::pair<int, int>> &snake_parts)
{
	/*
	 * 	Set up for a map generation
	 */
	int squares_to_full_fill;

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

	/*
	 *	random generation of the level
	 *	it calculates the general amount of the block
	 *	and fulfills divides it by 25
	 *	and fills it with obstacle and mirror to i_pos
	 *
	 *	1. the point should not be already occupied
	 *	2. be part of snake
	 *	3. be placed directly upper the head
	 */

	squares_to_full_fill = static_cast<int>((static_cast<double>(height * width) / 50));
	for (int i = 0; i < squares_to_full_fill; i++)
	{
		int j_map = unif_range_w(rng);
		int i_map = unif_range_h(rng);
		while (snake->CheckSnakePartCoordinate(i_map, j_map) || snake->CheckSnakePartCoordinate(i_map, width - j_map - 1)
			   || (game_map[i_map][j_map] && game_map[i_map][width - j_map - 1])
				|| (snake_parts[0].first - 1 == i_map))
		{
			i_map = unif_range_h(rng);
			j_map = unif_range_w(rng);
		}
		game_map[i_map][j_map] = 1;
		game_map[i_map][width - 1 - j_map] = 1;
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
	 * 	Create a snake object
	 */

	snake = std::make_shared<Snake>(Snake(width, height));

	/*
	 *	Create SDL wrapper
	 */

	lib_wrap = std::make_shared<SdlLibraryWrap>(SdlLibraryWrap(width, height));

	/*
	 *	Set score value
	 */

	score = 0;

	/*
	 *	Set game speed
	 */

	game_speed = 700;

	/*
	 *	Time in seconds to the food respawn
	 */

	fruit_respawn = static_cast<double>(width + height) / 2.0;

	/*
	 *	Generating of the map
	 */

	GenerateMap(snake->GetSnakeParts());

	/*
	 *	Create Fruit
	 */

	fruit = std::make_shared<Fruit>(Fruit());
	fruit->SetFruitPosition(game_map, snake->GetSnakeParts(), width, height);

	/*
	 *	Set pause by default
	 */

	pause = true;

	/*
	 *	Create a sound wrapper
	 */

	sound_wrap = std::make_shared<SoundWrapper>(SoundWrapper());
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
		game_speed(game.game_speed),
		fruit_respawn(game.fruit_respawn),
		pause(game.pause),
		sound_wrap(game.sound_wrap)
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
	fruit_respawn = game.fruit_respawn;
	pause = game.pause;
	sound_wrap = game.sound_wrap;
	return (*this);
}

/*
 * 	Destructor
 */

Game::~Game()
{

}
