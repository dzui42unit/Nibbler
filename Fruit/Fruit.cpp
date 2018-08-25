#include "Fruit.h"

/*
 *	Method that returns the position of the fruit
 */

std::pair<int, int>	 	Fruit::GetFruitPosition(void) const
{
	return (std::make_pair(i_pos, j_pos));
}

/*
 *	Method that checks if the position if free
 */

bool 	Fruit::CheckFreePosition(const std::vector<std::vector<int>> &game_map,
						  			const std::vector<std::pair<int, int>> &snake_parts)
{
	if (game_map[i_pos][j_pos] != 0)
		return (false);

	for (auto elem : snake_parts)
	{
		if (elem.first == i_pos && elem.second == j_pos)
			return (false);
	}
	return (true);
}

void	Fruit::SetFruitPosition(const std::vector<std::vector<int>> &game_map,
						 const std::vector<std::pair<int, int>> &snake_parts,
						 int w,
						 int h)
{
	/*
	 * 	Set up for a map generation
	 */

	std::mt19937_64 rng(std::time(NULL));
	std::uniform_int_distribution<int> unif_range_w(1, w - 1);
	std::uniform_int_distribution<int> unif_range_h(1, h - 1);

	while (!CheckFreePosition(game_map, snake_parts))
	{
		i_pos = unif_range_h(rng);
		j_pos = unif_range_w(rng);
	}

}

/*
 *	Default construtor
 */

Fruit::Fruit()
{
	i_pos = 0;
	j_pos = 0;
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