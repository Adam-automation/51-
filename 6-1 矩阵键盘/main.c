#include <at89c51RC2.h>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char Keynum;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey");
	while(1)
	{
		Keynum=MatrixKey();
		if(Keynum)
		{
			LCD_ShowNum(2,1,Keynum,2);
		}
	}
}
