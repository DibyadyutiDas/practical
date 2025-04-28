#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10

void goBackN() {
    int sent = 0;
    srand(time(0));

    while (sent < TOTAL_FRAMES) {
        cout << "Sending frames: ";
        for (int i = 0; i < WINDOW_SIZE && (sent + i) < TOTAL_FRAMES; i++) {
            cout << sent + i << " ";
        }
        cout << endl;

        int error = rand() % WINDOW_SIZE;
        cout << "Error occurred at frame " << sent + error << endl;

        sent += error;  // Go back to error frame
    }
}

int main() {
    goBackN();
    return 0;
}
