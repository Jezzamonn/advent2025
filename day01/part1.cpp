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
    
    std::cout << "Solving Day 01 Part 1..." << std::endl;

    int position = 50;
    int size = 100;
    int numberOfZeros = 0;
    std::string line;
    while (std::getline(input, line)) {
        int value = std::stoi(line.substr(1));
        if (line[0] == 'L') {
            position = (((position - value) % size) + size) % size;
        }
        else {
            position = (position + value) % size;
        }
        if (position == 0) {
            numberOfZeros++;
        }
        std::cout << line << "\tnumberOfZeros: " << numberOfZeros << std::endl;
    }

    input.close();
    return 0;
}
