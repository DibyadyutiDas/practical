#include <stdio.h>
#include <string.h>

int main() {
    char data[100], transmitted[110]; // Data and transmitted stream
    int i, count = 0, parityType;

    // Sender Side
    printf("Enter the data stream (binary format):\n");
    scanf("%s", data);

    printf("Enter 0 for Even Parity, 1 for Odd Parity:\n");
    scanf("%d", &parityType);

    strcpy(transmitted, data); // Copy data for transmission

    // Count number of 1s in the data stream
    for (i = 0; data[i] != '\0'; i++) {
      if (data[i] != '0' && data[i] != '1'){
        printf("Invalid binary input");
        return 0; // Invalid binary input
      }
      if (data[i] == '1')
        count++;
    }

    if (parityType != 0 && parityType != 1) {
        printf("Invalid Parity Selection! Please enter 0 or 1.\n");
        return 0; // Invalid Parity Type
    }
    // Append Parity Bit
    if (count % 2 == parityType) {
        strcat(transmitted, "0"); // Append 0
    } else {
        strcat(transmitted, "1"); // Append 1
    }

    printf("\nTransmitted Data (with parity bit): %s\n", transmitted);

    // Receiver Side
    count = 0;
    char received[110];

    printf("\nEnter the received data (including parity bit):\n");
    scanf("%s", received);

    // Count number of 1s in received data
    for (i = 0; received[i] != '\0'; i++) {
        if (received[i] == '1')
            count++;
    }

    // Parity Checking
    if (count % 2 == parityType) {
        printf("\nNo Error Detected. Data is intact.\n");
    } else {
        printf("\nError Detected in Transmission!\n");
    }

    received[strlen(received) - 1] = '\0';  // Remove parity bit
    printf("\nExtracted Original Data: %s\n", received);

    return 0;
}
