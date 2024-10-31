#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Vector of fruits to include in a fruit salad
    vector<string> fruits = {"apple", "banana", "orange", "kiwi", "melon"};

    // Using a for loop to iterate over the vector of fruits
    // TODO: change to a while loop
    auto it = fruits.begin();
    while(it != fruits.end()){
        cout << "Adding " << *it << " to the salad.\n";
        ++it;
    }
    return 0;
}