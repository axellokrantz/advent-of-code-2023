#include <iostream>
#include <vector>
using namespace std;

int main() {
    // TODO: Define a vector of temperatures
    std::vector<int> temperatures = {1, 2, 3, 4, 5};
    // TODO: Determine the size of the vector
    int v_size = temperatures.size();
    // TODO: Write a loop to go through each temperature in the array
    for(int i = 0; i < v_size; i++){
        if(temperatures[i] > 30){
            std::cout << "It's really hot!\n";
            break;
        }
        else if(temperatures[i] < 15){
            std::cout << "It's really cold!\n";
            continue;
        }
        std::cout << "The temperature is nice!\n";
    }
        // TODO: Add an 'if' statement to check if the temperature is over 30
            // TODO: Print a message for being really hot and then exit the loop
        // TODO: Add an 'else if' condition before the general temperature message to check if the temperature is below 15
            // TODO: For temperatures that are too cold, print a specific message and skip to the next one
        // TODO: Print a message saying the temperature is nice for all other cases

    return 0;
}