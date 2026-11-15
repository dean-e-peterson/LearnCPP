#include "SparseRuler.h"
#include "utils.h"
#include <iostream>

int main(int argc, char * [])
{
    int length{};
    int ticks{};

    // Get input.
    if (argc > 1)
    {
        std::cerr << "Command line parameters not yet implemented.\n";
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
    // Initialize timing info.
    // getCompleteRulers(length, ticks);
    // Record timing info.

    // Display rulers.
    std::cout << rulersToString({ 3, 6 });
    // Display count and timing info.

    std::cout << "Done\n";
    return 0;
}
