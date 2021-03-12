#ifndef _LCD1602_H_
#define _LCD1602_H_

/*****************LCD1602�ܽ�����********************/
#define LCD_PORT P0  //���ݶ˿�
sbit E=P1^7;		//1602ʹ������
sbit RW=P1^6;		//1602��д����	
sbit RS=P1^5;		//1602����/����ѡ������

/*******************��������************************/
/*****************�ײ���������********************/
void LCD1602_Delay();
void Write_CMD(unsigned char del);	 //дָ��
void Write_DAT(unsigned char del);  //д����

/*****************����Ӧ�ú���********************/
void LCD1602_Init();   //��ʼ��
//��ʾ�ַ�����  hangΪ��ֵȡֵ��Χ0-1�� lieΪ��ֵȡֵ��Χ0-15��datΪASCII�ַ�  //
void LCD1602_char(unsigned char hang,unsigned char lie,char dat);//��ʾ�ַ�
//��ʾ�ַ�������  hangΪ��ֵȡֵ��Χ0-1�� lieΪ��ֵȡֵ��Χ0-15��*pΪ�ַ��������ַ  //
void LCD1602_string(unsigned char hang,unsigned char lie,unsigned char *p);//��ʾ�ַ���
//��ʾ2λ���ֺ���  hangΪ��ֵȡֵ��Χ0-1�� lieΪ��ֵȡֵ��Χ0-15��datΪ��������  //
void LCD1602_2num(unsigned char hang,unsigned char lie,unsigned int dat);//��ʾ2λ����
void LCD1602_4num(unsigned char hang,unsigned char lie,unsigned int dat);//��ʾ4λ����

/***************************�û�����**************************************/


#endif
