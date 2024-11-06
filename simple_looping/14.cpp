#include <string>
#include <iostream>

std::string solution(const std::string &s) {

    int j = 1;
    int count = 0;
    std::string pair = "";
    std::string result = "";

    for (size_t i = 0; i < s.size(); i += 2)
    {
        if(s[i] != pair[0] && s[j] != pair[1] && count == 0){
            pair += s[i];
            pair += s[j];    
            count++;
        }
        else if (s[i] != pair[0] && s[j] != pair[1] && count > 0){
            result += pair;
            result += std::to_string(count);
            pair = "";
            pair += s[i];
            pair += s[j];
            count = 1;
        }
        else if(s[i] == pair[0] && s[j] == pair[1]){
            count++;
        }
        j += 2;
    }
    if(count > 0){
        result += s[s.size() -1];
        result += std::to_string(count);
    }
    
    std::cout << result;
    return result;
}

int main(){
    solution("aaabbabbababaca");
    // aa, ab, ba, bb, ab, ab, ac, a
    // aa1 ab1 ba1 bb1 ab2 ac1 a1 
}