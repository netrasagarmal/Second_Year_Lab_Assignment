#include<iostream>
#include<graphics.h>
using namespace std;
class DDA
{
		float X1,Y1,X2,Y2,DX,DY,X,Y,X_INC,Y_INC;int X0,Y0,STEPS;int gd=DETECT,gm;
	public:
	DDA()
	{
		X0=0;
		Y0=0;
	}
	void getCOORDINATES();     //GETS THE CO-ORDINATES OF LINES FROM THE USER
	void putCOORDINATES();		//PUTS THE CO-ORDINATES ENTERED BY THE USER
	void drawLINE(int x);				//DRAWS A LINE USING DDA LINE DRAWING ALGORITHM
};
void DDA::getCOORDINATES()
{
	X1=Y1=X2=Y2=DX=DY=0;
	cout<<"PLEASE ENTER THE CO-ORDINATES OF THE ENDPOINTS OF THE LINE TO BE DRAWN"<<endl;
	cout<<"END POINT 1:"<<endl<<"X = ";cin>>X1;		//TAKING ENDPOINTS OF STARTING VERTEX
	cout<<"Y = ";cin>>Y1;
	cout<<"END POINT 1:"<<endl<<"X = ";cin>>X2;		//TAKING ENDPOINTS OF ENDING VERTEX
	cout<<"Y = ";cin>>Y2;
}
void DDA::putCOORDINATES()
{
	cout<<"DRAWING A LINE FROM ("<<X1<<","<<Y1<<") TO ("<<X2<<","<<Y2<<")"<<endl;		//PUTING LINE ENDPOINTS
}
void DDA::drawLINE(int x)
{
	initgraph(&gd,&gm,NULL);							//INITALIZING GRAPH
	X0=getmaxx()/2;Y0=getmaxy()/2;					//FOR GETTING MIDPOINT OF THE SCREEN
	putpixel(X0,Y0,WHITE);								//PUTTING MIDPOINT
	DX=X2-X1;												
	DY=Y2-Y1;
	if(DX<0)
		DX=-DX;
	if(DY<0)
		DY=-DY;
	if(DX>=DY)												//TO DECIDE: COLUMN /ROW STEPING
		STEPS=DX;
	else
		STEPS=DY;
	DX=X2-X1;
	DY=Y2-Y1;
	X_INC=(float)DX/STEPS;								//X INCREMENTATION VALUE CORRESSPONDING TO THE SLOPE
	Y_INC=(float)DY/STEPS;								//Y INCREMENTATION VALUE CORRESSPONDING TO THE SLOPE
	X=X1;Y=Y1;		
	while(STEPS)											//LOOP EXECUTES "STEPS" TIMES
	{
		if(x==1)
		{
			if((int)X%2==0)
			putpixel(X0+X+0.5,Y0+Y+0.5,WHITE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		}
		if(x==2)
		{
			if((int)X%10!=0)
			putpixel(X0+X+0.5,Y0+Y+0.5,WHITE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		}
		if(x==3)
		{
			if((int)X%10!=0||(int)X%8==0||(int)X%6==0)
			putpixel(X0+X+0.5,Y0+Y+0.5,WHITE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		}
		if(x==4)
		{
			putpixel(X0+X+0.5,Y0+Y+0.5,WHITE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		}
		X+=X_INC;											//X INCREMENTATION
		Y+=Y_INC;											//Y INCREMENTATION
		STEPS--;
	}
	putpixel(X0,Y0,WHITE);
	delay(10000);											//DELAY FOR DISPLAY
	closegraph();											//CLOSING THE GRAPH
}
	
int main()													//MAIN FUNCTION
{
	cout<<"DDA LINE DRAWING ALGORITHM"<<endl;
	char c_ch;int i_ch;
	DDA LINE;
	do
	{												//CREATING OBJECT OF CLASS DDA WHER ALL DATA IS STORED
		LINE.getCOORDINATES();				
		LINE.putCOORDINATES();
		cout<<"STYLES:\n1:DOTTED\n2:DASHED\n3:DOTTED AND DASHED\n4:THICK\nCHOICE:";cin>>i_ch;
		switch(i_ch)
		{
			case 1:
				LINE.drawLINE(1);
			break;
			case 2:
				LINE.drawLINE(2);
			break;
			case 3:
				LINE.drawLINE(3);
			break;
			case 4:
				LINE.drawLINE(4);
			break;
			default:cout<<"PLEASE ENTER A VALID CHOICE"<<endl;
		}
		cout<<endl<<"LINE DRAWN SUCCESSFULLY"<<endl;
		cout<<"ENTER N TO EXIT:";cin>>c_ch;
	}while(c_ch!='N'&&c_ch!='n');
	return 0;
}