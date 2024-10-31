#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> temperatures = {25, 21, 17, 28, 35, 19, 22};
    int i = 0;
    int vectorLength = temperatures.size();
    while (i < vectorLength) {
        if (temperatures[i] > 20) {
            cout << "Temperature " << temperatures[i] << " is greater than 20." << endl;
        }
        cout << "Temperature " << temperatures[i] << " might require a jacket." << endl;
        i++;
    }
    return 0;
}