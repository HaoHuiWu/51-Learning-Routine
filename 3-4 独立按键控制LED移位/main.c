#include <REGX52.H>
void Delay(unsigned int ms)		//@12.000MHz
{	
	while(ms--)
	{
		unsigned char i, j;
		i = 20;
		j = 113;
		do
		{
			while (--j);
		} while (--i);
	}
	
}

unsigned char LED;
void main()
{	
	
	P2=~0x01;
	while(1)
	{	
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LED++;
			if(LED>=8)
				LED=0;
			P2=~(0x01<<LED);
		}
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			if(LED==0)
				LED=7;
			else
			LED--;
			P2=~(0x01<<LED);
		}
	}
}