#include <iostream>
#include <string>
#include <algorithm>

std::string reversed_triple_chars(const std::string& s) {
    
    std::string result = "";
    for (size_t i = 0; i < s.size(); i+= 3)
    {
        if(s.size() - i < 3){
            result += s.substr(i);
            break;
        }
        std::string sub_string = s.substr(i, 3);
        std::reverse(sub_string.begin(), sub_string.end());
        result += sub_string;
    }
    
    return result;
}

int main(){
    std::cout << reversed_triple_chars("abcdefgh");
}