#include <iostream>
using namespace std;

#define INF 999
#define V 4  // Number of vertices

void distanceVectorRouting(int costMatrix[V][V]) {
    int distance[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            distance[i][j] = costMatrix[i][j];

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }

    cout << "Final Distance Vector Table:\n";
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (distance[i][j] == INF)
                cout << "INF ";
            else
                cout << distance[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int costMatrix[V][V] = {
        {0, 2, INF, 1},
        {2, 0, 3, 2},
        {INF, 3, 0, 4},
        {1, 2, 4, 0}
    };

    distanceVectorRouting(costMatrix);
    return 0;
}
