#include "BMKEY.h"
/*********************************************************************
�ļ����ƣ�BMKEY.h
��    ����V1.0
˵    ����BMKEY��غ��������ļ�
�޸ļ�¼��2021-11-11
*********************************************************************/

/*********************************************************************
����ԭ�ͣ�void BMKEY_GPIO_config(void)
�������ܣ�LED�˿ڳ�ʼ������
�����������
�����������
*********************************************************************/
void	BMKEY_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_PullUp;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_2 |GPIO_Pin_3;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//��ʼ��
}




