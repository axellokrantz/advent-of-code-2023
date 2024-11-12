#include <iostream>
#include <fstream>
#include <string>

int main() {
    
    std::ifstream input_file("input.txt");

    if (!input_file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    std::string current_line;
    int total_sum = 0;
    
    while(std::getline(input_file, current_line)) {
        
    }

    std::cout << total_sum;
    return 0;
}