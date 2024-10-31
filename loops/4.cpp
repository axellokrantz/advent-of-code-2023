#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // This code will create a simplified fruit salad with the provided fruits
    vector<string> fruits = {"apple", "banana", "cherry", "date"};
    string fruits_in_salad = "";

    size_t index = 0;
    // TODO: Create a while loop that assembles a string of fruit names separated by spaces, without adding a space after the last fruit
    // Hint: Consider using a conditional to determine when to add a space
    auto it = fruits.begin();
    while(it != fruits.end()) {
        fruits_in_salad += *it;
        if(it != fruits.end() - 1){ 
            fruits_in_salad += " "; 
        }
        ++it;
    }

    cout << fruits_in_salad;  // Output the fruits in the salad
    return 0;
}