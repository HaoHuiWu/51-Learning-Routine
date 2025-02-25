#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer=P2^5;

#define SPEED  500

unsigned int FreqTable[]={
	0,
	63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,
};

unsigned char code Music_Star[]={
13,4,
13,4,
20,4,
20,4,
22,4,
22,4,
20,8,
18,4,
18,4,
17,4,
17,4,
15,4,
15,4,
13,8,
20,4,
20,4,
18,4,
18,4,
17,4,
17,4,
15,8,
20,4,
20,4,
18,4,
18,4,
17,4,
17,4,
15,8,
13,4,
13,4,
20,4,
20,4,
22,4,
22,4,
20,8,
18,4,
18,4,
17,4,
17,4,
15,4,
15,4,
13,8,
0xFF};
unsigned char FreqSelect,MusicSelect;

void main()
{
	Timer0Init();
	while(1)
	{	
		if(Music_Star[MusicSelect]!=0xFF)
		{
		FreqSelect=Music_Star[MusicSelect];//频率
		MusicSelect++;
		Delay(SPEED/4*Music_Star[MusicSelect]);//时间
		MusicSelect++;
		TR0=0;//停顿
		Delay(5);
		TR0=1;
		}
		else
		{	
			TR0=0;
			while(1);
		}
	}
		
}

void Timer0_Routine() interrupt 1
{	
	if(FreqTable[FreqSelect])
	{
	TL0 = FreqTable[FreqSelect]%256;		//设置定时初值
	TH0 = FreqTable[FreqSelect]/256;		//设置定时初值
	Buzzer=!Buzzer;
	}
	
}