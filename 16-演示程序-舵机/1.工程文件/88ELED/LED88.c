#include "LED88.h"
/*********************************************************************
文件名称：LED88.h
版    本：V1.0
说    明：88LED相关函数功能文件
修改记录：2021-11-11
*********************************************************************/

/*********************************************************************
函数原型：void LED_GPIO_config(void)
函数功能：LED端口初始化函数
输入参数：无
输出参数：无
*********************************************************************/
void	_88LED_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P7, &GPIO_InitStructure);	//初始化
	
		
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//初始化
}


u8 PointX[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};

u8 PointY[8]={0x80,0X40,0X20,0X10,0X08,0X04,0X02,0X01};
/*********************************************************************
函数原型：void SET_Point(u8 x,u8 y)
函数功能：XY坐标打点
输入参数：无
输出参数：无
*********************************************************************/
void SET_Point(u8 x,u8 y)
{
	
	P6=PointX[x];
	P7=PointY[y];
}
