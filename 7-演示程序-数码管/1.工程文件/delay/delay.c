#include	"delay.h"

/*********************************************************************
文件名称：delay.h
版    本：V1.0
说    明：延时函数相关
修改记录：2021-11-11
*********************************************************************/

/*********************************************************************
函数原型：void  delay_ms(unsigned int ms)
函数功能：毫秒级延时函数
输入参数：ms毫秒
输出参数：无
*********************************************************************/
void  delay_ms(unsigned int ms)
{
	unsigned int i;
	do{
		i = MAIN_Fosc / 13000;
	while(--i)	;   	
	}while(--ms);
}
/*********************************************************************
函数原型：void  delay_us(unsigned int us)
函数功能：微秒秒级延时函数
输入参数：us微秒
输出参数：无
*********************************************************************/
void  delay_us(unsigned int us)
{
	unsigned int i;
	do
	{
		i = MAIN_Fosc / 30000000;
		while(--i);	
	}while(--us);
}