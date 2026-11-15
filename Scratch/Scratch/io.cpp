#include "io.h"
#include <iostream>

double promptForHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double height{};
	std::cin >> height;
	return height;
}

void displayBallHeight(int seconds, double height)
{
	if (height > 0)
	{
		std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
	}
	else
	{
		std::cout << "At " << seconds << " seconds, the ball is on the ground\n";
	}
}
