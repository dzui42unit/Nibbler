#ifndef NIBBLER_GAME_H
#define NIBBLER_GAME_H

#define FILE_SCORES "scores.nibbler"

#include "../Snake/Snake.h"
#include "../SdlLibraryWrap/SdlLibraryWrap.h"
#include "../Fruit/Fruit.h"
#include "../SoundWrapper/SoundWrapper.h"

#include <iostream>
#include <regex>
#include <vector>
#include <memory>
#include <utility>
#include <ctime>
#include <exception>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <unistd.h>

enum Events { WALL_HIT, SELF_HIT, PICKED_FRUIT, PICKED_SUPER_FRUIT, OK };

class Game
{
private:

	/*
	 *	Map size limits
	 */

	static const int MAX_SIZE;
	static const int MIN_SIZE;
	/*
	 *	variables to store the size of map
	 */

	int 	width;
	int 	height;

	/*
	 *	Score of the player
	 */

	size_t 	score;

	/*
	 *	variable to store the map
	 */

	std::vector<std::vector<int>>	game_map;

	/*
	 * 	method for generating a map
	 */

	void 	GenerateMap(const std::vector<std::pair<int, int>> &snake_parts);

	std::shared_ptr<Snake>	snake;

	/*
	 *	pointer to the library wrapper
	 */

	std::shared_ptr<InterfaceLibrary>	lib_wrap;

	/*
	 *	pointer to the Fruit object
	 */

	std::shared_ptr<Fruit>				fruit;

	/*
	 *	pointer to the bonus fuit, that appears on the limited amount of time
	 */

	std::shared_ptr<Fruit>				super_fruit;

	/*
	 *	pointer to the sound wrapper
	 */


	std::shared_ptr<SoundWrapper>		sound_wrap;

	/*
	 *	Timer
	 */

	std::chrono::high_resolution_clock::time_point begin;
	std::chrono::high_resolution_clock::time_point fruit_timer;


	/*
	 *	Speed of game
	 */

	size_t game_speed;

	/*
	 *	Time period to change fruit position
	 */

	double fruit_respawn;

	/*
	 *	Set pause or not
	 */

	bool pause;

	/*
	 *	Scores
	 */

	std::vector<int>	scores_data;

public:

	/*
	 * 	Canonical form of a class
	 */

				Game() = delete;
				~Game();
				Game(const Game &game);
	Game		&operator=(const Game &game);

	/*
	 * 	Constructor that takes takes width and height as an input parameter
	 */

	Game(char *w , char *h);

	/*
	 *	method that prints a map
	 */

	void	PrintGameMap(void);

	/*
	 *	method to run a game loop
	 */

	void	RunGame(void);

	/*
	 *	Method to calculate collision
	 */

	Events 	CheckCollision(void) const;


	/*
	 *	Method that writes an score to the file
	 */

	void	StoreScore(void);

	/*
	 *	Exception if the wrong size of map is passed
	 */


	class 	MapSizeException : public std::exception
	{
	public:
		const char *what() const noexcept(true) override
		{
			std::string error_message;

			error_message = "Map size error: use integers in range from " + std::to_string(MIN_SIZE) + " and " + std::to_string(MAX_SIZE);
			return (error_message.c_str());
		}
	};
};


#endif //NIBBLER_GAME_H
