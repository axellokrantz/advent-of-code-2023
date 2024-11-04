#include <iostream>
#include <cctype>
#include <string>

// TODO: Define a function to encrypt the text using a shift cipher
// The function should take two parameters: a string reference to the text and the integer shift value
void encrypt(std::string &text, int shift){
    for(auto &c : text){
        if(isalpha(c) && isupper(c)){
            c = 'A' + (c - 'A' + shift) % 26;
        }
        else if(isalpha(c) && islower(c)){
            c = 'a' + (c - 'a' + shift) % 26;
        }
    }
}

// TODO: Implement a loop that goes through each character in the string

    // TODO: If the character is alphabetic, shift it by the given value
    // Make sure to maintain the case (upper or lower) of the original letter

    // TODO: If the character is not alphabetic, add it as is to the encrypted string

// TODO: After defining the function, call it in the main function with a sample string and a shift value
int main(){
    std::string text = "Hello World!";
    encrypt(text, 3);
    std::cout << text;
}

