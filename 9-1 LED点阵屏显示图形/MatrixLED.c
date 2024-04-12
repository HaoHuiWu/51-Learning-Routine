#include <REGX52.H>
#include "Delay.h"
sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;
/**
  * @brief  点阵屏初始化
  * @param 	无
  * @retval 无
  */
void MatrixLED_Init()
{
	SCK=0;
	RCK=0;
}

#define MatrixLED_Port	P0//定义P0
/**
  * @brief  74HC595写入一个字节
  * @param 	要写入的字节
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned int i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);
		SCK=1;//每来一个上升沿把SER的数据移入寄存器
		SCK=0;
	}
	RCK=1;//每来一个上升沿将八位数据锁存
	RCK=0;
}
/**
  * @brief  LED点阵屏显示一列数据
  * @param 	Cloumn要选择的列，范围0~7
	* @param 	Data选择列显示的数据，高位在上，1为亮，0为灭
  * @retval 无
  */

void MatrixLED_ShowClolum(unsigned char Column,Date)
{
	_74HC595_WriteByte(Date);//每一列要显示的数据
	MatrixLED_Port=~(0x80>>Column);//依次右移选择每一列
	Delay(1);
	MatrixLED_Port=0xFF;//防止残影，需要清0
}


