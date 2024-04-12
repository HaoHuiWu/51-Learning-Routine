#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit Motor=P1^0;

unsigned char Cout,Compare;
unsigned char KeyNum,speed;

void main ()
{		
		Motor=0;
		Timer0Init();
    while(1)
    {
      KeyNum=Key();
			if(KeyNum==1)
			{
				speed++;
				speed%=4;
				if(speed==0){Compare=0;}
				if(speed==1){Compare=50;}
				if(speed==2){Compare=75;}
				if(speed==3){Compare=100;}
			}
			Nixie(1,speed);
    }
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	Cout++;
	Cout%=100;
	if(Cout>Compare){Motor=0;}
	else {Motor=1;}
	
}