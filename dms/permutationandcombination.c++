#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n = 5, r = 3;
    cout << "Permutation P(" << n << ", " << r << ") = " << permutation(n, r) << endl;
    cout << "Combination C(" << n << ", " << r << ") = " << combination(n, r) << endl;
    return 0;
}