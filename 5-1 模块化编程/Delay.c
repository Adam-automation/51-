#include <INTRINS.H>
void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{
		nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}
