#include <graphics.h>
#include <math.h>
#include <stdio.h>

void drawRectangle(int x[], int y[]) {
    for (int i = 0; i < 4; i++) {
        line(x[i], y[i], x[(i + 1) % 4], y[(i + 1) % 4]);
    }
}

void translate2D(int x[], int y[], int tx, int ty) {
    for (int i = 0; i < 4; i++) {
        x[i] += tx;
        y[i] += ty;
    }
}

void rotate2D(int x[], int y[], int angle) {
    float rad = angle * M_PI / 180.0;
    for (int i = 0; i < 4; i++) {
        int newX = x[i] * cos(rad) - y[i] * sin(rad);
        int newY = x[i] * sin(rad) + y[i] * cos(rad);
        x[i] = newX;
        y[i] = newY;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x[] = {100, 200, 200, 100};
    int y[] = {100, 100, 200, 200};

    drawRectangle(x, y);
    translate2D(x, y, 50, 50);
    drawRectangle(x, y);

    rotate2D(x, y, 45);
    drawRectangle(x, y);

    getch();
    closegraph();
    return 0;
}