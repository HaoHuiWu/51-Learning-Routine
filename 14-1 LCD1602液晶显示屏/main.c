#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

void main ()
{		
		LCD_Init();
//		LCD_ShowChar(1,2,0xDF);
		LCD_ShowString(1,1,"PanWanYi is SB! SB is PanWanYi");
//		LCD_ShowNum(1,9,66,2);
//		LCD_ShowSignedNum(1,12,-88,2);
//		LCD_ShowHexNum(2,1,0xA5,2);
//		LCD_ShowBinNum(2,4,0xA5,8);
    while(1)
    {	
			
//      LCD_WriteCommand(0x18);
//			Delay(100);

    }
}
