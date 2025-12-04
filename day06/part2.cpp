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

    std::cout << "Solving Day 06 Part 2..." << std::endl;

    std::string line;
    while (std::getline(input, line)) {
        // Part 2 logic here
    }

    input.close();
    return 0;
}
