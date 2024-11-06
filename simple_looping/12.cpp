#include <cctype>
#include <string>
#include <iostream>

std::string encode_rle(const std::string& s) {
    
    char current_char;
    int count = 0;
    std::string encoded = "";
    // aaabbccd
    for (size_t i = 0; i < s.length(); i++)
    { 
        if(std::isalnum(s[i])){

            if(current_char != s[i] && count == 0){
                current_char = s[i];
                count++;
            }
            else if(current_char != s[i] && count > 0){
                encoded.push_back(current_char);
                encoded += std::to_string(count);
                current_char = s[i];
                count = 1;
            }
            else if(current_char == s[i]){
                count++;
            }
        }
        else{
            continue;
        }
    }
    if(count > 0){
        encoded.push_back(current_char);
        encoded += std::to_string(count);
    }
    
    return encoded;
}

int main(){
    std::cout << encode_rle("aaabbcccdde");
}