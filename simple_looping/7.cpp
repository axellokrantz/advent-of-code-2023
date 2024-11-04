#include <string>
#include <iostream>
#include <vector>

std::string repeat_char_jump(const std::string& input_string, int k) {
    
    std::vector visited(input_string.size(), false);
    int current_index = 0;
    std::string result = "";

    while(!visited[current_index]){
        result += input_string[current_index];
        visited[current_index] = true;
        current_index = (current_index + k) % input_string.length();
    }
    
    return result;
}

int main(){
    std::string input_string = "abcdefg";
    int k = 3; 
    std::cout << repeat_char_jump(input_string, k);  
}