#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    circle(200, 200, 100);
    circle(170, 170, 15);
    circle(230, 170, 15);
    arc(200, 200, 45, 135, 50);
    delay(10000);
    

closegraph();
return(0);
}
