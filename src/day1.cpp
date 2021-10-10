#include <fstream>
#include <iostream>
#include <sstream>

namespace day1 {
void part1() {
    std::ifstream file{"inputfiles/day1/input"};

    char first, last;

    file >> first;
    last = first;

    int acc = 0;

    for (char c = 0; file; file >> c) {
        if ('0' <= c && c <= '9') {
            if (last == c) {
                acc += c - '0';
            }
            last = c;
        }
    }
    if (first == last) {
        acc += first - '0';
    }

    std::cout << "ans: " << acc << std::endl;
}

void part2() {
    std::ifstream file{"inputfiles/day1/input"};

    std::ostringstream ss;

    for (char c = 0; file; file >> c) {
        if ('0' <= c && c <= '9') {
            ss << c;
        }
    }

    auto s = ss.str();

    int acc = 0;

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == s[(i + s.length() / 2) % s.length()]) {
            acc += s[i] - '0';
        }
    }

    std::cout << "ans: " << acc << std::endl;
}
}  // namespace day1
