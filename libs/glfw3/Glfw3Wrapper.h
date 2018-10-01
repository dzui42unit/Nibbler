#ifndef NIBBLER_GLFW3WRAPPER_H
#define NIBBLER_GLFW3WRAPPER_H

#include "InterfaceLibrary.h"
#include "FTGL/ftgl.h"
#include "GLFW/glfw3.h"
#include <map>
#include <iostream>
#include <fstream>

class Glfw3Wrapper : public InterfaceLibrary
{
private:
	GLFWwindow* 	window;
	int 			width;
	int				height;
	FTFont			*font;
public:
	Glfw3Wrapper() = delete;
					Glfw3Wrapper(int w, int h);
					~Glfw3Wrapper();
					Glfw3Wrapper(const Glfw3Wrapper &glw3);
	Glfw3Wrapper	&operator=(const Glfw3Wrapper &glw3);

	void 			RenderMap(const std::vector<std::vector<int>> &game_map) final;
	void			ClearImage(void) final;
	void			RenderImage(void) final;
	void 			RenderFood(int x, int y, bool isBonusFruit) final;
	int 			HandleInput(void) final;
	void 			RenderSnake(const std::vector<std::pair<int, int>> &snake_parts, int dir) final ;
	void			RenderSideMenu(int w, int h, size_t score, float time_left, std::vector<int> score_data) final ;
	void			RenderGameOverScreen(void) final;
	static int      _key;
};


#endif
