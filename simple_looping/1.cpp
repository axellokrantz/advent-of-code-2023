#include <vector>
#include <iostream>
#include <cmath>

std::vector<std::pair<int, double>> solution(const std::vector<int>& numbers) {
    
    // TODO: implement this function
 
    std::vector<std::pair<int, double>> pair;
    int j = numbers.size() - 1;
    
    for(int i = 0; i < numbers.size(); i++) {
        int first = numbers[i];
        int second = numbers[j];
        double geometrical = sqrt(first * second);
        geometrical = round(geometrical * 100)/100;
        pair.push_back({first, geometrical});
        j--;
    }

    return pair;
}

int main(){
    std::vector<int> numbers = {1, 2, 3, 4};
    solution(numbers);
    return 0;
}