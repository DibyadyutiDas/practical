#include <iostream>
using namespace std;

const int ROWS = 2;
const int COLS = 2;

void generate2DParity(int data[ROWS][COLS], int rowParity[ROWS], int colParity[COLS]) {
    for (int i = 0; i < ROWS; i++) {
        rowParity[i] = 0;
        for (int j = 0; j < COLS; j++) {
            rowParity[i] ^= data[i][j];
        }
    }

    for (int j = 0; j < COLS; j++) {
        colParity[j] = 0;
        for (int i = 0; i < ROWS; i++) {
            colParity[j] ^= data[i][j];
        }
    }
}

void check2DParity(int data[ROWS][COLS], int rowParity[ROWS], int colParity[COLS]) {
    bool error = false;
    for (int i = 0; i < ROWS; i++) {
        int parity = 0;
        for (int j = 0; j < COLS; j++) {
            parity ^= data[i][j];
        }
        if (parity != rowParity[i]) {
            cout << "Row " << i << " error detected.\n";
            error = true;
        }
    }

    for (int j = 0; j < COLS; j++) {
        int parity = 0;
        for (int i = 0; i < ROWS; i++) {
            parity ^= data[i][j];
        }
        if (parity != colParity[j]) {
            cout << "Column " << j << " error detected.\n";
            error = true;
        }
    }

    if (!error)
        cout << "No errors detected.\n";
}

int main() {
    int data[ROWS][COLS];
    cout << "Enter 2x2 data matrix (0s and 1s):\n";
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cin >> data[i][j];

    int rowParity[ROWS], colParity[COLS];
    generate2DParity(data, rowParity, colParity);

    cout << "Generated Row Parity: ";
    for (int i = 0; i < ROWS; i++) cout << rowParity[i] << " ";
    cout << "\nGenerated Column Parity: ";
    for (int j = 0; j < COLS; j++) cout << colParity[j] << " ";
    cout << endl;

    cout << "\nChecking for errors...\n";
    check2DParity(data, rowParity, colParity);

    return 0;
}

