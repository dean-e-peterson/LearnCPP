#include "SparseRuler.h"
#include "utils.h"
#include <chrono>
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
        length = promptForInt("Length of ruler to generate: ");
        ticks = promptForInt("Number of tickmarks on ruler: ");
    }

    std::cout << "Calculating complete sparse rulers of length "
              << length << " with " << ticks << " tick marks...\n";

    // Initialize timing info.
    auto startTime = std::chrono::steady_clock::now();

    // Calculate rulers.
    std::vector<long long> bitList = getCompleteRulers(length, ticks);

    // Record timing info.
    double elapsedSeconds = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1> > >(std::chrono::steady_clock::now() - startTime).count();

    // Display rulers.
    std::cout << rulersToString(bitList, length);
    std::cout << bitList.size() << " rulers found in " << elapsedSeconds << " seconds.\n";

    std::cout << "Done\n";
    return 0;
}
