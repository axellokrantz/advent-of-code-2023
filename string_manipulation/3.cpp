#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string encrypt_string(const string& text) {
    string encrypted;
    for (char c : text) {
        // TODO: Check if `c` is a letter and it is not the letter 'z' or 'Z'.
        // If it is a letter other than 'z' or 'Z', shift its value by 1 in the ASCII table.
        // If the letter is 'z', change it to 'a'. If it is 'Z', change it to 'A'.
        // If `c` is not a letter, append it unchanged to the encrypted string.
        if(isalpha(c) && c != 'z' && c != 'Z') {
            c += 1;
        }
        else if(c == 'z'){
            c = 'a';
        }
        else if (c == 'Z'){
            c = 'A';
        }
        encrypted += c;
    }
    return encrypted;
}

int main() {
    string encrypted_text = encrypt_string("Hello, C++!");
    cout << "The encrypted text is: " << encrypted_text << endl; // Should print out "Ifmmp, D++!"
    return 0;
}