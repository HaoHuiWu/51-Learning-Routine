#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,cout;

void main()
{	
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{	
			if(KeyNum<=10)
			{	
				if(cout<4)
				{
					Password*=10;//左移
					Password+=KeyNum%10;//取一位
				}
				cout++;
			}
			LCD_ShowNum(2,1,Password,4);
		}
		if(KeyNum==11)//确认键
		{
			if(Password==1234)//如果密码为1234
			{
				LCD_ShowString(1,14,"OK ");//显示OK
				Password=0;
				cout=0;
			}
			else
			{
				LCD_ShowString(1,14,"ERR");//错误显示ERR
				Password=0;
				cout=0;
			}
		}
		if(KeyNum==12)
		{
			Password=0;
			cout=0;
			LCD_ShowNum(2,1,Password,4);
		}
	}
}
