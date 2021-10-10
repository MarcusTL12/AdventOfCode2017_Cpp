#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

#include "days.h"

std::vector<std::vector<std::function<void()>>> funcs = {
    {day1::part1, day1::part2},
};

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Give day and part as command line arguments!\n";
        return 0;
    } else {
        size_t day, part;
        std::istringstream ss{argv[1]};

        ss >> day;
        ss = std::istringstream{argv[2]};
        ss >> part;

        funcs[day - 1][part - 1]();
    }
}
