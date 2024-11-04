#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string text = "C++ is fun!";
    int count = 0;

    for (char c : text) {
        if (islower(c)) {
            count++;
        }
    }

    cout << count << endl;  // Initially outputs: "c++ IS FUN!"
    return 0;
}