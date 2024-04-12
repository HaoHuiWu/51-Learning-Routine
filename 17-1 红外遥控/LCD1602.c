#include <REGX52.H>

sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_E=P2^7;

#define LCD_DataPort		P0

void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DataPort=Command;
	LCD_E=1;
	Delay1ms();
	LCD_E=0;
	Delay1ms();
}

void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DataPort=Data;
	LCD_E=1;
	Delay1ms();
	LCD_E=0;
	Delay1ms();
}

void LCD_Init(void)
{
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01);
}

void LCD_AC(unsigned char Line,unsigned char Column)
{
	if(Line==1)
		{
			LCD_WriteCommand(0x80|(Column-1));
		}
		else
		{
			LCD_WriteCommand(0x80|(Column-1)+0x40);
		}
}
void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char)
{	
	LCD_AC(Line,Column);
	LCD_WriteData(Char);
}

void LCD_ShowString(unsigned char Line,unsigned char Column,unsigned char *String)
{	
	unsigned char i;
	LCD_AC(Line,Column);
	for(i=0;String[i]!='\0';i++)
	{	
		LCD_WriteData(String[i]);
	}
}

int LCD_Pow(int X,int Y)
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}

void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_AC(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData('0'+Number/LCD_Pow(10,i-1)%10);
	}
}

void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length)
{
	unsigned char i;
	unsigned int Num;
	LCD_AC(Line,Column);
	if(Number>=0)
	{
		LCD_WriteData('+');
		Num=Number;
	}
	if(Number<0)
	{
		LCD_WriteData('-');
		Num=-Number;
	}
	for(i=Length;i>0;i--)
	{
		LCD_WriteData('0'+Num/LCD_Pow(10,i-1)%10);
	}
}

void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	unsigned char Num;
	
	LCD_AC(Line,Column);
	for(i=Length;i>0;i--)
	{	
		Num=Number/LCD_Pow(16,i-1)%16;
		if(Num<10)
		{
			LCD_WriteData('0'+Num);
		}
		else
		{
			LCD_WriteData('A'+Num-10);
		}
	}
}

void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_AC(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData('0'+Number/LCD_Pow(2,i-1)%2);
	}
}