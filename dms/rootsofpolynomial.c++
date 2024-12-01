#include <iostream>
#include <cmath>
using namespace std;

void findRoots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and distinct: " << root1 << " and " << root2 << endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "Roots are real and equal: " << root << endl;
    } else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex: " << realPart << " + " << imagPart << "i and " << realPart << " - " << imagPart << "i" << endl;
    }
}

int main() {
    double a = 1, b = -3, c = 2;
    findRoots(a, b, c);
    return 0;
}