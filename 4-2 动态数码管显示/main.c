#include <at89c51RC2.h>
#include <INTRINS.H>
void Delay(unsigned int xms)		//@11.0592MHz
{
	
	while(xms--)
	{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	}
}

unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void NixieTube(unsigned char Location,Number)
{
	switch(Location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=NixieTable[Number];
	Delay(1);
	P0=0x00;
}
void main()
{	
	
	while(1)
	{
		NixieTube(1,1);
//		Delay(20);
		NixieTube(2,2);
//		Delay(20);
		NixieTube(3,3);
//		Delay(20);
	}
}