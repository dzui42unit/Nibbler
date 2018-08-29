//#include "./Game/Game.h"
#define FILE_SCORES "scores.nibbler"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void    ReadScoresFile(void)
{
    std::vector<int>    scores_data;
    std::string                 temp_string;
    std::fstream                file;

    file.open(FILE_SCORES, std::fstream::in | std::fstream::out | std::fstream::app);

    while (std::getline(file, temp_string))
    {
        scores_data.push_back(std::stoi(temp_string));
        temp_string.clear();
    }

    std::sort(scores_data.begin(), scores_data.end());

    for (auto elem : scores_data)
    {
        std::cout << "score: " << elem << std::endl;
    }

    file.close();

    // writting in a file

    file.open(FILE_SCORES, std::ofstream::out | std::ofstream::trunc);


    int new_one_score = 0;
    std::cout << "INPUT NEW SCORE: ";
    std::cin >> new_one_score;


    scores_data.push_back(new_one_score);
    sort(scores_data.begin(), scores_data.end(), [](const int a, const int b) {return a > b; });

    if (scores_data.size() > 3)
        scores_data.pop_back();

    for (auto elem : scores_data)
    {
        file << elem << "\n";
    }
    file.close();

}

int main(int argc,char **argv)
{

    ReadScoresFile();

    /*
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
     */

	return (0);
}