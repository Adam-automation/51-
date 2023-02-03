#include <at89c51RC2.h>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char Keynum;
unsigned int Password,Count;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		Keynum=MatrixKey();
		if(Keynum)
		{
			if(Keynum<=10)  //如果s1~s10按键按下，输入密码
			{
				if(Count<4)   //密码位数小于4时进入循环
				{
					Password*=10;        //密码左移一位
					Password+=Keynum%10;  //获取一位密码
					Count++;		//密码位数计次
				}
				LCD_ShowNum(2,1,Password,4);
			}
			if(Keynum==11)   //s11为确认键
			{
				if(Password==2345)
				{
					LCD_ShowString(1,14,"OK");
					Password=0;									//密码清零
					Count=0;										//计次清零
					LCD_ShowNum(2,1,Password,4);//更新显示
				}
				else
				{
					LCD_ShowString(1,14,"NO");
					Password=0;
					Count=0;
					LCD_ShowNum(2,1,Password,4);
				}
			}
			if(Keynum==12)  //如果s12按键按下，取消一位密码
			{
					Password/=10;								
					Count-=1;										
					LCD_ShowNum(2,1,Password,4);
			}
		}
	}
}
