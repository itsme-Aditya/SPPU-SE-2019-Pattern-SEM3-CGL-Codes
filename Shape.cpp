#include<iostream>
#include <math.h>
#include<graphics.h>
using namespace std;

void ddaline(int x1, int y1, int x2, int y2) {
    float x, y; 
    float dx, dy;
    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    int len;
    if (abs(dx) > abs(dy)) {
        len = abs(dx);
    }
    else {
        len = abs(dy);
    }
    float xin, yin;
    xin = dx / len;
    yin = dy / len;
    int i = 0;
    while (i <= len) {
        putpixel(x, y, WHITE);
        x = x + xin;
        y = y + yin;
        i++;
    }
}
void circle(int centx, int centy, int r) {
    int x = 0, y = r;
    int p = 3 - (2 * r);
    do {
        putpixel(centx + x, centy + y, GREEN);
        putpixel(centx + x, centy - y, GREEN);
        putpixel(centx - x, centy + y, GREEN);
        putpixel(centx - x, centy - y, GREEN);
        putpixel(centx + y, centy + x, GREEN);
        putpixel(centx + y, centy - x, GREEN);
        putpixel(centx - y, centy + x, GREEN);
        putpixel(centx - y, centy - x, GREEN);
        if (p < 0) {
            p = p + (4 * x) + 6;
        }
        else {
            p = p + 4 * (x - y) + 10;
            y = y - 1;
        }
        x = x + 1;
    } while (x < y);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    float x1, y1, x2, y2, x3;
    int x, y, r;
    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter y1: ";
    cin >> y1;
    cout << "Enter x2: ";
    cin >> x2;
    x3 = (x1 + x2) / 2;
    y2 = y1 - sqrt(pow(x2 - x1, 2) + pow(x2 - x1 / 2, 2));
    ddaline(x1, y1, x2, y1);
    ddaline(x2, y1, x3, y2);
    ddaline(x3, y2, x1, y1);
    x = x3;
    y = y2 + 2 * (y1 - y2) / 3;
    r = (y1 - y2) / 3;
    circle(x, y, r);
    r = r * 2;
    circle(x, y, r);
    delay(10000);
    closegraph();
    return 0;
}

