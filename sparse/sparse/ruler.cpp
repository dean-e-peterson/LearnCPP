#include "ruler.h"
#include <vector>
#include <string>

// How it does it documentation.

std::string_view rulersToString(std::vector<int> bitsList = std::vector<int>{ 5, 7 }) // Remove hardcoded default.
{
	std::string result = std::string();
	for (const int bits : bitsList)
	{
		result.append(rulerToString(bits));
		result.append("\n");
	}
	return result;
}

std::string_view rulerToString(int)
{
	constexpr std::string_view placeholder{ ".. .  ." };
	return placeholder;
}