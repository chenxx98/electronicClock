#include "exit.h"

void Init_INT0(void)//��ʼ���ⲿ�ж�0
{
	IT0=1;//���ô�����ʽ ���ش���
	IE0=0;//�����־λ
	EX0=1;//�ⲿ�ж�0�Ŀ��أ���
	EA=1;//�ж��ܿ���
	PX0=1;//�������ȼ���1��
}
void Init_INT1(void)//��ʼ���ⲿ�ж�1
{
	IT1=1;////���ô�����ʽ ���ش���
	IE1=0;//�����־λ
	EX1=1;//�ⲿ�ж�0�Ŀ��⣬��
	EA=1;//�ж��ܿ���
	PX1=1;//�������ȼ���1��
}

//�ⲿ�ж�0��1������
void INT0_IRQ(void) interrupt 0
{
	sec++;    //P32��⵽�������
	if(sec>59)   
	{
		min++;  
		sec=0;
	}
}
void INT1_IRQ(void) interrupt 2
{
	min++;   //P33��⵽�������
	if(min>59)
	{
		hour++;
		min=0;	
	}
}


