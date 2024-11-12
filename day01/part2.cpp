#include <iostream>
#include <fstream>
#include <string>
#include <map>

char findDigit(const std::string& line, const std::map<std::string, char>& number_words, bool search_from_front) {
    
    char found_digit = '0';
    bool found = false;

    int start = search_from_front ? 0 : line.length() - 1; 
    int end = search_from_front ? line.length() : -1;
    int step = search_from_front ? 1 : -1;
    
    for(int i = start; i != end && !found; i += step) {

        if(isdigit(line[i])) {
            found_digit = line[i];
            found = true;
        }

        for(const auto& [word, digit] : number_words){
            if(line.compare(i, word.length(), word) == 0){
                found_digit = digit;
                found = true;
            }
        }
    }
    return found_digit;
}

int main() {
    
    std::ifstream input_file("input.txt");

    if (!input_file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    std::string current_line;
    std::map<std::string, char> number_words = {
        {"one", '1'}, {"two", '2'}, {"three", '3'},
        {"four", '4'}, {"five", '5'}, {"six", '6'},
        {"seven", '7'}, {"eight", '8'}, {"nine", '9'}
    };

    int total_sum = 0;
    
    while(std::getline(input_file, current_line)) {
        
        char first_digit = findDigit(current_line, number_words, true);
        char last_digit = findDigit(current_line, number_words, false);

        std::string number_str = {first_digit, last_digit};
        int value = std::atoi(number_str.c_str());
        total_sum += value;
    }

    std::cout << "Total sum: " << total_sum << std::endl;
    return 0;
}