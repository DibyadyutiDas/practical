#include <iostream>
#include <cmath>
using namespace std;

double euclideanDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1 = 1.0, y1 = 2.0, x2 = 4.0, y2 = 6.0;
    cout << "Euclidean Distance: " << euclideanDistance(x1, y1, x2, y2) << endl;
    return 0;
}