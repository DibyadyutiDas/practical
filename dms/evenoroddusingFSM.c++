#include <iostream>
using namespace std;

// FSM for Even/Odd detection
bool isEven(int n) {
    int state = 0; // Start in "Even" state
    while (n > 0) {
        int digit = n % 10; // Get the last digit
        if (state == 0) {
            state = (digit % 2 == 0) ? 0 : 1; // Transition based on digit
        } else {
            state = (digit % 2 == 0) ? 1 : 0;
        }
        n /= 10; // Move to the next digit
    }
    return state == 0;
}

int main() {
    int num = 1234;
    if (isEven(num)) {
        cout << num << " is even." << endl;
    } else {
        cout << num << " is odd." << endl;
    }
    return 0;
}