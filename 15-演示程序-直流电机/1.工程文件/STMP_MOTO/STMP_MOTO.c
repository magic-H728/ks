#include "STMP_MOTO.h"
#include "delay.h"
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
void	STMP_MOTO_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	

	GPIO_InitStructure.Pin  = GPIO_Pin_1 |GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4 ;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//初始化
}

void _delay_moto(u8 t)
{
	u8 i,j;
	for(i=0;i<t;i++)
	for(j=0;j<10;j++);


}

void STEP_MOTO_RUN(u16 speed)
{

 INA  = 1;
 INB 	= 0;
 INC	= 0;
 IND 	= 0;
	_delay_moto(speed);
 INA  = 1;
 INB 	= 1;
 INC	= 0;
 IND 	= 0;
	_delay_moto(speed);
 INA  = 0;
 INB 	= 1;
 INC	= 0;
 IND 	= 0;
	_delay_moto(speed);
 INA  = 0;
 INB 	= 1;
 INC	= 1;
 IND 	= 0;
	_delay_moto(speed);
 INA  = 0;
 INB 	= 0;
 INC	= 1;
 IND 	= 0;
	_delay_moto(speed);	
	INA  = 0;
 INB 	= 0;
 INC	= 1;
 IND 	= 1;
	_delay_moto(speed);
 INA  = 0;
 INB 	= 0;
 INC	= 0;
 IND 	= 1;
	_delay_moto(speed);	
 INA  = 1;
 INB 	= 0;
 INC	= 0;
 IND 	= 1;
	_delay_moto(speed);		
	
	
	
	
	
	
	
	
	
	
	
	
}

















