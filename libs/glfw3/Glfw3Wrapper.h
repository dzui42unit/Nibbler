#ifndef NIBBLER_GLFW3WRAPPER_H
#define NIBBLER_GLFW3WRAPPER_H

#include "../../InterfaceLibrary/InterfaceLibrary.h"
#include "GLFW/glfw3.h"

class Glfw3Wrapper : public InterfaceLibrary
{
private:

public:
	Glfw3Wrapper() = delete;
	Glfw3Wrapper(int w, int h);
	~Glfw3Wrapper();
	Glfw3Wrapper(const Glfw3Wrapper &glw3);
	Glfw3Wrapper	&operator=(const Glfw3Wrapper &glw3);

	void 			RenderMap(const std::vector<std::vector<int>> &game_map) final;
	void			ClearImage(void) final;
	void			RenderImage(void) final;
	void 			RenderFood(int x, int y, bool isBonusFruit);
	int 			HandleInput(void) final;
	void 			RenderSnake(const std::vector<std::pair<int, int>> &snake_parts, int dir) final ;
	void			RenderSideMenu(int w, int h, size_t score, float time_left, std::vector<int> score_data) final ;
	void			RenderGameOverScreen(void) final;
};


#endif
