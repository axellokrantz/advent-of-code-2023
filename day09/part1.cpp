#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool allZeroes(const std::vector<int>& sequence) {
    return std::all_of(sequence.begin(), sequence.end(), [](int x) { return x == 0; });
}

int main() {
    std::ifstream input_text("input.txt");
    std::string current_line;
    long long total_sum = 0;

    while (std::getline(input_text, current_line)) {
        std::vector<std::vector<int>> sequences;
        std::vector<int> sequence;
        std::stringstream ss(current_line);
        int number;
        while (ss >> number) {
            sequence.push_back(number);
        }

        sequences.push_back(sequence);
        bool all_zero_flag = false;

        while (!all_zero_flag) {
            std::vector<int> temp;
            for (int i = 0; i < sequence.size() - 1; i++) {
                temp.push_back(sequence[i + 1] - sequence[i]);
            }
            sequence = temp;
            sequences.push_back(sequence);

            all_zero_flag = allZeroes(sequence);
        }

        for (int i = sequences.size() - 1; i >= 1; i--) {
            if (allZeroes(sequences[i])) {
                sequences[i].push_back(0);
            }
            sequences[i - 1].push_back(sequences[i].back() +
                                       sequences[i - 1].back());
        }
        total_sum += sequences[0].back();
    }
    std::cout << total_sum << std::endl;
}