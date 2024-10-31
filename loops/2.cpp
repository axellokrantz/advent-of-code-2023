#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Vector of fruits for the fruit salad
    vector<string> fruits = {"apple", "banana", "cherry", "kiwi", "mango"};
    // Count the number of fruits in the salad
    int fruit_count = 0;
    // Loop over each fruit in the fruits vector
    for (const string& fruit : fruits) {
        fruit_count++;
    }
    cout << fruit_count << endl;  // This should print the total number of fruits in the salad
    return 0;
}