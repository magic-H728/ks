#include "REMOTO.h"
/*********************************************************************
文件名称：LED88.h
版    本：V1.0
说    明：88LED相关函数功能文件
修改记录：2021-11-11
*********************************************************************/
#define kServoPWMCountMax   2000


u16 ServoPWMCount = 0;

u16 ServoHighPulse = 50;  //50-250

#define T1MS1 (65536-MAIN_Fosc/100000)      //1T模式
/*********************************************************************
函数原型：void LED_GPIO_config(void)
函数功能：LED端口初始化函数
输入参数：无
输出参数：无
*********************************************************************/
void REMOTO_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
	GPIO_InitStructure.Mode = GPIO_PullUp;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_6;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P0, &GPIO_InitStructure);	//初始化
}

void Time1_16_Config_Init_1(void)
{
	AUXR |= 0x40;

    TMOD = 0x00;
    TL1 = T1MS1;
    TH1 = T1MS1 >> 8;
    TR1 = 1;
    ET1 = 1;
    EA = 1;
}


//50us一次中断
void tm1_isr() interrupt 3
{
	
	ServoPWMCount++;

	if(ServoPWMCount>=kServoPWMCountMax)
	{
		ServoPWMCount=0;
	}
	if(ServoPWMCount>=ServoHighPulse)
	{
		P06 = 0;
	}
	else
	{
		P06 = 1;
	}


}


