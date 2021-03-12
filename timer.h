#ifndef _TIMER_H_
#define _TIMER_H_

#include<reg51.h>
//全局变量
extern unsigned int cnt,year;
extern unsigned char sec,min,hour,hour,day,month;
//声明函数
void Init_T1(void);//定时器T1初始化

#endif
