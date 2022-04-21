#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <random>
class Rps_board {

	std::vector<int> score = {0,0};
	int winner;
public:
	void playround(std::string in);
};