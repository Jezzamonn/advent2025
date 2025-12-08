#include <iostream>
#include <fstream>
#include <string>
#include <vector>


// Lazy but maybe fast way of doing this?
bool isBadId(uint64_t num) {
    if (num < 10) {
        return false;
    }
    if (num < 100) {
        return num % 11 == 0;
    }
    if (num < 1000) {
        return false;
    }
    if (num < 10000) {
        return num % 101 == 0;
    }
    if (num < 100000) {
        return false;
    }
    if (num < 1000000) {
        return num % 1001 == 0;
    }
    if (num < 10000000) {
        return false;
    }
    if (num < 100000000) {
        return num % 10001 == 0;
    }
    if (num < 1000000000) {
        return false;
    }
    if (num < 10000000000) {
        return num % 100001 == 0;
    }
    if (num < 100000000000) {
        return false;
    }
    // Crash: Need to extend this.
    abort();
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
    
    std::cout << "Solving Day 02 Part 1..." << std::endl;

    std::string line;
    uint64_t sumOfBad = 0;
    while (std::getline(input, line)) {
        int searchStart = 0;
        while (true) {
            int nextCommaPosition = line.find(',', searchStart);
            if (nextCommaPosition == std::string::npos) {
                break;
            }

            int dashPosition = line.find('-', searchStart);

            uint64_t firstNum = std::stoull(line.substr(searchStart, dashPosition));
            uint64_t secondNum = std::stoull(line.substr(dashPosition+1, nextCommaPosition));

            std::cout << firstNum << '-' << secondNum << std::endl;
    

            // naive approach: just iterate from first to second
            for (uint64_t i = firstNum; i <= secondNum; i++) {
                if (isBadId(i)) {
                    sumOfBad += i;
                }
            }

            searchStart = nextCommaPosition + 1;
        }
    }

    // // test:
    // for (int i = 0; i < 45; i++) {
    //     std::cout << i << '\t' << isBadId(i) << std::endl;
    // }

    input.close();

    std::cout << sumOfBad << std::endl;

    return 0;
}
