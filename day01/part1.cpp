#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input_file("input.txt");

    if (!input_file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    std::string current_line;
    int total_sum = 0;

    while (std::getline(input_file, current_line)) {
        char first_digit = '0';
        char last_digit = '0';

        for (char c : current_line) {
            if (isdigit(c)) {
                if (first_digit == '0') {
                    first_digit = c;
                } else {
                    last_digit = c;
                }
            }
        }

        if (last_digit == '0') {
            last_digit = first_digit;
        }

        std::string number_str = {first_digit, last_digit};
        total_sum += std::atoi(number_str.c_str());
    }

    std::cout << "Total sum: " << total_sum << std::endl;
    return 0;
}