#include "ruler.h"
#include <vector>
#include <string>

// How it does it documentation.

std::string rulersToString(std::vector<long long> bitsList = std::vector<long long>{ 5, 7 }) // Remove hardcoded default.
{
	std::string result;
	for (const long long bits : bitsList)
	{
		result.append(rulerToString(bits));
		result.append("\n");
	}
	return result;
}

std::string rulerToString(long long)
{
	const std::string placeholder{ ".. .  ." };
	return placeholder;
}

// Return next long long with same number of 1 bits.
// Uses Gosper's hack.  See https://iamkate.com/code/hakmem-item-175/
long long next(long long bits)
{
	// TDOO: Fix, tried to do Gosper's hack from memory.
	// 
	// Get right-most 1
	long long right_most_one = bits ^ (-bits);

	// Find length of ripple carry
	long long ripple_carry_length = 1LL;

	// Get low bits
	long long low_bits = bits & (right_most_one - 1) + (1LL << ripple_carry_length) - 1;

	// Get high bits
	long long high_bits = 1;

	return high_bits | low_bits;
}
