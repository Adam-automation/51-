#include <at89c51RC2.h>
#include "LCD1602.h"
#include "Delay.h"

int result=0;

void main()
{
	LCD_Init();
	LCD_ShowChar(1,1,'A');
	LCD_ShowString(1,3,"HEllo");
	LCD_ShowSignedNum(1,13,-66,2);
	LCD_ShowHexNum(2,1,0xA8,2);
	LCD_ShowBinNum(2,4,0xAA,8);
	while(1)
	{
		result++;
		Delay(1000);
		LCD_ShowNum(1,9,result,3);
	}
}