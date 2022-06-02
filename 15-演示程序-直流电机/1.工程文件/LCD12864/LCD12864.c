#include "LCD12864.h"
#include "delay.h"
#include "FONT.h"
/*********************************************************************
�ļ����ƣ�LED1616.h
��    ����V1.0
˵    ����1616LED��غ��������ļ�
�޸ļ�¼��2021-11-11
*********************************************************************/

/*********************************************************************
����ԭ�ͣ�void LCD1602_GPIO_config(void)
�������ܣ�LCD�˿ڳ�ʼ������
�����������
�����������
*********************************************************************/
void	LCD12864_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//�ṹ����
	GPIO_InitStructure.Mode = GPIO_PullUp;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//��ʼ��
	
	GPIO_InitStructure.Mode = GPIO_PullUp;	
	GPIO_InitStructure.Pin  = GPIO_Pin_0 |GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_3;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P7, &GPIO_InitStructure);	//��ʼ��
	GPIO_InitStructure.Mode = GPIO_PullUp;
	GPIO_InitStructure.Pin  = GPIO_Pin_1;			//ָ��Ҫ��ʼ����IO, GPIO_Pin_7, �����
	GPIO_Inilize(GPIO_P0, &GPIO_InitStructure);	//��ʼ��
	
}



void Delay1(u8 delay)
{
	u8 j;
	while(delay--)
	{
		for(j=0;j<1;j++);
	}
}


/** LCDæ��� **/
void is_lcd12864_busy(){
//	Lcd12864DataIn();
//	Lcd12864RSLow();
//	Lcd12864RWHigh();
//	Lcd12864ENHigh();
//	while(Lcd12864Data()&0x80);
//	Lcd12864ENLow();
//	Lcd12864DataOut();
}

void lcd12864_write_cmd(u8 cmd){
	is_lcd12864_busy();
	Lcd12864RSLow();
	Lcd12864RWLow();
	Lcd12864WriteData(cmd);
	Lcd12864ENHigh();
	Delay1(5);
	Lcd12864ENLow();
}

void lcd12864_write_data(u8 dat){
	is_lcd12864_busy();
	Lcd12864RSHigh();
	Lcd12864RWLow();
	Lcd12864WriteData(dat);
	Lcd12864ENHigh();
	Delay1(5);
	Lcd12864ENLow();
}

//��������
void lcd12864_clear(){
	u8 i,j;
	Lcd12864CS1High();
	Lcd12864CS2High();
	for(i=0;i<8;i++){    //��8ҳ
		lcd12864_write_cmd(0xB8+i);  //��굽iҳ
		lcd12864_write_cmd(0x40);    //��굽ҳ��
		for(j=0;j<64;j++)lcd12864_write_data(0); //д0����
	}
}

void lcd12864_init()
{
	Lcd12864DataOut();
	Lcd12864CS1Low();
	Lcd12864CS2Low();
	Lcd12864ENLow();
	Delay1(10);
	lcd12864_write_cmd(0x3f);   //����ʾ
	lcd12864_write_cmd(0xc0);   //������ʾ��ʼ��
	lcd12864_clear();    //����
}
/******** ����ߴ������ʾ���� ***********|
|��������ʾλ�ã�rowҳ����col�кţ�    |
|    �ַ���С��x�������أ�y����ҳ��   |
|    ��ʾ���ݣ�tab��ģ��          ******/
void lcd12864_showXY(u8 row,u8 col,u8 x,u8 y,const u8 *tab){
	u8 i,j,right;
	if(col<64){
		right=0;
	} //����������־
	else {
		col-=64;
		right=1;
	}
	for(i=0;i<y;i++){
		if(right)
		{
			Lcd12864CS2Low();
			Lcd12864CS1High();
		}
		else
		{
			Lcd12864CS1Low();
			Lcd12864CS2High();
		}
		lcd12864_write_cmd(0xb8+row+i); //��
		lcd12864_write_cmd(0x40+col);   //��
		for(j=0;j<x;j++){
			if(col+j<64){
				lcd12864_write_data(tab[i*x+j]); //δ����
			}
			else if(right==0){//������������
				Lcd12864CS2Low();
				Lcd12864CS1High();
				lcd12864_write_cmd(0xb8+row+i);
				lcd12864_write_cmd(0x40+(col+j-64));
				lcd12864_write_data(tab[i*x+j]);
			}
		}
	}
}

u8 en_char_index(const u8 s){
	return s-32;
}

/* ����һ��16*16�ַ�����λ�� */
u8 cn_char_index(const u8 *s){
	u8 i;
	for(i=0;zm16x16_index[i]!=0;i+=2)
		if(zm16x16_index[i]==*s&&zm16x16_index[i+1]==*(s+1))break;
	return i/2;
}

/* ��ʾ�ַ��� */
void Lcd12864_showStr(u8 row,u8 col,const u8 *s){
	u8 i;
	for(i=0;s[i]!=0;i++){
		if(s[i]<0x80){  //Ӣ��
		   lcd12864_showXY(row,col,8,2,zm8x16_Table[en_char_index(s[i])]);
		   col+=8;
		}else{
			lcd12864_showXY(row,col,16,2,zm16x16_Table[cn_char_index(&s[i])]);
			col+=16;i+=1;
		}
		if(col>120){  //���д���
			col=0;
			row+=2;
		}
	}
}
