#include "LED1616.h"
/*********************************************************************
�ļ����ƣ�LED1616.h
��    ����V1.0
˵    ����1616LED��غ��������ļ�
�޸ļ�¼��2021-11-11
*********************************************************************/

/*********************************************************************
����ԭ�ͣ�void LED_GPIO_config(void)
�������ܣ�LED�˿ڳ�ʼ������
�����������
�����������
*********************************************************************/
void	_1616LED_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P7, &GPIO_InitStructure);	//��ʼ��
	
		
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//��ʼ��
	
	GPIO_InitStructure.Pin  = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2| GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P0, &GPIO_InitStructure);	//��ʼ��	
	
	GPIO_InitStructure.Pin  = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P1, &GPIO_InitStructure);	//��ʼ��		

	GPIO_InitStructure.Pin  = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4| GPIO_Pin_5;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//��ʼ��			
}

u16 SET_Point_Y[16]={	0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,
											0X0100,0X0200,0X0400,0X0800,0X1000,0X2000,0X4000,0X8000};
u16 SET_Point_X[16]={	0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,
											0X0100,0X0200,0X0400,0X0800,0X1000,0X2000,0X4000,0X8000};
void SET_LED1616_CMD(u16 CMDY,u16 CMDX)
{
	P77 = CMDY & 0X0001; //0000 0000 0000 0001
	P76 = CMDY & 0X0002;	//0000 0000 0000 0010
	P75 = CMDY & 0X0004;	//0000 0000 0000 0100
	P74 = CMDY & 0X0008;	//0000 0000 0000 1000
	P73 = CMDY & 0X0010;	//0000 0000 0001 0000
	P72 = CMDY & 0X0020;	//0000 0000 0010 0000
	P71=  CMDY & 0X0040;	//0000 0000 0100 0000
	P70 = CMDY & 0X0080;	//0000 0000 1000 0000

	
	P67 = CMDY & 0X0100;  //0000 0000 0000 0001
	P66 = CMDY & 0X0200;	//0000 0000 0000 0010
	P65 = CMDY & 0X0400;	//0000 0000 0000 0100
	P64 = CMDY & 0X0800;	//0000 0000 0000 1000
	P63 = CMDY & 0X1000;	//0000 0000 0001 0000
	P62 = CMDY & 0X2000;	//0000 0000 0010 0000
	P61 = CMDY & 0X4000;	//0000 0000 0100 0000
	P60 = CMDY & 0X8000;	//0000 0000 1000 0000

	P01 = CMDX & ~0X0001; //
	P02 = CMDX & ~0X0002;	//
	P05 = CMDX & ~0X0004;	//
	P06 = CMDX & ~0X0008;	//
	P07 = CMDX & ~0X0010;	//
	P00 = CMDX & ~0X0020;	//
	P13 = CMDX & ~0X0040;	//
	P14 = CMDX & ~0X0080;	//

	
	P15 = CMDX & ~0X0100; //
	P16 = CMDX & ~0X0200;	//
	P17 = CMDX & ~0X0400;	//
	P30 = CMDX & ~0X0800;	//
	P31 = CMDX & ~0X1000;	//
	P32 = CMDX & ~0X2000;	//
	P34 = CMDX & ~0X4000;	//
	P35 = CMDX & ~0X8000;	//
	
}

void SET_LED1616_POINT(u16 CMDY,u16 CMDX)
{
	SET_LED1616_CMD(SET_Point_Y[CMDY],SET_Point_Y[CMDX]);
}
