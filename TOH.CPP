#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int a[10],b[10],c[10];
void push(char inRod,int value){
	if(inRod=='A'){
		for(int i=0;i<10;i++){
			if(a[i]==0){
				a[i]=value;
				break;
			}
		}
	}else if(inRod=='B'){
		for(int i=0;i<10;i++){
			if(b[i]==0){
				b[i]=value;
				break;
			}
		}
	}else{
		for(int i=0;i<10;i++){
			if(c[i]==0){
				c[i]=value;
				break;
			}
		}
	}
}
int pop(char from){
	int temp=0;
	if(from=='A'){
		for(int i=0;i<10;i++){
			if(a[i]==0){
				temp=a[i-1];
				a[i-1]=0;
				break;
			}
		}
	}else if(from=='B'){
		for(int i=0;i<10;i++){
			if(b[i]==0){
				temp=b[i-1];
				b[i-1]=0;
				break;
			}
		}
	}else{
		for(int i=0;i<10;i++){
			if(c[i]==0){
				temp=c[i-1];
				c[i-1]=0;
				break;
			}
		}
	}
	return temp;
}
void drawa(int n){
	cleardevice();
	//base
	setcolor(15);
	for(int j=0; j<=300 ; j=j+150){
		line(100+j,getmaxy()-99,200+j,getmaxy()-99);
		setlinestyle(1,0,1);
		line(150+j,getmaxy()-100,150+j,getmaxy()-300);
		setlinestyle(0,0,1);
	}

	for(int i=0;i<10;i++){
		if(a[i]==0){
			break;
		}
		setcolor(a[i]);
		setfillstyle(SOLID_FILL,a[i]);
		rectangle(100+(n-a[i])*5,getmaxy()-100-i*20-i,200-(n-a[i])*5,getmaxy()-120-i*20-i);
		floodfill((((100+(n-a[i])*5)+(200-(n-a[i])*5))/2)+1,(((getmaxy()-100-i*20-i)+(getmaxy()-120-i*20-i))/2)+1,a[i]);
	}
	for(i=0;i<10;i++){
		if(b[i]==0){
			break;
		}
		setcolor(b[i]);
		setfillstyle(SOLID_FILL,b[i]);
		rectangle(250+(n-b[i])*5,getmaxy()-100-i*20-i,350-(n-b[i])*5,getmaxy()-120-i*20-i);
		floodfill((((250+(n-b[i])*5)+(350-(n-b[i])*5))/2)+1,(((getmaxy()-100-i*20-i)+(getmaxy()-120-i*20-i))/2)+1,b[i]);
	}

	for(i=0;i<10;i++){
		if(c[i]==0){
			break;
		}
		setcolor(c[i]);
		setfillstyle(SOLID_FILL,c[i]);
		rectangle(400+(n-c[i])*5,getmaxy()-100-i*20-i,500-(n-c[i])*5,getmaxy()-120-i*20-i);
		floodfill((((400+(n-c[i])*5)+(500-(n-c[i])*5))/2)+1,(((getmaxy()-100-i*20-i)+(getmaxy()-120-i*20-i))/2)+1,c[i]);
	}
	delay(1000);
}
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod,int s)
{
    if (n == 1)
    {
	printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
	push(to_rod,pop(from_rod));
	drawa(s);
	return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod,s);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    push(to_rod,pop(from_rod));
    drawa(s);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod,s);
}

void main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    int n = 4;
    printf("Please Enter Number of Disks\n");
    scanf("%d",&n);

    for(int i=n,j=0;i>0;i--,j++){
		a[j]=i;
	}
    drawa(n);
    towerOfHanoi(n, 'A', 'C', 'B',n);
    getch();
    closegraph();

}
