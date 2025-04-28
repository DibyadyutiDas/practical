#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void stopAndWait() {
    int frame = 0;
    char ack;
    srand(time(0));

    while (frame < 5) {  // Let's assume 5 frames to send
        cout << "Sending Frame " << frame << endl;
        int loss = rand() % 2; // Randomly simulate ACK lost or received

        if (loss) {
            cout << "ACK not received for Frame " << frame << ". Resending...\n";
        } else {
            cout << "ACK received for Frame " << frame << ".\n";
            frame++;
        }
    }
}

int main() {
    stopAndWait();
    return 0;
}
