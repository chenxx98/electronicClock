#ifndef _LCD1602_H_
#define _LCD1602_H_

/*****************LCD1602管脚配置********************/
#define LCD_PORT P0  //数据端口
sbit E=P1^7;		//1602使能引脚
sbit RW=P1^6;		//1602读写引脚	
sbit RS=P1^5;		//1602数据/命令选择引脚

/*******************函数声明************************/
/*****************底层驱动函数********************/
void LCD1602_Delay();
void Write_CMD(unsigned char del);	 //写指令
void Write_DAT(unsigned char del);  //写数据

/*****************基础应用函数********************/
void LCD1602_Init();   //初始化
//显示字符函数  hang为行值取值范围0-1， lie为列值取值范围0-15，dat为ASCII字符  //
void LCD1602_char(unsigned char hang,unsigned char lie,char dat);//显示字符
//显示字符串函数  hang为行值取值范围0-1， lie为列值取值范围0-15，*p为字符串数组地址  //
void LCD1602_string(unsigned char hang,unsigned char lie,unsigned char *p);//显示字符串
//显示2位数字函数  hang为行值取值范围0-1， lie为列值取值范围0-15，dat为整形数字  //
void LCD1602_2num(unsigned char hang,unsigned char lie,unsigned int dat);//显示2位数字
void LCD1602_4num(unsigned char hang,unsigned char lie,unsigned int dat);//显示4位数字

/***************************用户函数**************************************/


#endif
