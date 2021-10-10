#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace day2 {
void part1() {
    std::ifstream file{"inputfiles/day2/input"};

    int acc = 0;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss{line};

        int min, max;

        ss >> min;
        max = min;

        for (int i; ss >> i;) {
            if (i < min) min = i;
            if (i > max) max = i;
        }

        acc += max - min;
    }

    std::cout << "ans: " << acc << std::endl;
}

void part2() {
    std::ifstream file{"inputfiles/day2/input"};

    std::vector<int> v;
    v.reserve(8);

    int acc = 0;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss{line};

        v.clear();

        for (int val; ss >> val;) {
            v.push_back(val);
        }

        std::sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                int a = v[i];
                int b = v[j];

                auto d = div(b, a);

                if (!d.rem) {
                    acc += d.quot;
                }
            }
        }
    }

    std::cout << "ans: " << acc << std::endl;
}
}  // namespace day2
