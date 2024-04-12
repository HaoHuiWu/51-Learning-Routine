#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

unsigned char OneWire_Init(void);
void OneWire_SendBit(unsigned char Bit);
unsigned OneWire_ReceiveBit(void);
void OneWire_SendByte(unsigned char Byte);
unsigned OneWire_ReceiveByte(void);

#endif