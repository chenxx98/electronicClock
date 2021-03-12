#include "timer.h"
#include <reg51.h>
//���滻
#define uchar unsigned char  //  ֵ�� 0--255
#define uint unsigned int    //  ֵ�� 0--65535
//��������
uchar sec=20,min=50,hour=22,day=20,month=05;
uint year=2020,cnt=0;

void Init_T1(void)  //��ʱ��T1��ʼ��
{
	TMOD &=0X0F;//����λΪ0
	TMOD |=0X10;//MO��λ1��  ��ʱ��1��ʽ1
	
  TH1=(65536-50000)/256;//��8λ
	TL1=(65536-50000)%256;//��8λ
	TR1=1;  //������ʱ��
  TF1=0;//��־λ����
	ET1=1;//����ʱ��1�ж�
	EA=1;//���ж����ж�
	PT1=1;//���ȼ� 
}

//��ʱ��T1�жϷ�����
void T1_IRQ(void)  interrupt 3     //50msһ��
{
	TH1=(65536-50000)/256;//���¸���ֵ
	TL1=(65536-50000)%256;
	
  cnt++;
	if(cnt==20)//�ж���20�ξ���1s
	{
		cnt=0;
		sec++;   //���
		if(sec>=60)
		{
			sec=0;
			min++;//�ּ�
		  if(min>=60)
			{
				min=0;
				hour++;//ʱ��
				if(hour>=24)
				{
					hour=0;
					day++; //�ռ�
					if(day>=30)
					{
						day=0;
						month++;//�¼�
						if(month>=12)
						{
							month=0;
							year++;//���
						}
					}
				}
			}
		}
	}	
}

