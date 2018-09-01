#ifndef NIBBLER_INTERFACELIBRARY_H
#define NIBBLER_INTERFACELIBRARY_H

#include <vector>
#include <chrono>
#include <utility>

#define SIDE_MENU_WIDTH 380

class InterfaceLibrary
{
public:
	virtual void		ClearImage(void) = 0;
	virtual void		RenderImage(void) = 0;
	virtual void 		RenderMap(const std::vector<std::vector<int>> &game_map) = 0;
	virtual void 		RenderSnake(const std::vector<std::pair<int, int>> &snake_parts, int dir) = 0;
	virtual void 		RenderFood(int x, int y, bool isBonusFruit) = 0;
	virtual int 		HandleInput(void) = 0;
	virtual void		RenderSideMenu(int w, int h, size_t score, float time_left, std::vector<int> score_data) = 0;
	virtual void		RenderGameOverScreen(void) = 0;

	virtual 			~InterfaceLibrary() {};
						InterfaceLibrary() {};
						InterfaceLibrary(const InterfaceLibrary &il) = delete;
	InterfaceLibrary	&operator=(const InterfaceLibrary &li) = delete;
};

#endif //NIBBLER_INTERFACELIBRARY_H
