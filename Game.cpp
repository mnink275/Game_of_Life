#include "Game.h"

int GAME_FIELD_HEIGHT = 25;
int GAME_FIELD_WIDTH = 40;

Game::Game() : pause(16), neighbors_sum(0)
{
	//std::cout << "Game started!" << std::endl;
	startFieldInitializer();
}


void Game::start()
{
	while (1)
	{
		gameProceed();
		std::this_thread::sleep_for(pause);
		system("CLS");
		print();
	}
}


void Game::startFieldInitializer()
{
	gameField.resize(GAME_FIELD_HEIGHT,
		std::vector<int>(GAME_FIELD_WIDTH, 0));
	// Game Field:
	// vec[0] = { ... }
	// ...................
	// ...................
	// ...................
	// vec[last] = { ... }
	for (int i = 1; i < GAME_FIELD_HEIGHT - 1; i++)
	{
		for (int j = 1; j < GAME_FIELD_WIDTH - 1; j++)
		{
			gameField[i][j] = std::round((double)std::rand() / (double)RAND_MAX);
		}
	}
	print();
}


void Game::print()
{
	for (int i = 1; i < GAME_FIELD_HEIGHT - 1; i++)
	{
		for (int j = 1; j < GAME_FIELD_WIDTH - 1; j++)
		{			
			if (gameField[i][j] == 1)
			{
				std::cout << gameField[i][j] << "  ";
			}
			else
			{
				std::cout << " " << "  ";
			}
		}
		std::cout << std::endl;
	}
}


void Game::gameProceed()
{
	std::vector<std::vector<int>> sums(GAME_FIELD_HEIGHT,
		std::vector<int>(GAME_FIELD_WIDTH, 0));
	int neighbors_sum = 0;
	for (int i = 1; i < GAME_FIELD_HEIGHT - 1; i++)
	{
		for (int j = 1; j < GAME_FIELD_WIDTH - 1; j++)
		{
			neighbors_sum = 0;
			for (int k = i - 1; k <= i + 1; k++)
			{
				for (int l = j - 1; l <= j + 1; l++)
				{
					if (gameField[k][l] == 1)
					{
						neighbors_sum++;
					}
				}
			}
			sums[i][j] = neighbors_sum - gameField[i][j];
		}
	}

	for (int i = 1; i < GAME_FIELD_HEIGHT - 1; i++)
	{
		for (int j = 1; j < GAME_FIELD_WIDTH - 1; j++)
		{
			if (sums[i][j] == 3 && gameField[i][j] == 0)
			{
				gameField[i][j] = 1;
			}
			else if (sums[i][j] < 2 || sums[i][j] > 3)
			{
				gameField[i][j] = 0;
			}
		}
	}

	
}