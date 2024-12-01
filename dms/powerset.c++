#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printPowerSet(vector<int> &set) {
    int n = set.size();
    int powerSetSize = pow(2, n);
    for (int i = 0; i < powerSetSize; i++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) // Check if the j-th bit is set
                cout << set[j] << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> set = {1, 2, 3};
    cout << "Power set:" << endl;
    printPowerSet(set);
    return 0;
}