#include <iostream>
using namespace std;

int generateChecksum(int data[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
        if (sum > 255) // Assuming 8-bit sum
            sum = (sum & 255) + 1;
    }
    return (~sum) & 255; // One's complement
}

bool verifyChecksum(int data[], int n, int checksum) {
    int sum = checksum;
    for (int i = 0; i < n; i++) {
        sum += data[i];
        if (sum > 255)
            sum = (sum & 255) + 1;
    }
    return sum == 255;
}

int main() {
    int n;
    cout << "Enter number of data bytes: ";
    cin >> n;
    int data[n];
    cout << "Enter data bytes:\n";
    for (int i = 0; i < n; i++) cin >> data[i];

    int checksum = generateChecksum(data, n);
    cout << "Generated checksum: " << checksum << endl;

    cout << "\nVerifying checksum...\n";
    if (verifyChecksum(data, n, checksum))
        cout << "No error detected.\n";
    else
        cout << "Error detected!\n";

    return 0;
}
