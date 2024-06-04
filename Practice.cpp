#include <iostream>
#include <graphics.h>

using namespace std;

/*
void move(int j, int h, int &x, int &y) {
    if (j == 1) {
        y = y - h;
    }
    else if (j == 2) {
        x = x + h;
    }
    else if (j == 3) {
        y = y + h;
    }
    else if (j == 4) {
        x = x - h;
    }
    setcolor(BROWN);
    lineto(x, y);
}
void hilbert(int d, int r, int u, int l, int i, int h, int &x, int &y) {
    if (i > 0) {
        i--;
        hilbert(r, d, l, u, i, h, x, y);
        move(d, h, x, y);
        hilbert(d, r, u, l, i, h, x, y);
        move(r, h, x, y);
        hilbert(d, r, u, l, i, h, x, y);
        move(u, h, x, y);
        hilbert(l, u, r, d, i, h, x, y);
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int d = 3, r = 2, u = 1, l = 4, i, h, x, y;
    cout << "Enter starting point of the curve: ";
    cin >> x >> y;
    cout << "Enter length of line segment: ";
    cin >> h;
    cout << "Enter order of the curve: ";
    cin >> i;
    moveto(x, y);
    hilbert(d, r, u, l, i, h, x, y);
    delay(10000);
    return 0;
}
*/

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8, xmax, ymax, xmin, ymin;

int getcode(int x, int y) {
    int code = 0;
    if (y > ymax) {
        code = code | TOP;
    }
    if (y < ymin) {
        code = code | BOTTOM;
    }
    if (x > xmax) {
        code = code | RIGHT;
    }
    if (x < xmin) {
        code = code | LEFT;
    }
    return code;
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    cout << "Enter top left and bottom right co-ordinates of the window:";
    cin >> xmin >> ymin >> xmax >> ymax;
    int x1, y1, x2, y2;
    cout << "Enter the co-ordinates of end points of the line:";
    cin >> x1 >> y1 >> x2 >> y2;
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);
    delay(10000);
    int code1 = getcode(x1, y1);
    int code2 = getcode(x2, y2);
    int accept = 0;
    while (1) {
        float m = (float)(y2 - y1) / (x2 - x1);
        if (code1 == 0 && code2 == 0) {
            accept = 1;
            break;
        }
        else if ((code1 & code2) != 0) {
            break;
        }
        else {
            int x = 0, y = 0, temp;
            if (code1 != 0) {
                temp = code1;
            }
            else {
                temp = code2;
            }
            if (temp & TOP) {
                x = x1 + (1.0 / m) * (ymax - y1);
                y = ymax;
            }
            else if (temp & BOTTOM) {
                x = x1 + (1.0 / m) * (ymin - y1);
                y = ymin;
            }
            else if (temp & LEFT) {
                x = xmin;
                y = y1 + m * (xmin - x1);
            }
            else if (temp & RIGHT) {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }
            if (temp == code1) {
                x1 = x;
                y1 = y;
                code1 = getcode(x1, y1);
            }
            else {
                x2 = x;
                y2 = y;
                code2 = getcode(x2, y2);
            }
        }
    }
    if (accept) {
        cleardevice();
        rectangle(xmin, ymin, xmax, ymax);
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
    else {
        cleardevice();
        setcolor(WHITE);
        rectangle(xmin, ymin, xmax, ymax);
    }
    cout << "Accept value: " << accept;
    delay(10000);
    closegraph();

    return 0;
}

