#include <vector>
#include <utility>

std::vector<std::pair<int, int>> solution(const std::vector<int>& numbers) {
    
    int left_index;
    int right_index;

    std::vector<std::pair<int, int>> result;
    int mid = numbers.size() / 2;

   
    if(numbers.size() % 2 == 0){
        left_index = mid - 1;
        right_index = mid;
    }
    else{
        result.push_back({numbers[mid], 0});
        left_index = mid - 1;
        right_index = mid + 1;
    }

    while(left_index >= 0 && right_index < numbers.size()){
        result.push_back({numbers[left_index], numbers[right_index]});
        left_index--;
        right_index++;
    }
    // TODO: Implement the function to pair the elements from the middle to ends of the array
    return result;
}

int main(){
    solution({1,2,3,4,5});
}