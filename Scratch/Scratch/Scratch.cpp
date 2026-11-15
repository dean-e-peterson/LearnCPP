#include "io.h"
#include <cmath>
#include <iostream>

double getFall(int seconds)
{
    constexpr double G = 9.8; // in meters/second.
    return G * seconds * seconds / 2;
}

int main()
{
    double towerHeight = promptForHeight();
    for (int seconds = 0; seconds <= 5; seconds++)
    {
        double ballHeight = towerHeight - getFall(seconds);
        ballHeight = std::fmax(ballHeight, 0.0); // floor.
        displayBallHeight(seconds, ballHeight);
    }

    return 0;
}