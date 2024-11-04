#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

int reverse(int num){
    std::string str = std::to_string(num);
    std::reverse(str.begin(), str.end());
    return std::stoi(str);
}

bool findReverse(std::vector<int> numbers, int num){
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] == num) {
            return true;
        }
    }
    return false;
}

std::vector<std::pair<int, int>> solution(const std::vector<int>& numbers) {
    
    // TODO: implement solution here
    std::vector<std::pair<int, int>> pair;

    for(int i = 0; i < numbers.size(); i++) {

        int first = numbers[i];
        int reversed = reverse(first);

        if(findReverse(numbers, reversed)) {
            pair.push_back({first, reversed});
        }
    }
    return pair;
}

int main() {
    std::vector<int> numbers = {13,31,32};
    solution(numbers);
}