#include "timer.h"
#include <reg51.h>
//宏替换
#define uchar unsigned char  //  值域 0--255
#define uint unsigned int    //  值域 0--65535
//变量定义
uchar sec=20,min=50,hour=22,day=20,month=05;
uint year=2020,cnt=0;

void Init_T1(void)  //定时器T1初始化
{
	TMOD &=0X0F;//高四位为0
	TMOD |=0X10;//MO置位1；  定时器1方式1
	
  TH1=(65536-50000)/256;//高8位
	TL1=(65536-50000)%256;//低8位
	TR1=1;  //开启定时器
  TF1=0;//标志位清零
	ET1=1;//允许定时器1中断
	EA=1;//打开中断总中断
	PT1=1;//优先级 
}

//定时器T1中断服务函数
void T1_IRQ(void)  interrupt 3     //50ms一次
{
	TH1=(65536-50000)/256;//重新赋初值
	TL1=(65536-50000)%256;
	
  cnt++;
	if(cnt==20)//中断了20次就是1s
	{
		cnt=0;
		sec++;   //秒加
		if(sec>=60)
		{
			sec=0;
			min++;//分加
		  if(min>=60)
			{
				min=0;
				hour++;//时加
				if(hour>=24)
				{
					hour=0;
					day++; //日加
					if(day>=30)
					{
						day=0;
						month++;//月加
						if(month>=12)
						{
							month=0;
							year++;//年加
						}
					}
				}
			}
		}
	}	
}

