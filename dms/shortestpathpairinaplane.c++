#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

double euclideanDistance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

pair<pair<double, double>, pair<double, double>> findShortestPath(vector<pair<double, double>> points) {
    double minDistance = numeric_limits<double>::max();
    pair<pair<double, double>, pair<double, double>> closestPair;
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = i + 1; j < points.size(); j++) {
            double dist = euclideanDistance(points[i], points[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestPair = {points[i], points[j]};
            }
        }
    }
    return closestPair;
}

int main() {
    vector<pair<double, double>> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    auto result = findShortestPath(points);
    cout << "Shortest path is between points (" << result.first.first << ", " << result.first.second
         << ") and (" << result.second.first << ", " << result.second.second << ")" << endl;
    return 0;
}