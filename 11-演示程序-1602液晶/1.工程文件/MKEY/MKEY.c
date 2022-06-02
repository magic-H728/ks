#include "MKEY.h"
#include	"delay.h"
/*********************************************************************
�ļ����ƣ�LED.h
��    ����V1.0
˵    ����LED��غ��������ļ�
�޸ļ�¼��2021-11-11
*********************************************************************/

/*********************************************************************
����ԭ�ͣ�void LED_GPIO_config(void)
�������ܣ�LED�˿ڳ�ʼ������
�����������
�����������
*********************************************************************/
void	MKEY_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_PullUp;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//��ʼ��
}
/*********************************************************************
����ԭ�ͣ�u8 Mkey_Read(void)
�������ܣ����󰴼���ֵ��ȡ����
�����������
�����������
*********************************************************************/
u8 Mkey_Read(void)
{
	u8 val=16;
		switch(P6)
		{
			case 0x11:  val = 0;
			break;
			case 0x21:  val = 1;
			break;			
			case 0x41:  val = 2;
			break;			
			case 0x81:  val = 3;
			break;
			
			case 0x12:  val = 4;
			break;			
			case 0x22:  val = 5;
			break;			
			case 0x42:  val = 6;
			break;			
			case 0x82:  val = 7;
			break;				
			
			case 0x14:  val = 8;
			break;			
			case 0x24:  val = 9;
			break;			
			case 0x44:  val = 10;
			break;			
			case 0x84:  val = 11;
			break;			
			
			case 0x18:  val = 12;
			break;			
			case 0x28:  val = 13;
			break;			
			case 0x48:  val = 14;
			break;			
			case 0x88:  val = 15;
			break;	
			default:val=16;
				break;
		}

return val;

}