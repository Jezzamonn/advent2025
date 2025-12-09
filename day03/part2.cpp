#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "part2.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Could not open input file " << argv[1] << std::endl;
        return 1;
    }
    
    std::cout << "Solving Day 03 Part 2..." << std::endl;

    uint64_t sum = 0;
    std::string line;
    while (std::getline(input, line)) {
        uint64_t bestJoltage = getBestJoltages(line, 12)[0];
        sum += bestJoltage;
        std::cout << line << '\t' << bestJoltage << std::endl;
    }

    input.close();

    std::cout << sum << std::endl;

    return 0;
}

std::vector<uint64_t> getBestJoltages(std::string line, uint64_t numDigits) {

    // start at back, it's just the cumulative max
    std::vector<uint64_t> bestJoltages(line.length());

    // single digit case.
    if (numDigits == 1) {
        uint64_t max = 0;
        for (int i = line.length() - 1; i >= 0; i--) {
            uint64_t digit = line[i] - '0';
            max = std::max(max, digit);
            bestJoltages[i] = max;
        }
    }
    else {
        std::vector<uint64_t> prevBestJoltages = getBestJoltages(line, numDigits - 1);

        // This only really works for n = 2 though because of the uint64_t. That's fine.
        uint64_t powerOfTen = std::pow(10, numDigits - 1);

        uint64_t max = 0;
        for (int i = line.length() - numDigits; i >= 0; i--) {
            uint64_t digit = line[i] - '0';
            uint64_t bestUsingDigit = digit * powerOfTen + prevBestJoltages[i + 1];
            max = std::max(max, bestUsingDigit);
            bestJoltages[i] = max;
        }
    }

    return bestJoltages;
}