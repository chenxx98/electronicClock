#ifndef _KEY4_4_H_
#define _KEY4_4_H_

#include <reg51.h>
#define	KEY_PORT  P3  //���Ŷ���

//�������ɨ�躯�����ް������»���Чʱ����0����Ч����1-16
unsigned char keybord_sacn();//�������ɨ�躯��

/*��������Ӧ���ݺ���*/
/* ������Ч���أ�
			///0-9��Ӧ0-9��
			///+��10��-��11��*��12��/��13 ��C:14��=��15 
	 ������Ч���أ�16              */
unsigned char read_keydat(void);
#endif

