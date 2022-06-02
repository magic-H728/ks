#include "DCMOTO.h"
///*********************************************************************
//文件名称：LED88.h
//版    本：V1.0
//说    明：88LED相关函数功能文件
//修改记录：2021-11-11
//*********************************************************************/

//#define T1MS (65536-MAIN_Fosc/1000)      //1T模式
///*********************************************************************
//函数原型：void LED_GPIO_config(void)
//函数功能：LED端口初始化函数
//输入参数：无
//输出参数：无
//*********************************************************************/
//void DCMOTO_GPIO_config(void)
//{
//	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
//	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//	
//	GPIO_InitStructure.Pin  = GPIO_Pin_6;			//指定要初始化的IO, GPIO_Pin_7, 或操作
//	GPIO_Inilize(GPIO_P0, &GPIO_InitStructure);	//初始化
//	
//	GPIO_InitStructure.Pin  = GPIO_Pin_0 |GPIO_Pin_1;			//指定要初始化的IO, GPIO_Pin_7, 或操作
//	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//初始化	
//	
//}
//void Time0_16_Config_Init(void)
//{
//    AUXR |= 0x80;                   //定时器0为1T模式
////  AUXR &= 0x7f;                   //定时器0为12T模式

//    TMOD = 0x00;                    //设置定时器为模式0(16位自动重装载)
//    TL0 = T1MS;                     //初始化计时值
//    TH0 = T1MS >> 8;
//    TR0 = 1;                        //定时器0开始计时
//    ET0 = 1;                        //使能定时器0中断
//    EA = 1;
//}
//void DCMoto_Sta(u8 sta,u8 dir)
//{

//	switch(sta)
//	{
//		case 0: TR0 = 0;	IN1 = 0;IN2 =0; break;
//		case 1:TR0 = 1;
//		switch(dir)
//		{
//			case 1:
//				IN1 = 1;
//				IN2 =0;
//				break;	
//		
//			case 2:
//				IN1 = 0;
//				IN2 =1;
//				break;	
//		}break;	
//}
//}





//void tm0_isr() interrupt 1 using 1
//{
//    P06= ! P06;                    //将测试口取反
//}


