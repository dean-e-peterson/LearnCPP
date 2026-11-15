#include "SparseRuler.h"
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
	long long lowest_bit = bits & (-bits);
	long long left_bits = bits + lowest_bit;
	long long changed_bits = bits ^ left_bits;
	long long right_bits = (changed_bits / lowest_bit) >> 2;
	return left_bits | right_bits;
}
