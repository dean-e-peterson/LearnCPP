#include "utils.h"
#include <iostream>
#include <string_view>

int promptForInt(std::string_view prompt)
{
    std::cout << prompt;
    int value{};
    std::cin >> value;
    return value;
}
