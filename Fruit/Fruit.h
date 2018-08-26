#ifndef NIBBLER_FRUIT_H
#define NIBBLER_FRUIT_H

#include <random>
#include <vector>

class 	Fruit
{
private:

	/*
	 *	Position of a fruit
	 */

	int		i_pos;
	int 	j_pos;


	/*
	 *	random nb generator
	 */

	std::mt19937_64 rng;


	bool 	CheckFreePosition(const std::vector<std::vector<int>> &game_map,
							  const std::vector<std::pair<int, int>> &snake_parts);

public:

	/*
	 *	Canonical form of the class
	 */

			Fruit();
			~Fruit();
			Fruit(const Fruit &fr);
	Fruit	&operator=(const Fruit &fr);

	/*
	 *	Method that sets a position of the fruit
	 */

	void	SetFruitPosition(const std::vector<std::vector<int>> &game_map,
							 const std::vector<std::pair<int, int>> &snake_parts,
							 int w,
							 int h);

	/*
	 *	Method that returns the position of a fruit
	 */

	std::pair<int, int>	 	GetFruitPosition(void) const;

};


#endif //NIBBLER_FRUIT_H
