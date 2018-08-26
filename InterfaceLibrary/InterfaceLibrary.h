#ifndef NIBBLER_INTERFACELIBRARY_H
#define NIBBLER_INTERFACELIBRARY_H

#include <vector>
#include <chrono>
#include <utility>

class InterfaceLibrary
{
public:

	virtual int		RunLib(const std::vector<std::vector<int>> &game_map,
							   const std::vector<std::pair<int, int>> &snake_parts,
							   int x_food,
							   int y_food,
							   int dir,
								size_t score,
							  	double time_left) = 0;
	virtual void 		RenderMap(const std::vector<std::vector<int>> &game_map) = 0;
	virtual void 		RenderSnake(const std::vector<std::pair<int, int>> &snake_parts, int dir) = 0;
	virtual void 		RenderFood(int x, int y) = 0;
	virtual int 		HandleInput(void) = 0;
	virtual void		RenderSideMenu(int w, int h, size_t score, float time_left) = 0;

	virtual 			~InterfaceLibrary() {};
						InterfaceLibrary() {};
						InterfaceLibrary(const InterfaceLibrary &il) = delete;
	InterfaceLibrary	&operator=(const InterfaceLibrary &li) = delete;
};

#endif //NIBBLER_INTERFACELIBRARY_H
