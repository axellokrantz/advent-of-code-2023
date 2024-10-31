#include<iostream>
#include<vector>
using namespace std;

int main() {
    // Vector of fruits to be used in fruit salad
    vector<string> fruits = {"apple", "banana", "kiwi", "mango"};

    // TODO: Loop over the vector of fruits and add them to the fruit salad with a print statement
    for (const string& fruit : fruits) {
        // TODO: Print a statement for adding each fruit to the fruit salad.
        std::cout << "Adding " << fruit << " to the salad.\n";
    }
    return 0;
}