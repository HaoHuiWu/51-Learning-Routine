#include <REGX52.H>
#include "LCD1602.h"
#include "DS18B20.h"
#include "Delay.h"
#include "AT24C02.h"
#include "Key.h"
#include "Timer0.h"

float T,Tshow;
unsigned char Thigh,Tlow;
unsigned char KeyNum;

void main ()
{	
	DS18B20_ConvertT();
	Delay(1000);
	Thigh=AT24C02_ReadByte(0);
	Tlow=AT24C02_ReadByte(1);	
	if(Thigh>125||Tlow<-55||Thigh<=Tlow)
	{
		Thigh=20;
		Tlow=15;
	}
	Timer0Init();
	LCD_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	LCD_ShowSignedNum(2,4,Thigh,3);
	LCD_ShowSignedNum(2,12,Tlow,3);
    while(1)
    {	
			KeyNum=Key();
      DS18B20_ConvertT();			//温度读取及显示
			T=DS18B20_ReadT();
			if(T<0){LCD_ShowChar(1,3,'-');Tshow=-T;}
			else{LCD_ShowChar(1,3,'+');Tshow=T;}
			LCD_ShowNum(1,4,Tshow,3);
			LCD_ShowChar(1,7,':');
			LCD_ShowNum(1,8,(unsigned int)(Tshow*100)%100,3);
			if(KeyNum)
			{
				if(KeyNum==1)
				{
					Thigh++;
					if(Thigh>125){Thigh=125;}
				}
				if(KeyNum==2)
				{
					Thigh--;
					if(Thigh<=Tlow){Thigh++;}
				}
				if(KeyNum==3)
				{
					Tlow++;
					if(Tlow>=Thigh){Tlow--;}
				}
				if(KeyNum==4)
				{
					Tlow--;
					if(Tlow<-55){Tlow=-55;}
				}

				LCD_ShowSignedNum(2,4,Thigh,3);
				LCD_ShowSignedNum(2,12,Tlow,3);

			}				
				if(T>Thigh){LCD_ShowString(1,13,"OV:H");}
				else if(T<Tlow){LCD_ShowString(1,13,"OV:L");}
				else{LCD_ShowString(1,13,"    ");}
				AT24C02_WriteByte(0,Thigh);
				Delay(5);
				AT24C02_WriteByte(1,Tlow);
				Delay(5);
    }
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=20)
	{
		T0Count=0;
		Key_Loop();
	}
}