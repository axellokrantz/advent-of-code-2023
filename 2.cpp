#include <iostream>
#include <vector>
using namespace std;

// Let's simulate packing a bag for travel with vectors and explore some operations!

int main() {
    // Packing our bag with initial items
    vector<string> bag = {"t-shirt", "shorts", "sandals"};

    // TODO: Add "sunglasses" to our bag at the end

    // We realized we need "hat" right after "t-shirt", let's insert it at index 1
    // TODO: Insert "hat" into the bag at the position right after "t-shirt"

    // Printing out our bag to see all items packed
    for (const string& item : bag) {
        cout << item << " ";
    }
    // Expected output with TODOs completed: t-shirt hat shorts sandals sunglasses
    return 0;
}