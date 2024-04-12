#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"
#include "Delay.h"

sbit DA=P2^1;

unsigned char Cout,Compare,i;

void main ()
{		
		DA=0;
		Timer0Init();
    while(1)
    {
			for(i=0;i<100;i++)
			{
				Compare=i;
				Delay(10);
			}
			for(i=100;i>0;i--)
			{
				Compare=i;
				Delay(10);
			}
    }
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	Cout++;
	Cout%=100;
	if(Cout>Compare){DA=0;}
	else {DA=1;}
	
}