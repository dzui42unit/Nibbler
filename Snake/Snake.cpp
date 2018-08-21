#include "Snake.h"

/*
 * 	Default constructor
 */

Snake::Snake(int width, int height)
{
	/*
	 *	Set a head position and other 3 cells of snake
	 */

	snake_parts.emplace_back(width / 2, height / 2);
	snake_parts.emplace_back(snake_parts[0].first, snake_parts[0].second + 1);
	snake_parts.emplace_back(snake_parts[0].first, snake_parts[0].second + 2);
	snake_parts.emplace_back(snake_parts[0].first, snake_parts[0].second + 3);

	/*
	 *	Set default direction as UP
	 */

	dir = Directions::UP;
}

/*
 *	Copy constructor
 */

Snake::Snake(const Snake &sn)
{
	snake_parts = sn.snake_parts;
	dir = sn.dir;
}

/*
 * 	Copy assignment operator
 */

Snake	&Snake::operator=(const Snake &sn)
{
	snake_parts = sn.snake_parts;
	dir = sn.dir;
	return (*this);
}

/*
 * 	Destructor
 */

Snake::~Snake()
{

}

/*
 * 	Check is this coordinate is a part of a snake
 */

bool	Snake::CheckSnakePartCoordinate(int x, int y)
{
	for (auto elem : snake_parts)
	{
		if (y == elem.first && x == elem.second)
			return (true);
	}
	return (false);
}

/*
 *	Method to move a snake
 */

void	Snake::MoveSnake(void)
{
	std::pair<int, int>	prev_part_pos = snake_parts[0];
	std::pair<int, int>	cur_part_pos;

	/*
	 * 	Move up
	 * 	change y coord
	 */

	if (dir == Directions::UP)
		snake_parts[0].second -= 1;

	/*
	 *	Move down
	 *	change y coord
	 */

	if (dir == Directions::DOWN)
		snake_parts[0].second += 1;

	/*
	 *	Move left
	 *	change x coord
	 */

	if (dir == Directions::LEFT)
		snake_parts[0].first -= 1;
	/*
	 *	Move right
	 *	change x
	 */

	if (dir == Directions::RIGHT)
		snake_parts[0].first += 1;

	/*
	 *	Move all other parts
	 */

	for (size_t i = 1; i < snake_parts.size(); i++)
	{
		cur_part_pos = snake_parts[i];
		snake_parts[i].first = prev_part_pos.first;
		snake_parts[i].second = prev_part_pos.second;
		prev_part_pos = cur_part_pos;
	}
}

void	Snake::SetSnakeDirection(Directions d)
{
	if (dir == Directions::UP && d != Directions::DOWN)
		dir = d;
	if (dir == Directions::DOWN && d != Directions::UP)
		dir = d;
	if (dir == Directions::LEFT && d != Directions::RIGHT)
		dir = d;
	if (dir == Directions::RIGHT && d != Directions::LEFT)
		dir = d;
}