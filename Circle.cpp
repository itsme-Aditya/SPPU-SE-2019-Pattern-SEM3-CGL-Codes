#include<iostream>
#include<graphics.h>
using namespace std;

void circle() 
{
    int centx, centy, x, y, r, p;
    cout << "Enter center co-ordinates:";
    cin >> centx;
    cin >> centy;
    cout << "Enter radius of the circle:";
    cin >> r;
    x = 0;
    y = r;
    p = 3 - (2 * r);
    do {
        putpixel(centx + x, centy - y, RED);
        putpixel(centx - x, centy - y, BLUE);
        putpixel(centx + x, centy + y, GREEN);
        putpixel(centx - x, centy + y, YELLOW);
        putpixel(centx + y, centy + x, WHITE);
        putpixel(centx + y, centy - x, BLUE);
        putpixel(centx - y, centy + x, BLUE);
        putpixel(centx - y, centy - x, RED);
        if (p < 0) {
            p = p + (4 * x) + 6;
        }
        else {
            p = p + (4 * (x - y)) + 10;
            y = y - 1;
        }
        x = x + 1;
        delay(100);
    } while (x < y);
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    circle();
    delay(10000);
    closegraph();
    return 0;
}

