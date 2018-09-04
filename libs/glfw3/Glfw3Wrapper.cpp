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
	GLFWwindowrefreshfun(window);
}

/*
 *	Method that puts image to the window
 */

void	Glfw3Wrapper::RenderImage(void)
{
	float ratio;
//	int width, height;
//	glfwGetFramebufferSize(window, width, height);
//	ratio = width / (float) height;
//	glViewport(0, 0, width, height);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
//	glBegin(GL_TRIANGLES);
//	glColor3f(1.f, 0.f, 0.f);
//	glVertex3f(-0.6f, -0.4f, 0.f);
//	glColor3f(0.f, 1.f, 0.f);
//	glVertex3f(0.6f, -0.4f, 0.f);
//	glColor3f(0.f, 0.f, 1.f);
//	glVertex3f(0.f, 0.6f, 0.f);
//	glEnd();
//	glfwSwapBuffers(window);
//	glfwPollEvents();
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
	/*
	 * Initialization of GLFW
	 */
	glfwInit();

	/*
	 * Set up of the  GLFW
	 * Setting of minimal and maximal version of OpenGL.
	 */

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	/*
	 * Setting up a profile for which a context is created
	 */
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/*
	 *	Disable of the window resizing
	 */
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

//	window = glfwCreateWindow(w * 32 + SIDE_MENU_WIDTH, h * 32, "Nibbler", NULL, NULL);
//
//	if (!window)
//	{
//		std::cout << "ERROR GLFW3 CREATE WINDOW" << std::endl;
//		exit(0);
//	}
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
	window = glfw3.window;
}

/*
 *	Copy assignment operator
 */

Glfw3Wrapper 	&Glfw3Wrapper::operator=(const Glfw3Wrapper &glfw3)
{
	window = glfw3.window;
	return (*this);
}

/*
 *	Destructor
 */

Glfw3Wrapper::~Glfw3Wrapper()
{
	glfwDestroyWindow(window);
}

extern "C" Glfw3Wrapper      *createWrapper(int w, int h)
{
	return (new Glfw3Wrapper(w, h));
}
extern "C" void                deleteWrapper(Glfw3Wrapper *lib)
{
	delete lib;
}
