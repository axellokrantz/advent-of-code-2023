#include <vector>
#include <iostream>

std::vector<int> solution(const std::vector<int>& arrayA, const std::vector<int>& arrayB) {

    std::vector<int> result;
    std::vector<bool> visited(arrayA.size());
    int current_pos = 0;
    int next_pos;

    while(!visited[current_pos]){
        visited[current_pos] = true;
        next_pos = arrayA[current_pos];
        result.push_back(next_pos);
        //

        current_pos = arrayB[next_pos - 1] - 1;
    }
    return result;
}

int main() {
    solution({1, 3, 2, 5, 4}, {5, 4, 3, 2, 1});
}
