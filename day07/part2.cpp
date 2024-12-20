#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

struct Hand {
    long long score;
    int bid;
};

 std::map<char, int> card_values = {
        {'A', 13}, {'K', 12}, {'Q', 11}, {'T', 10},
        {'9', 9},  {'8', 8},  {'7', 7},  {'6', 6},  {'5', 5},
        {'4', 4},  {'3', 3},  {'2', 2}, {'J', 1}};

std::map<char, int> addJokers(std::string hand){
    std::map<char, int> map;
    int number_of_jokers = 0;
    for (auto& c : hand) {
        if(c != 'J'){
            map[c]++;
        }
        else{
            number_of_jokers++;
        }
    }

    char best_card = ' ';
    int highest_freq = 0;
    int highest_value = 0;

    for(auto& pair : map){
        char card = pair.first;
        int freq = pair.second;
        int value = card_values[card];

        if(highest_freq < freq || (highest_freq == freq && value > highest_value) ){
            best_card = card;
            highest_freq = freq;
            highest_value = value;
        }    
    }

    while(number_of_jokers > 0){
        map[best_card]++;
        number_of_jokers--;
    }
    return map;
}

long long calculateScore(std::string hand) {

    long long score = 0;
    std::map<char, int> map = addJokers(hand);
    
    if (map.size() == 1) {
        score = 60000000000;
    } else if (map.size() == 2) {
        bool is_four = false;
        for (auto& pair : map) {
            if (pair.second == 4) {
                score = 50000000000;
                is_four = true;
                break;
            }
        }
        if (!is_four) {
            score = 40000000000;
        }
    } else if (map.size() == 3) {
        bool is_three = false;
        for (auto& pair : map) {
            if (pair.second == 3) {
                score = 30000000000;
                is_three = true;
                break;
            }
        }
        if (!is_three) {
            score = 20000000000;
        }
    } else if (map.size() == 4) {
        score = 10000000000;
    } else {
        score = 0;
    }

    long long multiplier = 100000000;
    for (int i = 0; i < hand.length(); i++) {
        int value = card_values[hand[i]];
        score += multiplier * value;
        multiplier /= 100;
    }
    return score;
}

int main() {
    std::ifstream input_file("input.txt");
    std::string line;
    std::vector<Hand> hands;

    while (std::getline(input_file, line)) {
        std::string hand = line.substr(0, line.find(" "));
        int bid = std::stoi(line.substr(line.find(" ") + 1));
        long long score = calculateScore(hand);
        hands.push_back({score, bid});
    }
    
    std::sort(hands.begin(), hands.end(), [](const Hand& a, const Hand& b) {
        return a.score < b.score;
    });

    long long total_winning = 0;
    for(int i = 0; i < hands.size(); i++){
        total_winning += (i + 1) * hands[i].bid;
    }

    std::cout << "Total winning is: " << total_winning << std::endl;
    return 0;
}