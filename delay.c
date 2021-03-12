#include "delay.h"
#include <intrins.h>
void Delay_100us()		//��ʱ100us
{
	unsigned char i;

	_nop_();
	i = 47;
	while (--i);

}

void Delay_1ms()		//��ʱ1ms 
{
	unsigned char i, j;
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

void Delay_xms(unsigned char ms)//��ʱ��ms��ms 
{
	unsigned char i, j;
	i = 2*ms;
	j = 200;
	do
	{
		while (--j);
	} while (--i);
   
}