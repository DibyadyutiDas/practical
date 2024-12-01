#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Build the state transition table for the given pattern
vector<vector<int>> buildFSM(const string &pattern) {
    int M = pattern.length();
    vector<vector<int>> fsm(M + 1, vector<int>(256, 0)); // ASCII table size
    
    // Initialize the first row
    fsm[0][pattern[0]] = 1;

    // Shadow state for prefix matches
    int shadow = 0;

    for (int i = 1; i <= M; i++) {
        for (int ch = 0; ch < 256; ch++) {
            fsm[i][ch] = fsm[shadow][ch];
        }
        if (i < M) {
            fsm[i][pattern[i]] = i + 1;
            shadow = fsm[shadow][pattern[i]];
        }
    }
    return fsm;
}

// Perform the pattern matching using FSM
void searchPattern(const string &text, const string &pattern) {
    vector<vector<int>> fsm = buildFSM(pattern);
    int state = 0;

    for (int i = 0; i < text.length(); i++) {
        state = fsm[state][text[i]];
        if (state == pattern.length()) {
            cout << "Pattern found at index " << (i - pattern.length() + 1) << endl;
        }
    }
}

int main() {
    string text = "ababcabcababc";
    string pattern = "abc";
    searchPattern(text, pattern);
    return 0;
}