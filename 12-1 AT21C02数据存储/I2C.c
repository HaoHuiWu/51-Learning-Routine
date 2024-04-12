#include <REGX52.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

void I2C_Start(void)//开始
{
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;
	
}

void I2C_Stop(void)//停止
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
	
}
/**
  * @brief  发送字节
  * @param 	Byte要发送的字节
  * @retval 无
  */
void I2C_SendByte(unsigned char Byte)
{	
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;
	}
}
/**
  * @brief  接受字节
  * @param 	无
  * @retval 接受到的字节
  */
unsigned char I2C_ReceiveByte(void)
{
	unsigned char i,Byte=0x00;
	I2C_SDA=1;
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if(I2C_SDA){Byte|=(0x80>>i);}
		I2C_SCL=0;
	}
}
/**
  * @brief  发送应答
* @param 	AckBit应答位，0为应答，1为非应答
  * @retval 无
  */
void I2C_SendAck(bit AckBit)
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	I2C_SCL=0;
}
/**
  * @brief  接受应答
  * @param 	无
  * @retval AckBit应答位，0为应答，1为非应答
  */
unsigned char I2C_ReceiveAck(void)
{	
	unsigned char AckBit;
	I2C_SDA=1;
	I2C_SCL=1;
	AckBit=I2C_SDA;
	I2C_SCL=0;
	return AckBit;
}