#include "SparseRuler.h"
#include <vector>
#include <string>

// How it does it documentation.

std::string rulersToString(std::vector<long long> bitsList, int length)
{
	std::string result;
	for (const long long bits : bitsList)
	{
		result.append(rulerToString(bits, length));
		result.append("\n");
	}
	return result;
}

std::string rulerToString(long long bits, int length)
{
	auto result = std::string();
	for (int i = 0; i < length + 1; i++)
	{
		const bool ithBitIsOne = static_cast<bool>(bits & (1LL << i));
		if (ithBitIsOne)
		{
			result.append(".");
		}
		else
		{
			result.append(" ");
		}
	}
	return result;
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

// Attach ones on both ends of a bit combo.
long long attachEnds(long long bits, int length)
{
	long long result = 1LL; // Attach lower end.
	result = result | (bits << 1); // Insert middle.
	result = result | (1LL << length); // Attach high end.
	return result;
}

bool isComplete(long long bits, int length)
{
	bool result = true;
	for (int i = 1; i <= length; i++)
	{
		bool measuresi = static_cast<bool>(bits & (bits << i));
		result = (result && measuresi);
	}
	return result;
}

std::vector<long long> getCompleteRulers(int length, int ticks)
{
	auto result = std::vector<long long>();
	constexpr int endTicks = 2;

	// First combination of inner bits with the tick marks except the two ends.
	long long innerCandidate = (1LL << (ticks - endTicks)) - 1;

	const long long overflow = 1LL << (length + 1 - endTicks);
	while (innerCandidate < overflow)
	{
		const long long candidate = attachEnds(innerCandidate, length);
		if (isComplete(candidate, length))
		{
			result.push_back(candidate);
		}

		// Get next combination of inner bits from Gosper's hack with next().
		innerCandidate = next(innerCandidate);
	}
	return result;
}
