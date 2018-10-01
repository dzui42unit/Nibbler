#ifndef NIBBLER_SNAKE_H
#define NIBBLER_SNAKE_H

#include <vector>
#include <utility>
#include <iostream>

/*
 *	Directions
 */

enum Directions { NOTHING_PRESSED = -1, UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4, PAUSE = -2, SDL_LIB = 10, SFML_LIB = 20, OPENGL_LIB = 30, QUIT = -10};


class Snake
{
private:

	/*
	 *	All the parts of snake
	 */

	std::vector<std::pair<int, int>>	snake_parts;

	/*
	 *	Snake direction
	 */

	Directions 							dir;

	/*
	 *	Initial size of the Snake
	 */

	static const int					INIT_SIZE;

public:

	/*
	 *	All the methods for the canonical form
	 */

			Snake() = delete;
			Snake(int x, int y);
			Snake(const Snake &sn);
			~Snake();
	Snake	&operator=(const Snake &sn);

	/*
	 *	returns true, if this coordinate is a part of snake
	 */

	bool	CheckSnakePartCoordinate(int x, int y);

	/*
	 * 	Method to move a snake
	 */

	void	MoveSnake(bool increase);

	/*
	 *	Method to set snake's direction
	 */

	void	SetSnakeDirection(Directions d);

	/*
	 *	Method that returns all snake parts
	 */

	const std::vector<std::pair<int, int>>	&GetSnakeParts(void) const;

	/*
	 *	Method that returns the direction of the Snake
	 */

	Directions	GetSnakeDirection(void) const;
};


#endif
