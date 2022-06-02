#include "STMP_MOTO.h"
#include "delay.h"
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
void	STMP_MOTO_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	

	GPIO_InitStructure.Pin  = GPIO_Pin_1 |GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4 ;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//��ʼ��
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

















