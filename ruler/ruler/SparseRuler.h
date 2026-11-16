#ifndef SPARSE_RULER_H
#define SPARSE_RULER_H
#include <vector>
#include <string>

// What it does and how to use it documenatation.

std::string rulersToString(std::vector<long long> bitsList, int length);
std::string rulerToString(long long bits, int length);
std::vector<long long> getCompleteRulers(int length, int ticks);

// Probably do not need to be declared in the header because they 
// are only accessed from the .cpp file they are defined in.
//bool isComplete(long long bits, int length);
//long long next(long long bits);

#endif
