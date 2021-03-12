#ifndef _KEY4_4_H_
#define _KEY4_4_H_

#include <reg51.h>
#define	KEY_PORT  P3  //引脚定义

//矩阵键盘扫描函数：无按键按下或无效时返回0；有效返回1-16
unsigned char keybord_sacn();//矩阵键盘扫描函数

/*读按键对应数据函数*/
/* 按键有效返回：
			///0-9对应0-9，
			///+：10，-：11，*：12，/：13 ，C:14，=：15 
	 按键无效返回：16              */
unsigned char read_keydat(void);
#endif

