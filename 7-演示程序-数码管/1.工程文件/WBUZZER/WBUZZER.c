#include "WBUZZER.h"




void	WBUZZER_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_7;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P2, &GPIO_InitStructure);	//��ʼ��
}
