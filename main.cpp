#include "./Game/Game.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main(int argc,char **argv)
{
	Game					*game;

	game = nullptr;
	if (argc != 3)
	{
		std::cout << "Invalid usage" << std::endl;
		std::cout << "Example: " << argv[0] << " <int> <int>" << std::endl;
		exit(0);
	}
	else
	{
		try
		{
			game = new Game(argv[1], argv[2]);
			game->RunGame();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	delete game;
	return (0);
}