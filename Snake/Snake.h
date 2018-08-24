#ifndef NIBBLER_SNAKE_H
#define NIBBLER_SNAKE_H

#include <vector>
#include <utility>
#include <iostream>

/*
 *	Directions
 */

enum Directions { UP = 1, DOWN, LEFT, RIGHT};

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

	void	MoveSnake(void);

	/*
	 *	Method to set snake's direction
	 */

	void	SetSnakeDirection(Directions d);

	/*
	 *	Method that returns all snake parts
	 */

	const std::vector<std::pair<int, int>>	&GetSnakeParts(void) const
	{
		return (snake_parts);
	};

	/*
	 *	Method that returns the direction of the Snake
	 */

	Directions	GetSnakeDirection(void) const
	{
		return (dir);
	}
};


#endif