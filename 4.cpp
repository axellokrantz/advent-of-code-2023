#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    // Initialize an empty vector of strings named 'suitcase'
    std::vector<std::string> suitcase;
    // TODO: Add items to your suitcase
    suitcase.insert(suitcase.end(), {"mouse", "keyboard", "computer"});

    // Declare a string variable for your goodbye message
    std::string goodbye_message;
    // TODO: Assign a farewell message to the variable
    goodbye_message = "Bye!";
    // Access the first and last item in your suitcase
    std::string first_item = suitcase[0];
    std::string last_item = suitcase[suitcase.size() - 1];
    // TODO: Print the first item
    // TODO: Print the last item 
    std::cout << first_item << " " << last_item << "\n";
    transform(goodbye_message.begin(), goodbye_message.end(), goodbye_message.begin(), ::toupper);
    std::cout << goodbye_message;
    // Send off with a farewell in uppercase
    // TODO: Convert and print the farewell message in uppercase
    return 0;
}