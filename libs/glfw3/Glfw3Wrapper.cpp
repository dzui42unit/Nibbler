#include "Glfw3Wrapper.h"
#include "../../Snake/Snake.h"
#include <cmath>

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
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
}

/*
 *	Method that puts image to the window
 */

void	Glfw3Wrapper::RenderImage(void)
{
	glfwSwapBuffers(window);
}

/*
 *	Method that renders a Snake
 */

void 			Glfw3Wrapper::RenderSnake(const std::vector<std::pair<int, int>> &snake_parts, int dir)
{
	int x;
	int y;

	for (size_t i = 1; i < snake_parts.size(); i++)
	{
		x = snake_parts[i].second * 32;
		y = snake_parts[i].first * 32;
		glColor3f(0.18, 0.54, 0.32);
		glRecti(x, y, x + 32, y + 32);
	}
	glColor3f(0.26, 0.91, 0.52);
	x = snake_parts[0].second * 32;
	y = snake_parts[0].first * 32;
	glRecti(x, y, x + 32, y + 32);
}


/*
 *	Key hook handler for user input
 *	Movement of the snake UP, DOWN, LEFT, RIGHT and ESC
 */

int 			Glfw3Wrapper::HandleInput(void)
{
	static std::map<int, int>	key_events = { {GLFW_KEY_SPACE, GLFW_RELEASE}, {GLFW_KEY_KP_1, GLFW_RELEASE}, {GLFW_KEY_KP_2, GLFW_RELEASE}, {GLFW_KEY_KP_3, GLFW_RELEASE} };
	int state;

	glfwPollEvents();



	state = glfwGetKey(window, GLFW_KEY_ESCAPE);
	if (state == GLFW_PRESS)
		return(0);
	state = glfwGetKey(window, GLFW_KEY_SPACE);
	if (state == GLFW_RELEASE && key_events[GLFW_KEY_SPACE] == GLFW_PRESS)
	{
		key_events[GLFW_KEY_SPACE] = state;
		return (Directions::PAUSE);
	}
	key_events[GLFW_KEY_SPACE] = state;
	state = glfwGetKey(window, GLFW_KEY_UP);
	if (state == GLFW_PRESS)
		return (Directions::UP);
	state = glfwGetKey(window, GLFW_KEY_DOWN);
	if (state == GLFW_PRESS)
		return (Directions::DOWN);
	state = glfwGetKey(window, GLFW_KEY_LEFT);
	if (state == GLFW_PRESS)
		return (Directions::LEFT);
	state = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (state == GLFW_PRESS)
		return (Directions::RIGHT);
	state = glfwGetKey(window, GLFW_KEY_KP_1);
	if (state == GLFW_RELEASE && key_events[GLFW_KEY_KP_1] == GLFW_PRESS)
	{
		key_events[GLFW_KEY_KP_1] = state;
		return (Directions::SDL_LIB);
	}
	key_events[GLFW_KEY_KP_1] = state;
	state = glfwGetKey(window, GLFW_KEY_KP_2);
	if (state == GLFW_RELEASE && key_events[GLFW_KEY_KP_2] == GLFW_PRESS)
	{
		key_events[GLFW_KEY_KP_2] = state;
		return (Directions::SFML_LIB);
	}
	key_events[GLFW_KEY_KP_2] = state;
	return (Directions::NOTHING_PRESSED);
}


/*
 *	A method to render a map
 */

void 		 Glfw3Wrapper::RenderMap(const std::vector<std::vector<int>> &game_map)
{
	int x;
	int y;

	glRecti(x, y, x + 32, y + 32);
	for (size_t i = 0; i < game_map.size(); i++)
	{
		for (size_t j = 0; j < game_map[i].size(); j++)
		{
			x = j * 32;
			y = i * 32;
			if (game_map[i][j])
				glColor3f(0.73, 0.68, 0.49);
			else
				glColor3f(0.96, 0.9, 0.63);
			glRecti(x, y, x + 32, y + 32);
		}
	}
}

/*
 *	Default constructor for the SDL wrap
 */

Glfw3Wrapper::Glfw3Wrapper(int w, int h)
{
	width = w * 32 + SIDE_MENU_WIDTH;
	height = h * 32;

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(width, height, "Nibbler OpenGl", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwMakeContextCurrent(window);

	/*
	 *	Initialize callback function for the input handler
	 */
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glOrtho(0, width, height, 0, 0, 1);

//	glfwReadImage("game_over.png", image_data, nullptr);
}

/*
 *	Method that renders a fruit
 */

void	Glfw3Wrapper::RenderFood(int i_pos, int j_pos, bool isBonusFruit)
{
	int x;
	int y;

	x = j_pos * 32;
	y = i_pos * 32;
	if (isBonusFruit) {
		glColor3f(0.38, 0.21, 0.56);
	}
	else {
		glColor3f(1.0, 0.47, 0.47);
	}
	glRecti(x, y, x + 32, y + 32);
}

/*
 *	Copy constructor
 */

Glfw3Wrapper::Glfw3Wrapper(const Glfw3Wrapper &glfw3)
{
    window = glfw3.window;
	width = glfw3.width;
	height = glfw3.height;
	image_data = glfw3.image_data;
}

/*
 *	Copy assignment operator
 */

Glfw3Wrapper 	&Glfw3Wrapper::operator=(const Glfw3Wrapper &glfw3)
{
    window = glfw3.window;
	width = glfw3.width;
	height = glfw3.height;
	image_data = glfw3.image_data;
	return (*this);
}

/*
 *	Destructor
 */

Glfw3Wrapper::~Glfw3Wrapper()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

extern "C" Glfw3Wrapper      *createWrapper(int w, int h)
{
	return (new Glfw3Wrapper(w, h));
}
extern "C" void                deleteWrapper(Glfw3Wrapper *lib)
{
	delete lib;
}
