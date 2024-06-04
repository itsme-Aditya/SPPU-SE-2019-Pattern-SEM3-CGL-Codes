#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(23, 30, 150, 120);
    circle(100, 100, 50);
    rectangle(25, 30, 150, 210);
    arc(100, 100, 30, 70, 70);
    outtext("Computer Graphics");
    outtextxy(150, 150, "Computer Graphics");
    delay(10000);
    cout<<"Computer Graphics";
    

closegraph();
return(0);
}

