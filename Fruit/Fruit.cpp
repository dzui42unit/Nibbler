#include "Fruit.h"

/*
 *	Method that returns the position of the fruit
 */

std::pair<int, int>	 	Fruit::GetFruitPosition(void) const
{
	return (std::make_pair(i_pos, j_pos));
}

/*
 *	Method that checks if the position is free on the map
 *	is not a part of the map of snake
 */

bool 	Fruit::CheckFreePosition(const std::vector<std::vector<int>> &game_map,
						  			const std::vector<std::pair<int, int>> &snake_parts, int fruit_i_pos, int  fruit_j_pos)
{
	if (fruit_i_pos == i_pos && fruit_j_pos == j_pos)
		return (false);
	if (game_map[i_pos][j_pos] != 0)
		return (false);

	for (auto elem : snake_parts)
	{
		if (elem.first == i_pos && elem.second == j_pos)
			return (false);
	}
	return (true);
}

/*
 *	Method that sets a new position of the fruit on the map
 */

void	Fruit::SetFruitPosition(const std::vector<std::vector<int>> &game_map,
						 const std::vector<std::pair<int, int>> &snake_parts,
						 int w,
						 int h, int fruit_i, int fruit_j)
{
	/*
	 * 	Set up for a coordinates generation
	 */

	std::uniform_int_distribution<int> unif_range_w(1, w - 1);
	std::uniform_int_distribution<int> unif_range_h(1, h - 1);

	i_pos = unif_range_h(rng);
	j_pos = unif_range_w(rng);

	/*
	 *	Generate new coordinates until they will not occupy a free cell on the game map
	 */

	while (!CheckFreePosition(game_map, snake_parts, fruit_i, fruit_j))
	{
		i_pos = unif_range_h(rng);
		j_pos = unif_range_w(rng);
	}

}

/*
 *	Default constructor
 */

Fruit::Fruit()
{
	std::mt19937_64 rng(std::time(NULL));

	i_pos = -1;
	j_pos = -1;
}

/*
 *	Copy constructor
 */

Fruit::Fruit(const Fruit &fr)
{
	i_pos = fr.i_pos;
	j_pos = fr.j_pos;
}

/*
 *	Copy assignment operator
 */

Fruit	&Fruit::operator=(const Fruit &fr)
{
	i_pos = fr.i_pos;
	j_pos = fr.j_pos;

	return (*this);
}

/*
 *	Destructor
 */

Fruit::~Fruit()
{

}

/*
 *	method that hides a fruit from the map
 */

void					Fruit::HideFruit(void)
{
	i_pos = -1;
	j_pos = -1;
}
