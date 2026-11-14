#include "utils.h"
#include <iostream>

int promptForInt(/* add char* or string param later */)
{
    std::cout << "Please enter an integer: ";
    int value{};
    std::cin >> value;
    return value;
}
