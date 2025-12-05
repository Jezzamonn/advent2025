#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

    std::cout << "Solving Day 01 Part 2..." << std::endl;

    int position = 50;
    int size = 100;
    int numberOfZeros = 0;
    std::string line;
    while (std::getline(input, line)) {
        int prevPosition = position;
        int value = std::stoi(line.substr(1));
        int numFullRotations = value / size;
        numberOfZeros += numFullRotations;

        int remainder = value % size;
        if (line[0] == 'L') {
            position -= remainder;
            if (position == 0 && remainder != 0) {
                numberOfZeros++;
            }
            else if (position < 0) {
                position += size;
                if (prevPosition != 0) {
                    numberOfZeros++;
                }
            }
        }
        else {
            position += remainder;
            if (position >= size) {
                position -= size;
                numberOfZeros++;
            }
        }
        std::cout << line << "\t" << prevPosition << "->" << position << "\tnumberOfZeros: " << numberOfZeros << std::endl;
    }

    // // brute force?

    // int position = 50;
    // int size = 100;
    // int numberOfZeros = 0;
    // std::string line;
    // while (std::getline(input, line)) {
    //     int prevPosition = position;
    //     int value = std::stoi(line.substr(1));

    //     if (line[0] == 'L') {
    //         for (int i = 0; i < value; i++) {
    //             position--;
    //             if (position == 0) {
    //                 numberOfZeros++;
    //             }
    //             if (position < 0) {
    //                 position += size;
    //             }
    //         }
    //     }
    //     else {
    //         for (int i = 0; i < value; i++) {
    //             position++;
    //             if (position == 100) {
    //                 numberOfZeros++;
    //                 position = 0;
    //             }
    //         }
    //     }
    //     std::cout << line << "\t" << prevPosition << "->" << position << "\tnumberOfZeros: " << numberOfZeros << std::endl;
    // }

    // 5765 = too low?
    // 5782 = correct
    // 6239 = too high

    input.close();
    return 0;
}
