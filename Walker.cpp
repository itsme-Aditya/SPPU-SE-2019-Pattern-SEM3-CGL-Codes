#include <graphics.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void man(int cx, int cy)
{
    //man
    line(cx,cy,cx,cy-50);//torsoe
    circle(cx,cy-70,20);//head
    line(cx,cy-50,cx+20,cy-20);//hand 1.1
    line(cx+20,cy-20,cx+40,cy-50);//hand 1.2
    line(cx,cy-50,cx-20,cy-20);//hand 2.1
    line(cx-20,cy-20,cx-20,cy);//hand 2.2
    //umbrella
    line(cx+40,cy-50,cx+40,cy-100);//handle
    line(cx,cy-100,cx+80,cy-100);
    arc(cx+40,cy-100,0,180,40);
    
}

void rain(int cx, int cy)
{
    for (int i=0;i<500;i++)//50drops
    {
        int rhx=getmaxx();
        int rhy=getmaxy();
        int x=rand()%rhx;
        int y=rand()%rhy;
        bool flag=true;
        if (cx<x && x<cx+80)
        {
            if(cy-100<y && y<cy+30)
            {
                flag=false;
            }
            //line(x,y,x+2,y);
        }
        if (flag)
        {
            setcolor(LIGHTBLUE);
            line(x,y-5,x,y);
            setcolor(WHITE);
        }
        
    }

}

void walker(int cx, int cy)
{
    for (int i=0; i<20;i++)
    {
        cx=cx+20;
        man(cx,cy);
        line(0,cy+30,600,cy+30);//ground
        if (i%2==1)//legs frame 1
        {
            line(cx,cy,cx+20,cy+30);
            line(cx,cy,cx-20,cy+30);
        }
        else //legs frame 2
        {
            line(cx,cy,cx-5,cy+30);
            line(cx,cy,cx+5,cy+30);
        }
        
        rain(cx,cy);
        delay(500);
        cleardevice();
    }
    
}

int main()
{
int gd=DETECT, gm;
initgraph(&gd,&gm,NULL);
walker(50,300);
closegraph();
return 0;
}