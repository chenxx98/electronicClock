#include <reg51.h>
#include "lcd1602.h"

void LCD1602_Delay()
{
	int i,j;
	for(i=0; i<=10; i++)
	for(j=0; j<=20; j++)
;
}

/********************************************************************
* 名称 : Write_CMD(unsigned char del)
* 功能 : 1602命令函数
* 输入 : 输入的命令值
* 输出 : 无
***********************************************************************/

void Write_CMD(unsigned char del)	 //写指令   输入：RS=L；Rw=L；                          
{						//	D0~D7= 指令码，E=高脉冲；
	LCD_PORT = del;			 //输出：D0~D7=数据
	RS = 0;
	RW = 0;
	E = 0;
	LCD1602_Delay();
	E = 1;
	LCD1602_Delay();
}


/********************************************************************
* 名称 : Write_DAT(unsigned char del)
* 功能 : 1602写数据函数
* 输入 : 需要写入1602的数据
* 输出 : 无
***********************************************************************/

void Write_DAT(unsigned char del)  //写数据  输入：RS=H；RW=L；
{
	LCD_PORT = del;		   //D0~D7=数据；E=高脉冲
	RS = 1;
	RW = 0;			   //输出：无
	E = 0;
	LCD1602_Delay();
	E = 1;
	LCD1602_Delay();
}

/********************************************************************
* 名称 : LCD1602_init()
* 功能 : 1602初始化，请参考1602的资料
* 输入 : 无
* 输出 : 无
***********************************************************************/
void LCD1602_Init(void)
{
	Write_CMD(0x01); //显示清0
	Write_CMD(0x38); //显示模式设置 ，设置16*2显示，5*7点阵，8位数据接口  
	Write_CMD(0x0c); // 显示开关光标的设置
	Write_CMD(0x06); //显示光标移动设置
//	Write_CMD(0xd0);
}

/********************************************************************
* 名称 : LCD1602_char(unsigned char hang,unsigned char lie,char sign)
* 功能 : 改变液晶中某位的值，如果要让第0行，第5个字符显示"b" ，调用该函数如下
		 LCD1602_char(0,5,'b')
* 输入 : 行，列，需要输入1602的数据
* 输出 : 无
***********************************************************************/
void LCD1602_char(unsigned char hang,unsigned char lie,char dat)
{
	unsigned char a;
	if(hang == 0) a = 0x80;
	if(hang == 1) a = 0xc0;
	a = a + lie;
	Write_CMD(a);//调用写指令函数
	Write_DAT(dat);//调用写数据函数
}

/********************************************************************
* 名称 : LCD1602_string(unsigned char hang,unsigned char lie,unsigned char *p)
* 功能 : 改变液晶中某位的值，如果要让第一行，第五个字符开始显示"ab cd ef" ，调用该函数如下
	 	 LCD1602_string(1,5,"ab cd ef;")
* 输入 : 行，列，需要输入1602的数据
* 输出 : 无
***********************************************************************/
void LCD1602_string(unsigned char hang,unsigned char lie,unsigned char *p)
{
	unsigned char a;
	if(hang == 0) a = 0x80;//0x80代表第一行第一个字
	if(hang == 1) a = 0xc0;	 //	代表第二行的第五个字
	a = a + lie ;
	Write_CMD(a);
	while(1)
	{
		if(*p == '\0') break;
		Write_DAT(*p);
		p++;
	}
}
/********************************************************************
* 名称 : LCD1602_2num(unsigned char hang,unsigned char lie,unsigned int dat)
* 功能 : 如果要让第一行，第五个字符显示整数99 ，调用该函数如下
		 LCD1602_2num(1,5,99)
* 输入 : 行，列，需要输入1602的数据
* 输出 : 无
***********************************************************************/
void LCD1602_2num(unsigned char hang,unsigned char lie,unsigned int dat)
{
	LCD1602_char( hang,lie,dat/10%10+'0');//十位
	LCD1602_char( hang,lie+1,dat%10+'0');//个位
}

/********************************************************************
* 名称 : LCD1602_num(unsigned char hang,unsigned char lie,unsigned int dat)
* 功能 : 如果要让第一行，第五个字符显示整数9999 ，调用该函数如下
		 LCD1602_2num(1,5,9999)
* 输入 : 行，列，需要输入1602的数据
* 输出 : 无
***********************************************************************/
void LCD1602_4num(unsigned char hang,unsigned char lie,unsigned int dat)
{
 	LCD1602_char( hang,lie,dat/1000%10+'0');//千位
	LCD1602_char( hang,lie+1,dat/100%10+'0');//百位
	LCD1602_char( hang,lie+2,dat/10%10+'0');//十位
	LCD1602_char( hang,lie+3,dat%10+'0'); //个位

}
