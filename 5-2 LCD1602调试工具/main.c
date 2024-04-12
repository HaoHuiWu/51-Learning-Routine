#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

int Result=0;

void main()
{
//	LCD_Init();
//	LCD_ShowChar(1,1,'A');
//	LCD_ShowString(1,2,"pwyissb");
//	LCD_ShowNum(1,9,123,3);
//	LCD_ShowSignedNum(1,13,-55,2);
//	LCD_ShowHexNum(2,1,0xFE,2);
//	LCD_ShowBinNum(2,3,0x12,2);
	
	LCD_Init();
	while(1)
	{
		Result++;
		Delay(1000);
		LCD_ShowNum(1,1,Result,3);
	}
}