#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Key.h"
#include "AT24C02.h"

unsigned char KeyNum;
unsigned int Num;

void main ()
{
		LCD_Init();
		LCD_ShowString(1,1,"Hello");
//		AT24C02_WriteByte(1,123);
//		Delay(5);
//		Data=AT24C02_ReadByte(1);
//		LCD_ShowNum(2,1,Data,3);
    while(1)
    {
       KeyNum=Key();
			if(KeyNum==1)
			{
				Num++;
				LCD_ShowNum(1,1,Num,5);
			}
			if(KeyNum==2)
			{
				Num--;
				LCD_ShowNum(1,1,Num,5);
			}
			if(KeyNum==3)
			{
				AT24C02_WriteByte(0,Num%256);
				Delay(5);
				AT24C02_WriteByte(1,Num/256);
				Delay(5);
				LCD_ShowString(2,1,"Write OK");
				Delay(1000);
				LCD_ShowString(2,1,"        ");
			}
			if(KeyNum==4)
			{
				Num=AT24C02_ReadByte(0);
				Num|=AT24C02_ReadByte(1)<<8;
				LCD_ShowNum(1,1,Num,5);
				LCD_ShowString(2,1,"Read OK");
				Delay(1000);
				LCD_ShowString(2,1,"        ");
			}
    }
}

