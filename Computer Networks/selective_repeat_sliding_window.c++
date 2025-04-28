#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10

void selectiveRepeat() {
    int ack[TOTAL_FRAMES] = {0};
    srand(time(0));

    while (true) {
        bool allAcked = true;
        cout << "Sending frames: ";
        for (int i = 0; i < TOTAL_FRAMES; i++) {
            if (ack[i] == 0) {
                cout << i << " ";
            }
        }
        cout << endl;

        for (int i = 0; i < TOTAL_FRAMES; i++) {
            if (ack[i] == 0) {
                int success = rand() % 2;
                if (success) {
                    cout << "ACK received for Frame " << i << endl;
                    ack[i] = 1;
                } else {
                    cout << "Frame " << i << " lost. Resending...\n";
                }
            }
        }

        for (int i = 0; i < TOTAL_FRAMES; i++) {
            if (ack[i] == 0) {
                allAcked = false;
                break;
            }
        }

        if (allAcked) break;
    }
    cout << "All frames sent successfully.\n";
}

int main() {
    selectiveRepeat();
    return 0;
}
