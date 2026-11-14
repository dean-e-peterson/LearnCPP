#include "ruler.h"
#include "utils.h"
#include <iostream>

int main(int argc, char * [])
{
    int length{};
    int ticks{};

    // Get input.
    if (argc > 1)
    {
        std::cerr << "Command line parameters not yet implemented." << std::endl;
        return 1;
    }
    else
    {
        length = promptForInt();
        ticks = promptForInt();
    }

    // Calculate rulers.
    std::cout << "Calculating complete sparse rulers of length "
              << length << " with " << ticks << " tick marks...\n";
    // getCompleteRulers(length, ticks);

    // Display rulers.
    // std::cout << rulersToStrings();

    std::cout << "Done\n";
    return 0;
}
