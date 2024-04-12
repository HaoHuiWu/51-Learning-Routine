#include <REGX52.H>
#include "Delay.h"

unsigned char Key_KeyNum;

unsigned char Key(void)
{
	unsigned char Temp;
	Temp=Key_KeyNum;
	Key_KeyNum=0;
	return Temp;
}

unsigned char Key_GetState()
{
		unsigned int Keynumer=0;
		if(P3_1==0){Keynumer=1;}
		if(P3_0==0){Keynumer=2;}
		if(P3_2==0){Keynumer=3;}
		if(P3_3==0){Keynumer=4;}
		return Keynumer;
}
void Key_Loop(void)
{
	static unsigned char NowState,LastState;
	LastState=NowState;
	NowState=Key_GetState();
	if(LastState==1 && NowState==0)
	{
		Key_KeyNum=1;
	}
	if(LastState==2 && NowState==0)
	{
		Key_KeyNum=2;
	}
	if(LastState==3 && NowState==0)
	{
		Key_KeyNum=3;
	}
	if(LastState==4 && NowState==0)
	{
		Key_KeyNum=4;
	}
}