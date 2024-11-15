#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <sstream>
#include <vector>

int main() {
    std::ifstream card_file("input.txt");
    std::string line;
    std::vector<int> card_copies(203, 1);
    int card_number = 0;

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

        for (int i = 1; i <= matches; i++) {
            if ((card_number + i) >= card_copies.size()) {
                break;
            }
            card_copies[card_number + i] += card_copies[card_number];
        }
        card_number++;
    }
    std::cout << "Total number of copies: "
              << std::accumulate(card_copies.begin(), card_copies.end(), 0);
}