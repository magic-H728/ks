#include "LCD12864.h"
#include "delay.h"
#include "FONT.h"
/*********************************************************************
文件名称：LED1616.h
版    本：V1.0
说    明：1616LED相关函数功能文件
修改记录：2021-11-11
*********************************************************************/

/*********************************************************************
函数原型：void LCD1602_GPIO_config(void)
函数功能：LCD端口初始化函数
输入参数：无
输出参数：无
*********************************************************************/
void	LCD12864_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
	GPIO_InitStructure.Mode = GPIO_PullUp;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//初始化
	
	GPIO_InitStructure.Mode = GPIO_PullUp;	
	GPIO_InitStructure.Pin  = GPIO_Pin_0 |GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_3;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P7, &GPIO_InitStructure);	//初始化
	GPIO_InitStructure.Mode = GPIO_PullUp;
	GPIO_InitStructure.Pin  = GPIO_Pin_1;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P0, &GPIO_InitStructure);	//初始化
	
}



void Delay1(u8 delay)
{
	u8 j;
	while(delay--)
	{
		for(j=0;j<1;j++);
	}
}


/** LCD忙检测 **/
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

//清屏函数
void lcd12864_clear(){
	u8 i,j;
	Lcd12864CS1High();
	Lcd12864CS2High();
	for(i=0;i<8;i++){    //共8页
		lcd12864_write_cmd(0xB8+i);  //光标到i页
		lcd12864_write_cmd(0x40);    //光标到页首
		for(j=0;j<64;j++)lcd12864_write_data(0); //写0清屏
	}
}

void lcd12864_init()
{
	Lcd12864DataOut();
	Lcd12864CS1Low();
	Lcd12864CS2Low();
	Lcd12864ENLow();
	Delay1(10);
	lcd12864_write_cmd(0x3f);   //开显示
	lcd12864_write_cmd(0xc0);   //设置显示起始行
	lcd12864_clear();    //清屏
}
/******** 任意尺寸点阵显示函数 ***********|
|参数：显示位置：row页数，col列号，    |
|    字符大小：x横向像素，y纵向页数   |
|    显示内容：tab字模表          ******/
void lcd12864_showXY(u8 row,u8 col,u8 x,u8 y,const u8 *tab){
	u8 i,j,right;
	if(col<64){
		right=0;
	} //置左右屏标志
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
		lcd12864_write_cmd(0xb8+row+i); //行
		lcd12864_write_cmd(0x40+col);   //列
		for(j=0;j<x;j++){
			if(col+j<64){
				lcd12864_write_data(tab[i*x+j]); //未跨屏
			}
			else if(right==0){//从左屏跨右屏
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

/* 返回一个16*16字符索引位置 */
u8 cn_char_index(const u8 *s){
	u8 i;
	for(i=0;zm16x16_index[i]!=0;i+=2)
		if(zm16x16_index[i]==*s&&zm16x16_index[i+1]==*(s+1))break;
	return i/2;
}

/* 显示字符串 */
void Lcd12864_showStr(u8 row,u8 col,const u8 *s){
	u8 i;
	for(i=0;s[i]!=0;i++){
		if(s[i]<0x80){  //英文
		   lcd12864_showXY(row,col,8,2,zm8x16_Table[en_char_index(s[i])]);
		   col+=8;
		}else{
			lcd12864_showXY(row,col,16,2,zm16x16_Table[cn_char_index(&s[i])]);
			col+=16;i+=1;
		}
		if(col>120){  //换行处理
			col=0;
			row+=2;
		}
	}
}
