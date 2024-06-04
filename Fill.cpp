#include <iostream>
#include <graphics.h>
using namespace std;

void ffill(int x, int y, int oldcolor, int newcolor) {
    int current = getpixel(x, y);
    if (current == oldcolor) {
        putpixel(x, y, newcolor);
        ffill(x + 1, y, oldcolor, newcolor);
        ffill(x - 1, y, oldcolor, newcolor);
        ffill(x, y + 1, oldcolor, newcolor);
        ffill(x, y - 1, oldcolor, newcolor);
     }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x1, y1, x2, y2, x3, y3, xavg, yavg;
    cout << "Enter end points of triangle:";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    xavg = (int)(x1 + x2 + x3) / 3;
    yavg = (int)(y1 + y2 + y3) / 3;
    ffill(xavg, yavg, BLACK, RED);
    delay(10000);
    closegraph();
    return 0;
}

