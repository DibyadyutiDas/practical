#include <graphics.h>
#include <stdio.h>

#define MAX_VERTICES 20

typedef struct {
    int x, y;
} Point;

void clipLeft(Point poly[], int *n, int xMin) {
    Point newPoly[MAX_VERTICES];
    int newCount = 0;
    for (int i = 0; i < *n; i++) {
        Point current = poly[i];
        Point next = poly[(i + 1) % *n];
        if (current.x >= xMin) {
            if (next.x >= xMin) {
                newPoly[newCount++] = next;
            } else {
                newPoly[newCount++] = (Point){xMin, current.y + (xMin - current.x) * (next.y - current.y) / (next.x - current.x)};
            }
        } else {
            if (next.x >= xMin) {
                newPoly[newCount++] = (Point){xMin, current.y + (xMin - current.x) * (next.y - current.y) / (next.x - current.x)};
                newPoly[newCount++] = next;
            }
        }
    }
    for (int i = 0; i < newCount; i++) poly[i] = newPoly[i];
    *n = newCount;
}

void sutherlandHodgmanClip(Point poly[], int *n, int xMin, int yMin, int xMax, int yMax) {
    clipLeft(poly, n, xMin);
    // Add similar functions for top, right, and bottom clipping
}

void drawPolygon(Point poly[], int n, int color) {
    setcolor(color);
    for (int i = 0; i < n; i++) {
        line(poly[i].x, poly[i].y, poly[(i + 1) % n].x, poly[(i + 1) % n].y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Point poly[] = {{50, 50}, {200, 50}, {200, 200}, {50, 200}};
    int n = 4;

    int xMin = 100, yMin = 100, xMax = 300, yMax = 300;
    rectangle(xMin, yMin, xMax, yMax);

    drawPolygon(poly, n, WHITE);

    sutherlandHodgmanClip(poly, &n, xMin, yMin, xMax, yMax);
    drawPolygon(poly, n, GREEN);

    getch();
    closegraph();
    return 0;
}