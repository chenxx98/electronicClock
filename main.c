#include <reg51.h>
#include "timer.h"
#include "lcd1602.h"
#include "key4_4.h"
//#include "exit.h"
//宏替换
#define uchar unsigned char  //  值域 0--255
#define uint unsigned int    //  值域 0--65535
//变量定义
uchar keynum;

//主程序
void main(void)
{
	LCD1602_Init(); //LCD1602初始化
	Init_T1();      //定时器T1初始化
//	Init_INT0();    //外部中断INT0初始化  
//	Init_INT1();    //外部中断INT1初始化 
	
  while(1)
	{	
    //调用1602显示
    //显示年/月/日
		LCD1602_4num(0,3,year);
		LCD1602_char(0,7,'/');
		LCD1602_2num(0,8,month);
		LCD1602_char(0,10,'/');
		LCD1602_2num(0,11,day);
	  //显示时：分：秒
    LCD1602_2num(1,4,hour);
		LCD1602_char(1,6,':');
		LCD1602_2num(1,7,min);
		LCD1602_char(1,9,':');
		LCD1602_2num(1,10,sec);
    
    //矩阵按键修改日期时间
    keynum=keybord_sacn();//读取按键返回值
    if(keynum!=0)
	{
	  switch(keynum)//多分支选择
		{
			case 1:year++;break;//年++  
		  case 2:year--;break;//年--
			case 3:month++;if(month>12)month=01;break;//月++
			case 4:month--;if(month<=0)month=12;break;//月--
	
			case 5:day++;if(day>30)day=01;break;//日++
			case 6:day--;if(day<=0)day=30;break;//日--
			case 7:hour++;if(hour>=24)hour=0;break;//时++
			case 8:hour--;if(hour<=0)hour=23;break;//时--
			
			case 9:min++;if(min>=60)min=0;break;//分++
			case 10:min--;if(min<=0)min=59;break;//分--
			case 11:sec++;if(sec>=60)sec=0;break;//秒++
			case 12:sec--;if(sec<=0)sec=59;break;//秒--
			
			//case 13:;break;//切换闹钟
			//case 14:;break;//时
			//case 15:;break;//分
			//case 16:;break;//关
			default: break;	
		}
	}
    
    
	}
}
