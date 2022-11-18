#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

class Game
{
public:
	Game();
	void start();
	void print();
	void gameProceed();

private:
	void startFieldInitializer();
	std::vector<std::vector<int>> gameField;
	std::chrono::milliseconds pause;
	int neighbors_sum;
};

