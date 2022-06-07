#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void ploatpixels(int cx,int cy,int x,int y){
	putpixel(x+cx,y+cy,15);
	putpixel(-x+cx,y+cy,15);
	putpixel(x+cx,-y+cy,15);
	putpixel(-x+cx,-y+cy,15);
	putpixel(y+cx,x+cy,15);
	putpixel(-y+cx,x+cy,15);
	putpixel(y+cx,-x+cy,15);
	putpixel(-y+cx,-x+cy,15);
}
void bresenham(int X,int Y,int r){
	cleardevice();
	int x=0,y=r,d;
	d=3-2*r;
	while(x<y){
		ploatpixels(X,Y,x,y);
		if(d<0){
			d=d+4*x+6;
			x++;
		}else{
			d=d+4*(x-y)+10;
			x++;
			y--;
		}
	}
}
void midpoint(int X,int Y,int r){
	cleardevice();
	int x=0,y=r,d;
	d=1-r;
	while(x<=y){
		ploatpixels(X,Y,x,y);
		if(d<0){
			d=d+2*x+3;
			x++;
		}else{
			d=d+2*(x-y)+5;
			y--;
			x++;
		}
	}
}
void main(){
	int gd=DETECT,gm;
	int x,y,r,c;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	printf("Please enter x y cordinates and radious of the circle.\n");
	scanf("%d%d%d",&x,&y,&r);
	printf("1.Press 1 for MidPoint circle drawing algorithm.\n");
	printf("2.Press 2 for Bresenham's circle drawing algorithm.\n");
	scanf("%d",&c);
	switch(c){
		case 1:
			midpoint(x,y,r);
			break;
		case 2:
			bresenham(x,y,r);
			break;
		default:
			printf("Please select a valid option and try again.");

	}
	getch();
	closegraph();
}