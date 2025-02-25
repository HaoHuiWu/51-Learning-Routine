#include <REGX52.H>

sbit OneWire_DQ=P3^7;

unsigned char OneWire_Init(void)
{	
	unsigned char i,AckBit;
	OneWire_DQ=1;
	OneWire_DQ=0;
	i = 227;while (--i);  //Delay500us
	OneWire_DQ=1;
	i = 29;while (--i);  //Delay70us
	AckBit=OneWire_DQ;
	i = 227;while (--i);  //Delay500us
	return AckBit;
	
}

void OneWire_SendBit(unsigned char Bit)
{	
	unsigned char i;
	OneWire_DQ=0;
	i = 2;while (--i); //Delay10us
	OneWire_DQ=Bit;
	i = 22;while (--i);//Delay50us
	OneWire_DQ=1;
	
}

unsigned OneWire_ReceiveBit(void)
{
	unsigned char i,Bit;
	OneWire_DQ=0;
	i = 1;while (--i); //Delay5us
	OneWire_DQ=1;
	i = 1;while (--i); //Delay5us
	Bit=OneWire_DQ;
	i = 22;while (--i);//Delay50us
	return Bit;
}	

void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&(0x01<<i));
	}
}

unsigned OneWire_ReceiveByte(void)
{
	unsigned char i,Byte=0x00;
	for(i=0;i<8;i++)
	{
		if(OneWire_ReceiveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}
	