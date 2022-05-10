#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<time.h>
int Array[4][4]={{0,14,13,12},{11,10,9,8},{7,6,5,4},{3,2,1,15}};
int final[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
int position[2]={0,0};
void swap(int *a,int *b){
     int temp=*b;
     *b=*a;
     *a=temp;
}
void getPosition(){
    int find=0;
    for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	     if(Array[i][j]==0){
		position[0]=i;
		position[1]=j;
		find=1;
		break;
	     }
	}
    if(find){
	break;
    }
    }
}
void shuffle(){
	srand(time(0));
	int k,s;
    for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	      k =(rand()/4)%4;
	      s=(rand()/4)%4;
	      swap(&Array[k][s],&Array[s][k]);
	}
    }
    getPosition();
}
int Draw(){
	int x=1;
	cleardevice();
	outtextxy(100,40,"Arrang the numbers in assending order.");
	outtextxy(100,60,"Press Esc to Exit any time.");
	outtextxy(100,80,"Press R key to Restart the game.");
	for(int k=0;k<=4;k++){
	     line(100,100+k*50,300,100+k*50);
	     line(100+k*50,100,100+k*50,300);
	}
	char a[9];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
		if(Array[i][j]!=final[i][j]){
			x=0;
			setfillstyle(SOLID_FILL,RED);

		}else{
			setfillstyle(SOLID_FILL,GREEN);
		}

		if(Array[i][j]!=0){
			floodfill(120+j*50,120+i*50,15);
			sprintf(a,"%d",Array[i][j]);
			outtextxy(120+j*50,120+i*50,a);
			}

		}
	}
	return x;
}
void Move(int Dir){
     if(Dir==0){
	if(position[0]>0){
		swap(&Array[position[0]][position[1]],&Array[position[0]-1][position[1]]);
		position[0]--;
	}
     }else if(Dir==1){
	if(position[0]<3){
		 swap(&Array[position[0]][position[1]],&Array[position[0]+1][position[1]]);
		 position[0]++;
	}

     }else if(Dir==2){
	if(position[1]>0){
		swap(&Array[position[0]][position[1]],&Array[position[0]][position[1]-1]);
		position[1]--;
	}
     }else if(Dir==3){
	if(position[1]<3){
		swap(&Array[position[0]][position[1]],&Array[position[0]][position[1]+1]);
		position[1]++;
	}
     }
     Draw();
}
void main(){
	int gd=DETECT,GM;
	char ch;
	initgraph(&gd,&GM,"C:\\TURBOC3\\BGI");
	shuffle();
	Draw();
	while(1){
	       if(kbhit()){
			ch=getch();
			//printf("%d",int(ch));
			if(int(ch)==27){//To Exit on press of Esc Key.
				break;
			}else if(int(ch)==119||int(ch)==87||int(ch)==72){//To move up on press of W or UP arrow key.
			       Move(0);
			}else if(int(ch)==83||int(ch)==115||int(ch)==80){//To move Down on press of S or Down arrow key.
			       Move(1);
			}else if(int(ch)==65||int(ch)==97||int(ch)==75){//To move Left on Press of A or Left arrow key.
			       Move(2);
			}else if(int(ch)==68||int(ch)==100||int(ch)==77){//To move Right on Press of D or Right arrow key.
			       Move(3);
			}else if(int(ch)==114||int(ch)==82){
			       shuffle();
			}
			if(Draw()){
				outtextxy(100,310,"GAME OVER YOU WIN!");
				break;
			}


	       }
	}
	getch();
	closegraph();
}
