#include "FOURLED.h"
#include "delay.h"
/*********************************************************************
文件名称：LED.h
版    本：V1.0
说    明：LED相关函数功能文件
修改记录：2021-11-11
*********************************************************************/
code u8 FOUR_mum[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
/*********************************************************************
函数原型：void LED_GPIO_config(void)
函数功能：LED端口初始化函数
输入参数：无
输出参数：无
*********************************************************************/
void	FOURLED_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P7, &GPIO_InitStructure);	//初始化
	
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_InitStructure.Pin  = GPIO_Pin_7;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P2, &GPIO_InitStructure);	//初始化
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_InitStructure.Pin  = GPIO_Pin_0;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//初始化
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_InitStructure.Pin  = GPIO_Pin_1;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//初始化
	
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_InitStructure.Pin  = GPIO_Pin_2;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//初始化
	DIG_A = 1;
	DIG_B = 1;
	DIG_C = 1;
	DIG_D = 1;
}

void FOUR_SMGShow(u16 num,u8 t)
{
	u8 housand=num/1000;
	u8 Hundred=num%1000/100;
	u8 Ten=num%100/10;
	u8 One=num%10;
	
	DIG_A = 0;	
	P7=FOUR_mum[housand];
	delay_ms(t);

	DIG_A = 1;	


	DIG_B = 0;	
	P7=FOUR_mum[Hundred];	
	delay_ms(t);
	DIG_B = 1;	


	DIG_C = 0;	
	P7=FOUR_mum[Ten];
	delay_ms(t);
	DIG_C = 1;	
	

	DIG_D = 0;	
	P7=FOUR_mum[One];
	delay_ms(t);
	DIG_D = 1;	
	

}

