#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
void main(){
	int Gd=DETECT,Gm;
	initgraph(&Gd,&Gm,"C:\\TURBOC3\\BGI");
	/*
	for(int h=0;h<12;h++){
		for(int m=0;m<60;m++){
			for(int s=0;s<60;s++){
				circle(getmaxx()/2,getmaxy()/2,150);
				pieslice(getmaxx()/2,getmaxy()/2,89-(h*30),90-(h*30),50);
				pieslice(getmaxx()/2,getmaxy()/2,89-(m*6),90-(m*6),75);
				pieslice(getmaxx()/2,getmaxy()/2,89-(s*6),90-(s*6),100);
				delay(1000);
				clrscr();
			}
		}
	}
	*/
	time_t seconds;
	int num;
    while( !kbhit()){
    	struct tm *timeStruct;
		seconds = time(NULL);
		timeStruct = localtime(&seconds);
		int h=timeStruct->tm_hour;
		int m=timeStruct->tm_min;
		int s=timeStruct->tm_sec;
		if(h>=12){
		 h=h-12;
		}
		char msg[200];
		sprintf(msg, "Time is %d:%d:%d", h,m,s);
		outtextxy(10,10, msg);
		outtextxy(10,25,"Press any key to Exit.");
		circle(getmaxx()/2,getmaxy()/2,150);
		pieslice(getmaxx()/2,getmaxy()/2,91-(h*30),90-(h*30),50);
		pieslice(getmaxx()/2,getmaxy()/2,91-(m*6),90-(m*6),75);
		pieslice(getmaxx()/2,getmaxy()/2,91-(s*6),90-(s*6),100);
		setbkcolor(RED);
		//scanf("%d",&num);
		if(num==0){
			break;
		}
		delay(1000);
		
		cleardevice();
    	
	}
	//getch();

}
