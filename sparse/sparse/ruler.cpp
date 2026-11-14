#include "ruler.h"
#include <vector>
#include <string>

// How it does it documentation.

std::string rulersToString(std::vector<int> bitsList = std::vector<int>{ 5, 7 }) // Remove hardcoded default.
{
	std::string result;
	for (const int bits : bitsList)
	{
		result.append(rulerToString(bits));
		result.append("\n");
	}
	return result;
}

std::string rulerToString(int)
{
	const std::string placeholder{ ".. .  ." };
	return placeholder;
}