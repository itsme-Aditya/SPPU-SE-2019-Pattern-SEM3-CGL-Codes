#include<iostream>
#include<graphics.h>
using namespace std;

int line()
{
    
    int x1, y1, x2, y2, len;
    cout << "Enter value of x1 ";
    cin >> x1;
    cout << "Enter value of y1 ";
    cin >> y1;
    cout << "Enter value of x2 ";
    cin >> x2;
    cout << "Enter value of y2 ";
    cin >> y2;
    float dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;
    
    if (abs(dx) >= abs(dy)) {
        len = abs(dx);
    }
    else {
        len = abs(dy);
    }
    
    float xin, yin;
    xin = dx / len;
    yin = dy / len;
    
    float x, y;
    
    x = x1;
    y = y1;
    
    int i = 0;
    
    while (i <= len)
        {
        putpixel(x, y, GREEN);
            x = x + xin;
            y = y + yin;
        i ++;              
        }
    return(0);
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    line(); 
    line();
    line();
    delay(30000);
    closegraph();
    return 0;
}
// Triangle = (100,100), (50,200), (50,200), (150,200), (150,200), (100,100)
