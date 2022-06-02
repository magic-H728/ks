#include "LED88.h"
/*********************************************************************
�ļ����ƣ�LED88.h
��    ����V1.0
˵    ����88LED��غ��������ļ�
�޸ļ�¼��2021-11-11
*********************************************************************/

/*********************************************************************
����ԭ�ͣ�void LED_GPIO_config(void)
�������ܣ�LED�˿ڳ�ʼ������
�����������
�����������
*********************************************************************/
void	_88LED_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P7, &GPIO_InitStructure);	//��ʼ��
	
		
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//��ʼ��
}


u8 PointX[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};

u8 PointY[8]={0x80,0X40,0X20,0X10,0X08,0X04,0X02,0X01};
/*********************************************************************
����ԭ�ͣ�void SET_Point(u8 x,u8 y)
�������ܣ�XY������
�����������
�����������
*********************************************************************/
void SET_Point(u8 x,u8 y)
{
	
	P6=PointX[x];
	P7=PointY[y];
}
