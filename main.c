#include <reg51.h>
#include "timer.h"
#include "lcd1602.h"
#include "key4_4.h"
//#include "exit.h"
//���滻
#define uchar unsigned char  //  ֵ�� 0--255
#define uint unsigned int    //  ֵ�� 0--65535
//��������
uchar keynum;

//������
void main(void)
{
	LCD1602_Init(); //LCD1602��ʼ��
	Init_T1();      //��ʱ��T1��ʼ��
//	Init_INT0();    //�ⲿ�ж�INT0��ʼ��  
//	Init_INT1();    //�ⲿ�ж�INT1��ʼ�� 
	
  while(1)
	{	
    //����1602��ʾ
    //��ʾ��/��/��
		LCD1602_4num(0,3,year);
		LCD1602_char(0,7,'/');
		LCD1602_2num(0,8,month);
		LCD1602_char(0,10,'/');
		LCD1602_2num(0,11,day);
	  //��ʾʱ���֣���
    LCD1602_2num(1,4,hour);
		LCD1602_char(1,6,':');
		LCD1602_2num(1,7,min);
		LCD1602_char(1,9,':');
		LCD1602_2num(1,10,sec);
    
    //���󰴼��޸�����ʱ��
    keynum=keybord_sacn();//��ȡ��������ֵ
    if(keynum!=0)
	{
	  switch(keynum)//���֧ѡ��
		{
			case 1:year++;break;//��++  
		  case 2:year--;break;//��--
			case 3:month++;if(month>12)month=01;break;//��++
			case 4:month--;if(month<=0)month=12;break;//��--
	
			case 5:day++;if(day>30)day=01;break;//��++
			case 6:day--;if(day<=0)day=30;break;//��--
			case 7:hour++;if(hour>=24)hour=0;break;//ʱ++
			case 8:hour--;if(hour<=0)hour=23;break;//ʱ--
			
			case 9:min++;if(min>=60)min=0;break;//��++
			case 10:min--;if(min<=0)min=59;break;//��--
			case 11:sec++;if(sec>=60)sec=0;break;//��++
			case 12:sec--;if(sec<=0)sec=59;break;//��--
			
			//case 13:;break;//�л�����
			//case 14:;break;//ʱ
			//case 15:;break;//��
			//case 16:;break;//��
			default: break;	
		}
	}
    
    
	}
}
