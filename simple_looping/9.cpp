#include <vector>

std::vector<int> solution(const std::vector<int>& numbers) {
    
    int mid = numbers.size() / 2;
    int left_index = mid - 1;
    int right_index;
    std::vector<int> result;

    if(numbers.size() % 2 == 0){
        right_index = mid;
    }
    else{
        result.push_back(numbers[mid]);
        right_index = mid + 1;    
    }

    while(left_index >= 0 && right_index < numbers.size()){
        int temp = numbers[left_index] * numbers[right_index];
        result.push_back(temp);
        left_index--;
        right_index++;
    }

    return result;
}

int main(){
    solution({1,2,3,4,5});
}