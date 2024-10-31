#include <iostream>
#include <string>
using namespace std;

int main() {
    // Define a string named 'word' to represent the phrase we'll work with
    string word = "FRUIT Salad";
    string vowels = "aeiou";

    // TODO: Initialize a counter to hold the number of non-vowel characters
    int counter = 0;

    // TODO: Use a for-each loop to iterate over each character in the string
    // TODO: Inside the loop, write a condition to check if the character is not a vowel or a space
    // Don't forget to consider both lowercase and uppercase characters
    for(const auto& c : word){
        if(vowels.find(tolower(c)) == string::npos){
            counter++;
        }
    }

    // TODO: If the condition is true, increase the counter for non-vowel characters
    // TODO: Finally, print out the count of non-vowel characters
    std::cout << counter;
    return 0;
}