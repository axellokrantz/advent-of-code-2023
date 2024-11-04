#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void process_text(const string& text) {
    string new_text = "";
    for (char c : text) {
        if (isalpha(c)) {
            new_text += toupper(c);
        }
    }
    cout << "Processed Text: " << new_text << endl;
}

int main() {
    process_text("Happy Coding, Friends!");
    return 0;
}