/*Write a C++ Program to draw a given pattern. Use 
DDA line and Bresenham’s circle drawing 
algorithm. Apply the concept of encapsulation */

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
using namespace std;

typedef struct coordinate
{
	int x,y;
	char code[4];
}PT;

void drawwindow();
void drawline(PT p1,PT p2,int cl);
PT setcode(PT p);
int visibility(PT p1,PT p2);
PT resetendpt(PT p1,PT p2);

int main()
{
	int v;
	int gd,gm;gd=DETECT;
	PT p1,p2,ptemp;
	cout<<"\n---The size of Clipping Window---";
	cout<<"\n\nLeft-Top:150,150 \nRight-Bottom:350,350";
	cout<<"\n------------------------------------";
	cout<<"\nEnetr the endpoint 1 of line to be clipped";
	cout<<"\nEnter the x coordinate::";
	cin>>p1.x;
	cout<<"\nEnter the y coordinates::";
	cin>>p1.y;
	cout<<"\nEnetr the endpoint 2 of line to be clipped";
	cout<<"\nEnter the x coordinate::";
	cin>>p2.x;
	cout<<"\nEnter the y coordinates::";
	cin>>p2.y;
	
	initgraph(&gd,&gm,NULL);
	cleardevice();
	drawwindow();
	getch();
	drawline(p1,p2,15);
	getch();
	p1=setcode(p1);
	p2=setcode(p2);
	v=visibility(p1,p2);
	switch(v)
	{
		case 0:
			cleardevice();
			drawwindow();
			drawline(p1,p2,15);
			break;

		case 1:
			cleardevice();
			drawwindow();
			break;

		case 2:
			cleardevice();
			p1=resetendpt(p1,p2);
			p2=resetendpt(p2,p1);
			drawwindow();
			drawline(p1,p2,15);
			break;
	}
	getch();
	closegraph();
	return(0);
}

/*Function to draw window*/
void drawwindow()
{
	setcolor(RED);
	line(150,150,350,150);
	line(350,150,350,350);
	line(150,350,350,350);
	line(150,150,150,350);
}

/*Function to draw line between two points*/
void drawline(PT p1,PT p2,int cl)
{
	setcolor(cl);
	line(p1.x,p1.y,p2.x,p2.y);
}

/*function to set code of the coordinates */
PT setcode(PT p)
{
	PT ptemp;
	if(p.y<150)
	ptemp.code[0]='1';//top
	else
	ptemp.code[0]='0';
	if(p.y>350)
	ptemp.code[1]='1';//bottom;
	else
	ptemp.code[1]='0';
	if(p.x>350)
	ptemp.code[2]='1';//right;
	else
	ptemp.code[2]='0';
	if(p.x<150)
	ptemp.code[3]='1';//right;
	else
	ptemp.code[3]='0';
	ptemp.x=p.x;
	ptemp.y=p.y;
	return(ptemp);
}

/*Function to determine visibility of line*/
int visibility(PT p1,PT p2)
{
	int i,flag=0;
	for(i=0;i<4;i++)
	{
		if((p1.code[i]!='0')||(p2.code[i]!='0'))
		flag=1;
	}
	if(flag==0)
	return(0);
	for(i=0;i<4;i++)
	{
		if((p1.code[i]==p2.code[i])&&(p1.code[i]=='1'))
		flag=0;
	}
	if(flag==0)
	return(1);
	return(2);
}

/*Function to find new endpoints*/
PT resetendpt(PT p1,PT p2)
{
	PT temp;
	int x,y,i;
	float m,k;
	if(p1.code[3]=='1')
	x=150;
	if(p1.code[2]=='1')
	x=350;
	if((p1.code[3]=='1')||(p1.code[2]=='1'))
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(p1.y+(m*(x-p1.x)));
		temp.y=k;
		temp.x=x;
		for(i=0;i<4;i++)

		temp.code[i]=p1.code[i];
		if(temp.y<=350&&temp.y>=150)
		return(temp);
	}
	if(p1.code[0]=='1')
	y=150;
	if(p1.code[1]=='1')
	y=350;
	if((p1.code[0]=='1')||(p1.code[1]=='1'))
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(float)p1.x+(float)(y-p1.y)/m;
		temp.x=k;
		temp.y=y;
		for(i=0;i<4;i++)
		temp.code[i]=p1.code[i];
		return(temp);
	}
	else
	return(p1);
}
