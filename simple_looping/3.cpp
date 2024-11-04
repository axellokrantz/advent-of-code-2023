#include <vector>
#include <iostream>

std::vector<int> solution(const std::vector<int>& numbers) {
    
    std::vector<int> result;
    int j = numbers.size() - 1;
    int i = 0;

    while(i <= j){
        int first = numbers[i];
        int second = numbers[j];
        result.push_back(first + second);
        j--;
        i++;
    }
    
    return result;
}

int main(){
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    solution(numbers);
}