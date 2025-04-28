#include <iostream>
#include <vector>
using namespace std;

int calculateParity(vector<int> &data, int parityPos) {
    int count = 0;
    for (int i = parityPos; i <= data.size(); i += 2 * parityPos) {
        for (int j = i; j < i + parityPos && j <= data.size(); j++) {
            if (data[j] == 1) count++;
        }
    }
    return count % 2;
}

int main() {
    int m;
    cout << "Enter number of data bits: ";
    cin >> m;
    vector<int> data(m + 10, 0); // Extra space for parity bits
    cout << "Enter data bits:\n";

    int j = 1;
    for (int i = 1; j <= m; i++) {
        if ((i & (i - 1)) != 0) { // Not a power of two
            cin >> data[i];
            j++;
        }
    }

    for (int i = 1; i <= m + 10; i <<= 1) {
        data[i] = calculateParity(data, i);
    }

    cout << "Hamming code is:\n";
    for (int i = 1; i <= m + 10; i++) {
        if (data[i] != -1)
            cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}
