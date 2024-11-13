#include <fstream>
#include <iostream>
#include <vector>

bool isSymbol(char c) { return (!isdigit(c) && c != '.'); }

bool hasAdjacentSymbol(int start_index, int digit_length,
                       const std::string& previous_line,
                       const std::string& current_line,
                       const std::string& next_line) {
    if (!previous_line.empty()) {
        for (int i = start_index - 1; i <= (start_index + digit_length); i++) {
            if (i >= 0 && i < previous_line.length() &&
                isSymbol(previous_line[i])) {
                return true;
            }
        }
    }

    if (start_index > 0 && isSymbol(current_line[start_index - 1])) {
        return true;
    } else if (start_index + digit_length < current_line.length() &&
               isSymbol(current_line[start_index + digit_length])) {
        return true;
    }

    if (!next_line.empty()) {
        for (int i = start_index - 1; i <= (start_index + digit_length); i++) {
            if (i >= 0 && i < next_line.length() && isSymbol(next_line[i])) {
                return true;
            }
        }
    }
    return false;
}

int processLine(const std::string& previous_line,
                const std::string& current_line, const std::string& next_line) {
    int line_sum = 0;
    for (int i = 0; i < current_line.length(); i++) {
        std::string str_digit = "";

        if (isdigit(current_line[i])) {
            while (i < current_line.length() && isdigit(current_line[i])) {
                str_digit += current_line[i];
                i++;
            }
        }

        if (!str_digit.empty() &&
            hasAdjacentSymbol((i - str_digit.length()), str_digit.length(),
                              previous_line, current_line, next_line)) {
            line_sum += std::stoi(str_digit);
        }
    }
    return line_sum;
}

int main() {
    std::ifstream input_file("input.txt");

    std::string previous_line = "";
    std::string current_line = "";
    std::string next_line = "";
    int sum = 0;

    std::getline(input_file, current_line);

    while (std::getline(input_file, next_line)) {
        sum += processLine(previous_line, current_line, next_line);
        previous_line = current_line;
        current_line = next_line;
    }
    sum += processLine(previous_line, current_line, "");
    std::cout << "Sum of all of the part numbers: " << sum << std::endl;
    return 0;
}