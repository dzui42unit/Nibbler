#include "Glfw3Wrapper.h"

/*
 *	A method that renders a game over screen
 */

void	Glfw3Wrapper::RenderGameOverScreen(void)
{

}

/*
 *	A function that renders a side menu in a simple manner
 */

void	Glfw3Wrapper::RenderSideMenu(int w, int , size_t score, float time_left, std::vector<int> score_data)
{

}

/*
 *	Method that clears an image
 */

void	Glfw3Wrapper::ClearImage(void)
{

}

/*
 *	Method that puts image to the window
 */

void	Glfw3Wrapper::RenderImage(void)
{

}

/*
 *	Method that renders a Snake
 */

void 			Glfw3Wrapper::RenderSnake(const std::vector<std::pair<int, int>> &snake_parts, int dir)
{

}


/*
 *	Key hook handler for user input
 *	Movement of the snake UP, DOWN, LEFT, RIGHT and ESC
 */

int 			Glfw3Wrapper::HandleInput(void)
{
	return (0);
}


/*
 *	A method to render a map
 */

void 		 Glfw3Wrapper::RenderMap(const std::vector<std::vector<int>> &game_map)
{

}

/*
 *	Default constructor for the SDL wrap
 */

Glfw3Wrapper::Glfw3Wrapper(int w, int h)
{

}

/*
 *	Method that renders a fruit
 */

void	Glfw3Wrapper::RenderFood(int i_pos, int j_pos, bool isBonusFruit)
{

}

/*
 *	Copy constructor
 */

Glfw3Wrapper::Glfw3Wrapper(const Glfw3Wrapper &glfw3)
{

}

/*
 *	Copy assignment operator
 */

Glfw3Wrapper 	&Glfw3Wrapper::operator=(const Glfw3Wrapper &glfw3)
{

	return (*this);
}

/*
 *	Destructor
 */

Glfw3Wrapper::~Glfw3Wrapper()
{

}

extern "C" Glfw3Wrapper      *createWrapper(int w, int h)
{
	return (new Glfw3Wrapper(w, h));
}
extern "C" void                deleteWrapper(Glfw3Wrapper *lib)
{
	delete lib;
}
