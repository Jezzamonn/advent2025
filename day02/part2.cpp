#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool isBadId(uint64_t num) {
    std::string numStr = std::to_string(num);

    int length = numStr.length();
    for (int sectionLength = 1; sectionLength <= length / 2; sectionLength++) {
        if (length % sectionLength != 0) {
            continue;
        }
        int numSections = length / sectionLength;

        // Loop over each substring
        bool couldBeMatch = true;
        for (int section = 1; section < numSections; section++) {
            int sectionStart = section * sectionLength;
            for (int i = 0; i < sectionLength; i++) {
                if (numStr[i] != numStr[sectionStart + i]) {
                    couldBeMatch = false;
                    break;
                }
            }
            if (!couldBeMatch) {
                break;
            }
        }

        if (couldBeMatch) {
            return true;
        }
    }
    return false;
}

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

    std::cout << "Solving Day 02 Part 2..." << std::endl;

    std::string line;
    uint64_t sumOfBad = 0;
    while (std::getline(input, line)) {
        int searchStart = 0;
        while (true) {
            int nextCommaPosition = line.find(',', searchStart);
            int numberEndPosition = (nextCommaPosition == std::string::npos) ? nextCommaPosition : line.length();

            int dashPosition = line.find('-', searchStart);

            uint64_t firstNum = std::stoull(line.substr(searchStart, dashPosition));
            uint64_t secondNum = std::stoull(line.substr(dashPosition+1, numberEndPosition));

            std::cout << firstNum << '-' << secondNum << std::endl;
    

            // naive approach: just iterate from first to second
            for (uint64_t i = firstNum; i <= secondNum; i++) {
                if (isBadId(i)) {
                    std::cout << '\t' << i << std::endl;
                    sumOfBad += i;
                }
            }

            if (nextCommaPosition == std::string::npos) {
                break;
            }

            searchStart = nextCommaPosition + 1;
        }
    }

    // // test:
    // for (int i = 2424; i < 2425; i++) {
    //     std::cout << i << '\t' << isBadId(i) << std::endl;
    // }

    // Output should be 4174379265 for the example
    // Got              2053167144 ??

    input.close();

    std::cout << sumOfBad << std::endl;

    return 0;
}
