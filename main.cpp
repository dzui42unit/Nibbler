#include "./Game/Game.h"

int main(int argc,char **argv)
{
	std::shared_ptr<Game>	game;

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
			game = std::make_shared<Game>(Game(argv[1], argv[2]));
			game->RunGame();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}