#include <iostream>
using namespace std;

// Array of temperatures throughout the day
int temperatures[] = {16, 14, 20, 22, 19, 13};

int main() {
    // TODO: Loop through the temperatures to suggest clothing
    for(int i = 0; i < 6; i++) {
        int temp = temperatures[i];
        if (temp < 15) {
            cout << "Wear warm clothes." << endl;
            // TODO: If it's cold outside, we stop checking the temperatures. Add the needed line to interrupt the loop.
            break;
        } else if (temp >= 20) {
            // TODO: Print a suggestion to wear light clothes.
            // TODO: Add a line here that will skip the final cout statement when it's warm enough for light clothes.
            std::cout << "Wear light clothes.\n";
            continue;
        }
        cout << "Consider a light jacket." << endl; // Suggestion for in-between temperatures
    }
    return 0;
}