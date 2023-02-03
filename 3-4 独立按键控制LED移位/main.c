#include <at89c51RC2.h>
#include <INTRINS.H>

void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--)
	{
		nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{
	unsigned char LEDNUM;
	P2=~0x01;
	while(1)
	{
		if(P3_1==0)
		{
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			LEDNUM++;
			if(LEDNUM>=8)
				LEDNUM=0;
			P2=~(0x01<<LEDNUM);
		}
		if(P3_0==0)
		{
			Delay1ms(20);
			while(P3_0==0);
			Delay1ms(20);
			if(LEDNUM==0)
				LEDNUM=7;
			else
				LEDNUM--;
			P2=~(0x01<<LEDNUM);		
		}
	}
}