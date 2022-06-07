#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
union REGS in, out;
int color=15,drawMode=0;
#define PI 3.14159
int initMouse()
{
    in.x.ax = 0;
    int86(0X33, &in, &out);
    return out.x.ax;
}
void showMouse()
{
    in.x.ax = 1;
    int86(0X33, &in, &out);
}
void hideMouse()
{
    in.x.ax = 2;
    int86(0X33, &in, &out);
}
void getMousePosition(int* x, int* y,int* click)
{
    in.x.ax = 3;
    int86(0x33, &in, &out);
    *x = out.x.cx;
    *y = out.x.dx;
    *click = out.x.bx;
}
void drawColor(){
	setcolor(15);
	outtextxy(10,10,"Colors");
	outtextxy(64,10,"Free Hand");
	line(60,0,60,25);
	outtextxy(149,10,"Line");
	line(145,0,145,25);
	outtextxy(194,10,"Square/Rectangle");
	line(190,0,190,25);
	outtextxy(344,10,"Circle");
	line(340,0,340,25);
	//outtextxy(404,10,"Fill");
	line(400,0,400,25);
	//outtextxy(454,10,"Clear");
	//line(450,0,450,25);
	//line(500,0,500,25);
	line(0,25,getmaxx(),25);
	line(60,25,60,getmaxy());
	rectangle(getmaxx()-25,0,getmaxx(),25);
	setfillstyle(SOLID_FILL,RED);
	floodfill(getmaxx()-14,15,15);
	outtextxy(getmaxx()-15,10,"X");
	rectangle(0,0,getmaxx(),getmaxy());
	for(int i=0;i<16;i++){
		setfillstyle(SOLID_FILL,i);
		rectangle(0,25+i*25,60,50+i*25);
		floodfill(27,27+i*25,15);
	}
}
void clear(){
	delay(100);
	drawColor();
}
void changeShape(){
	int x1,y1,click;
	getMousePosition(&x1, &y1, &click);
	if(y1<25&&x1>10&&x1<145){
		drawMode=0;
	}else if(y1<25&&x1>145&&x1<190){
		drawMode=1;
	}else if(y1<25&&x1>190&&x1<340){
		drawMode=3;
	}else if(y1<25&&x1>340&&x1<400){
		drawMode=2;
	}else if(y1<25&&x1>400&&x1<450){
		drawMode=4;
	}else if(y1<25&&x1>450&&x1<500){
		clear();
	}
}
void freeHand(){
	int x1,y1,x2,y2,click;
	getMousePosition(&x1, &y1, &click);
	x2 = x1;
	y2 = y1;
	while (click == 1) {
	    hideMouse();
	    line(x1, y1, x2, y2);
	    showMouse();
	    x1 = x2;
	    y1 = y2;
	    getMousePosition(&x2, &y2, &click);
	}
}
void line(){
	int x1,y1,x2,y2,mx,my,click;
	getMousePosition(&x1, &y1, &click);
	x2 = mx = x1;
	y2 = my = y1;
	setwritemode(XOR_PUT);
	while (click == 1) {
	    hideMouse();
	    line(x1, y1, x2, y2);
	    getMousePosition(&mx, &my, &click);
	    line(x1,y1,mx,my);
	    showMouse();
	    x2 = mx;
	    y2 = my;

	}
	setwritemode(COPY_PUT);
}
void rectangle(){
	int x1,y1,x2,y2,mx,my,click;
	getMousePosition(&x1, &y1, &click);
	x2 = mx = x1;
	y2 = my = y1;
	setwritemode(XOR_PUT);
	while (click == 1) {
	    hideMouse();
	    rectangle(x1, y1, x2, y2);
	    getMousePosition(&mx, &my, &click);
	    rectangle(x1,y1,mx,my);
	    showMouse();
	    x2 = mx;
	    y2 = my;
	}
	setwritemode(COPY_PUT);
}
void circle(){
	int t,x1,y1,x2,y2,cx,cy,rx,ry,mx,my,click;
	getMousePosition(&x1, &y1, &click);
	x2 = mx = x1;
	y2 = my = y1;
	setwritemode(XOR_PUT);
	int i=0;
			while (click == 1) {
				hideMouse();
				setlinestyle(1,0,1);
				rectangle(x1, y1, mx, my);
				getMousePosition(&mx, &my, &click);

				if(mx<x1)
					x2=mx+((x1-mx)*2);
				else
					x2=mx;
				if(my<y1)
					y2=my+((y1-my)*2);
				else
					y2=my;
				rectangle(x1,y1,mx,my);
				showMouse();
				cx=abs((x1+mx)/2);
				cy=abs((y1+my)/2);
				rx=(x2-x1)/2;
				ry=(y2-y1)/2;
				i=1;
				}
		if(i){
		hideMouse();
		i=0;
			rectangle(x1,y1,mx,my);
			setlinestyle(0,0,1);
			ellipse(cx,cy,0,360,rx,ry);
		showMouse();
	}
	setwritemode(COPY_PUT);
}

void fill(int x,int y,int fillc,int bg){
	if(getpixel(x,y)!=bg||getpixel(x,y)==fillc){
		return;
	}
	delay(1);
	putpixel(x,y,fillc);
	fill(x+1,y,fillc,bg);
	fill(x,y+1,fillc,bg);
	fill(x-1,y,fillc,bg);
	fill(x,y-1,fillc,bg);
}
void getfill(){
	int x1,y1,click;
	getMousePosition(&x1, &y1, &click);
	while (click == 1) {
	    hideMouse();
	    getMousePosition(&x1, &y1, &click);
	    fill(x1,y1,color,getpixel(x1,y1));
	    showMouse();
	}
}
void start(){
	int status, i,x1,y1,click;
	initMouse();
	drawColor();
	setlinestyle(0,1,2);
	while (!kbhit()) {
		getMousePosition(&x1, &y1, &click);
		if(click==2&&y1<25&&x1>60&&x1<400){
			changeShape();
		}
		if(click==2&&x1<60&&y1>25){
			hideMouse();
			getMousePosition(&x1, &y1, &click);
			color=getpixel(x1,y1);
		}
		if(click==2&&x1>getmaxx()-25&&y1<25){
			exit(0);
		}
		setcolor(color);
		showMouse();
		switch(drawMode){
			case 0:
				freeHand();
				break;
			case 1:
				line();
				break;
			case 2:
				circle();
				break;
			case 3:
				rectangle();
				break;
			case 4:
				getfill();
				break;
			default:
				break;
		}
    }
    getch();
}
void main()
{
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    start();
    closegraph();
}