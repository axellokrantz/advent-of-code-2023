#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>

int main() {
    std::ifstream card_file("input.txt");
    std::string line;

    int total_score = 0;

    while (std::getline(card_file, line)) {
        size_t card_separator = line.find(":");
        std::string card_numbers = line.substr(card_separator + 1);
        std::set<int> winning_numbers;
        std::set<int> my_numbers;

        size_t numbers_separator = line.find("|");
        std::string winning_section = line.substr(
            card_separator + 1, numbers_separator - (card_separator + 1));
        std::string my_section = line.substr(numbers_separator + 1);

        std::stringstream my_stream(my_section);
        std::stringstream winning_stream(winning_section);

        int number;
        while (my_stream >> number) {
            my_numbers.insert(number);
        }

        while (winning_stream >> number) {
            winning_numbers.insert(number);
        }

        int matches = 0;
        for (const auto& number : my_numbers) {
            if (winning_numbers.find(number) != winning_numbers.end()) {
                matches++;
            }
        }
        total_score += (matches > 0) ? pow(2, matches - 1) : 0;
    }
    std::cout << "Total score: " << total_score;
}