#include "PULSE_IN_BIT_OUT.h"
/*********************************************************************
�ļ����ƣ�BIT_IN_OUT.h
��    ����V1.0
˵    ����LED��غ��������ļ�
�޸ļ�¼��2021-11-11
*********************************************************************/

/*********************************************************************
����ԭ�ͣ�void BitInOut_config(void)
�������ܣ�λ����������˿ڳ�ʼ������
�����������
�����������
*********************************************************************/
void	BitInOut_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Pin  = GPIO_Pin_4;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_InitStructure.Mode = GPIO_HighZ;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//��ʼ��
	
	
	GPIO_InitStructure.Pin  = GPIO_Pin_0;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P5, &GPIO_InitStructure);	//��ʼ��
	
}




