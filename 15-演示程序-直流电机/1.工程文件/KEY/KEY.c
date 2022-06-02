#include "KEY.h"
/*********************************************************************
文件名称：LED.h
版    本：V1.0
说    明：LED相关函数功能文件
修改记录：2021-11-11
*********************************************************************/

/*********************************************************************
函数原型：void LED_GPIO_config(void)
函数功能：LED端口初始化函数
输入参数：无
输出参数：无
*********************************************************************/
void	KEY_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_2;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//初始化
}




