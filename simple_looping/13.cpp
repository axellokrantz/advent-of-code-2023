#include <vector>
#include <utility>
#include <string>
#include <iostream>

std::vector<std::pair<char, int>> solution(const std::string& s) {

    int count = 0;
    char current_char;
    std::vector<std::pair<char, int>> result;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if(current_char != s[i] && count == 0){
            current_char = s[i];
            count++;
        }
        else if(current_char != s[i] && count > 0){
            result.push_back({current_char, count});
            current_char = s[i];
            count = 1;
        }
        else if(current_char == s[i]){
            count++;
        }
    }

    if(count > 0) {
        result.push_back({current_char, count});
    }
    
    for(const auto& pair : result){
        std::cout << "{" << pair.first << "," << pair.second << "}";
    }
    
    return result;
}

int main(){
    solution("$$$$$");
}