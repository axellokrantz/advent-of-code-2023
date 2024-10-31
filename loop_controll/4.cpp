#include <iostream>
using namespace std;

int main() {
    // Array of temperatures with mixed weather conditions
    int temperatures[] = {16, 21, 20, 14, 22, 19, 13};
    int arraySize = sizeof(temperatures)/sizeof(temperatures[0]);

    for (int i = 0; i < arraySize; ++i) {
        int temp = temperatures[i];
        // TODO: Print "It's really hot." and exit the loop if temperature is above 30
        // TODO: Print "It's quite chilly." and skip to the next iteration if temperature is below 20
        if(temp > 30){
            std::cout << "It's really hot.";
            break;
        }
        else if(temp < 20){
            std::cout << "It's quite chilly";
            continue;
        }
        cout << "Lovely weather." << endl;
    }
    return 0;
}