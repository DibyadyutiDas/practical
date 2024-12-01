#include <iostream>
#include <string>
using namespace std;

// FSM to check for keywords
bool isKeyword(const string &input) {
    string keywords[] = {"char", "const", "continue"};
    for (const string &keyword : keywords) {
        if (input == keyword) {
            return true;
        }
    }
    return false;
}

void checkKeywords(const string &text) {
    string word = "";
    for (char ch : text) {
        if (isspace(ch)) {
            if (!word.empty() && isKeyword(word)) {
                cout << "'" << word << "' is a keyword." << endl;
            }
            word = "";
        } else {
            word += ch;
        }
    }
    if (!word.empty() && isKeyword(word)) {
        cout << "'" << word << "' is a keyword." << endl;
    }
}

int main() {
    string text = "int x = 10; char c = 'a'; const int y = 20; continue;";
    cout << "Input text: " << text << endl;
    cout << "Identified keywords:" << endl;
    checkKeywords(text);
    return 0;
}