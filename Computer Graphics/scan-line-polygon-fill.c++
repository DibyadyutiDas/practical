#include <graphics.h>
#include <stdio.h>

typedef struct {
    int x, y;
} Point;

void drawPolygon(Point poly[], int n) {
    for (int i = 0; i < n; i++) {
        line(poly[i].x, poly[i].y, poly[(i + 1) % n].x, poly[(i + 1) % n].y);
    }
}

void scanLineFill(Point poly[], int n) {
    int ymin = poly[0].y, ymax = poly[0].y;
    for (int i = 1; i < n; i++) {
        if (poly[i].y < ymin) ymin = poly[i].y;
        if (poly[i].y > ymax) ymax = poly[i].y;
    }

    for (int y = ymin; y <= ymax; y++) {
        int intersections[n], count = 0;

        for (int i = 0; i < n; i++) {
            Point p1 = poly[i], p2 = poly[(i + 1) % n];
            if (p1.y == p2.y) continue;

            if ((y >= p1.y && y < p2.y) || (y >= p2.y && y < p1.y)) {
                intersections[count++] = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
            }
        }

        for (int i = 0; i < count - 1; i += 2) {
            line(intersections[i], y, intersections[i + 1], y);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Point poly[] = {{100, 150}, {200, 50}, {300, 150}, {200, 250}};
    int n = 4;

    drawPolygon(poly, n);
    scanLineFill(poly, n);

    getch();
    closegraph();
    return 0;
}