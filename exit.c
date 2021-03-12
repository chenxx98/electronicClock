#include "exit.h"

void Init_INT0(void)//初始化外部中断0
{
	IT0=1;//设置触发方式 跳沿触发
	IE0=0;//清除标志位
	EX0=1;//外部中断0的开关，开
	EA=1;//中断总开关
	PX0=1;//配置优先级，1高
}
void Init_INT1(void)//初始化外部中断1
{
	IT1=1;////设置触发方式 跳沿触发
	IE1=0;//清除标志位
	EX1=1;//外部中断0的开光，开
	EA=1;//中断总开关
	PX1=1;//配置优先级，1高
}

//外部中断0、1服务函数
void INT0_IRQ(void) interrupt 0
{
	sec++;    //P32检测到跳沿秒加
	if(sec>59)   
	{
		min++;  
		sec=0;
	}
}
void INT1_IRQ(void) interrupt 2
{
	min++;   //P33检测到跳沿秒加
	if(min>59)
	{
		hour++;
		min=0;	
	}
}


