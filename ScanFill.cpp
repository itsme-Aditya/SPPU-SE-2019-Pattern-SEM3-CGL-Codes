#include <graphics.h>
#include <iostream>
using namespace std;

// Function to perform scan line filling for a triangle
void scanFillTriangle(int x[], int y[], int fill_color) {
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);

    int top = y[0], bottom = y[0];
    for (int i = 1; i < 3; i++) {
        if (y[i] < top) top = y[i];
        if (y[i] > bottom) bottom = y[i];
    }

    for (int scan_y = top + 1; scan_y < bottom; scan_y++) {
        int xl = getmaxx(), xr = 0;
        for (int i = 0; i < 3; i++) {
            int j = (i + 1) % 3;
            if ((scan_y >= y[i] && scan_y < y[j]) || (scan_y >= y[j] && scan_y < y[i])) {
                int x_intersect = x[i] + (scan_y - y[i]) * (x[j] - x[i]) / (y[j] - y[i]);
                if (x_intersect < xl) xl = x_intersect;
                if (x_intersect > xr) xr = x_intersect;
            }
        }
        for (int scan_x = xl + 1; scan_x < xr; scan_x++) {
            putpixel(scan_x, scan_y, fill_color);
        }
    }
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x[3], y[3];

    // Coordinates for a triangle
    x[0] = 100;
    y[0] = 100;
    x[1] = 200;
    y[1] = 300;
    x[2] = 300;
    y[2] = 150;

    int fill_color = YELLOW; // You can change this to any color

    scanFillTriangle(x, y, fill_color);

    delay(5000); // Display for 5 seconds
    closegraph();
    return 0;
}

