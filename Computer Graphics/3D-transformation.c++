#include <graphics.h>
#include <math.h>
#include <stdio.h>

void drawCube() {
    line(100, 100, 200, 100);
    line(100, 100, 100, 200);
    line(200, 100, 200, 200);
    line(100, 200, 200, 200);

    line(100, 100, 150, 50);
    line(200, 100, 250, 50);
    line(150, 50, 250, 50);

    line(100, 200, 150, 150);
    line(200, 200, 250, 150);
    line(150, 150, 250, 150);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawCube();

    getch();
    closegraph();
    return 0;
}