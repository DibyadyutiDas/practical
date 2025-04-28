#include <iostream>
using namespace std;

// Function to generate even parity
int generateParity(int data) {
    int count = 0, temp = data;
    while (temp) {
        if (temp & 1) count++;
        temp >>= 1;
    }
    return count % 2 == 0 ? 0 : 1;
}

// Function to check parity
bool checkParity(int data, int parityBit) {
    return generateParity(data) == parityBit;
}

int main() {
    int data;
    cout << "Enter data (integer): ";
    cin >> data;

    int parityBit = generateParity(data);
    cout << "Generated Even Parity Bit: " << parityBit << endl;

    int receivedData, receivedParity;
    cout << "Enter received data and parity bit: ";
    cin >> receivedData >> receivedParity;

    if (checkParity(receivedData, receivedParity))
        cout << "No error detected.\n";
    else
        cout << "Error detected!\n";

    return 0;
}
