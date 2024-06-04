#include <iostream>
#include <graphics.h>

using namespace std;

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
    setcolor(GREEN);
    lineto(x, y);
}
void hilbert(int d, int r, int u, int l, int i, int h, int &x, int &y) {
    if (i > 0) {
        i --;
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
    int x, y, n, h, d = 3, r = 2, u = 1, l = 4;
    cout << "Enter x and y co-ordinate of initial point:";
    cin >> x >> y;
    cout << "Enter length of line segment:";
    cin >> h;
    cout << "Enter order of the curve:";
    cin >> n;
    moveto(x, y);
    hilbert(d, r, u, l, n, h, x, y);
    delay(10000);
    closegraph();
    return 0;
}
    
