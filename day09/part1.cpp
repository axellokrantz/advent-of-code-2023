#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream input_text("input.txt");
    std::string current_line;

    while (std::getline(input_text, current_line)) {
        std::vector<std::vector<int>> sequences;
        std::vector<int> sequence;
        std::stringstream ss(current_line);
        int number;
        while (ss >> number) {
            sequence.push_back(number);
        }

        sequences.push_back(sequence);
        bool allZeroes = false;

        while (!allZeroes) {
            std::vector<int> temp;
            for (int i = 0; i < sequence.size() - 1; i++) {
                temp.push_back(sequence[i + 1] - sequence[i]);
            }
            sequence = temp;
            sequences.push_back(sequence);

            allZeroes = std::all_of(sequence.begin(), sequence.end(),
                                    [](int x) { return x == 0; });
        }

        
    }
}