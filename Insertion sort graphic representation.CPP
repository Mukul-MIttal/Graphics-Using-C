#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void draw(int a[],int n){
	cleardevice();
	char m[30];
	int y =getmaxy();
	for(int i=0;i<n;i++){
		setfillstyle(SOLID_FILL,a[i]);
		rectangle(10+i*30,y-40,40+i*30,y-(40+10*a[i]+10*a[i]));
		floodfill(15+i*30,y-(45+10*a[i]),15);
		sprintf(m,"%d",a[i]);
		outtextxy(23+i*30,495-45,m);
	}
}
void iSort(int arr[],int n){
	int i,key,j;
	draw(arr,n);
	for(i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
		//if(kbhit()){
		//delay(1000);
			arr[j+1]=arr[j];
			j=j-1;
			arr[j+1]=key;
			draw(arr,n);
			delay(1000);
			}
		//}
	}
}
void main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int a[15]={9,1,8,2,7,3,6,4,5,10,14,12,11,13,0};
	iSort(a,15);
	getch();
	closegraph();
}