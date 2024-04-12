#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "IR.h"
#include "Timer0.h"

unsigned char Num;
unsigned int Time;

void main ()
{		
		LCD_Init();
		LCD_ShowString(1,1,"A");
		IR_Init();
    while(1)
    {
       
    }
}
