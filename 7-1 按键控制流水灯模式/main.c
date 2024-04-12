#include <REGX52.H>
#include "Timer.h"
#include "Key.h"
#include "Delay.h"
#include <INTRINS.H>


unsigned char Keynum,LEDmode;

void main ()
{		P2=0xFE;
		Timer0Init();
    while(1)
    {
			Keynum=Key();
			if(Keynum)
			{	
				if(Keynum==1)
				{
					LEDmode++;
					if(LEDmode>=2)LEDmode=0;
				}
						
			}
					
    }
}

void Timer0_Routine()  interrupt 1
{	
	static unsigned int T0cout;
	TL0 = 0x18;		
	TH0 = 0xFC;
	T0cout++;
	if(T0cout>=500)
	{	
		T0cout=0;
		if(LEDmode==0)P2=_crol_(P2,1);
		if(LEDmode==1)P2=_cror_(P2,1);
	}
}