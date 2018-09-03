#ifndef NIBBLER_GAME_H
#define NIBBLER_GAME_H

#define FILE_SCORES "scores.nibbler"

#include "../Snake/Snake.h"
#include "../InterfaceLibrary/InterfaceLibrary.h"
#include "../Fruit/Fruit.h"
#include "../InterfaceSoundLib/InterfaceSoundLib.h"


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
#include <dlfcn.h>
#include <unistd.h>

#define SDL_LIB_NAME "libs/sdl/libsdl2wrapper.so"
#define SFML_LIB_NAME "libsfml2wrapper.so"
#define OPENGL_LIB_NAME "libopengl2wrapper.so"
#define LIB_SOUND_WRAP "libs/SoundWrapper/libsoundwrapper.so"


enum Events { WALL_HIT, SELF_HIT, PICKED_FRUIT, PICKED_SUPER_FRUIT, OK };

class Game
{
private:

	/*
	 *	Method that processes dl errors
	 */

	void	dlErrors(void);

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

	Snake					*snake;

	/*
	 *	pointer to the library wrapper
	 */

	InterfaceLibrary					*lib_wrap;

	/*
	 *	pointer to the Fruit object
	 */

	Fruit								*fruit;

	/*
	 *	pointer to the bonus fuit, that appears on the limited amount of time
	 */

	Fruit								*super_fruit;

	/*
	 *	pointer to the sound wrapper
	 */

    InterfaceSoundLib                   *sound_wrap;

	/*
	 *	Timer
	 */

	std::chrono::high_resolution_clock::time_point begin;
	std::chrono::high_resolution_clock::time_point fruit_timer;

	/*
	 *	Pointer to the function that creates a library
	 */
	InterfaceLibrary    *(* LibWrapCreator)(int w, int h);

	/*
	 *	Pointer to the function that deletes library
	 */
	void        (*DeleteLibWrap)(InterfaceLibrary *);

	/*
	 *	Speed of game
	 */

	long long game_speed;

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

	/*
	 *	Pointer to the function that creates an Sound wrapper
	 */
	InterfaceSoundLib    *(* createSoundWrap)(void);

	/*
	 *	Pointer to the function that deletes an Sound wrapper
	 */
	void        (*DeleteSoundWrap)(InterfaceSoundLib *);

    /*
     *  pointer to the dynamic library handler
     */
    void		*dl_handle;

    /*
     *  pointer to the dynamic sound handler
     */
    void        *dl_sound;

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

	/*
	 *	Method that loads a graphical library
	 */
	void	LoadGraphicLibrary(Directions dir);

	/*
	 *	Method that loads a sound library
	 */
	void	LoadSoundLibrary(void);

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
