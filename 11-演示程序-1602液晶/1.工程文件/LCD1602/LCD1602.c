#include "LCD1602.h"
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
void	LCD1602_GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;			//结构定义
	GPIO_InitStructure.Mode = GPIO_PullUp;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	
	GPIO_InitStructure.Pin  = GPIO_Pin_All;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P6, &GPIO_InitStructure);	//初始化
	
		
	GPIO_InitStructure.Pin  = GPIO_Pin_0 |GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P7, &GPIO_InitStructure);	//初始化
	
	GPIO_InitStructure.Pin  = GPIO_Pin_0;			//指定要初始化的IO, GPIO_Pin_7, 或操作
	GPIO_Inilize(GPIO_P0, &GPIO_InitStructure);	//初始化
	
}

u8 code Xword[]={
    0x18,0x18,0x07,0x08,0x08,0x08,0x07,0x00,        //℃，代码 0x00
    0x00,0x00,0x00,0x00,0xff,0x00,0x00,0x00,        //一，代码 0x01
    0x00,0x00,0x00,0x0e,0x00,0xff,0x00,0x00,        //二，代码 0x02
    0x00,0x00,0xff,0x00,0x0e,0x00,0xff,0x00,        //三，代码 0x03
    0x00,0x00,0xff,0xf5,0xfb,0xf1,0xff,0x00,        //四，代码 0x04
    0x00,0xfe,0x08,0xfe,0x0a,0x0a,0xff,0x00,        //五，代码 0x05
    0x00,0x04,0x00,0xff,0x00,0x0a,0x11,0x00,        //六，代码 0x06
    0x00,0x1f,0x11,0x1f,0x11,0x11,0x1f,0x00,        //日，代码 0x07
};

void Delay(u8 delay)
{
	u8 j;
	while(delay--)
	{
		for(j=0;j<1;j++);
	}
}


/** 远程不需要测忙 **/
void is_lcd1602_busy(){
//	Lcd1602DataIn();
//	Lcd1602RSLow();
//	Lcd1602RWHigh();
//	Lcd1602ENHigh();
//	while(Lcd1602BusyData());
//	Lcd1602ENLow();
//	Lcd1602DataOut();
}

void lcd1602_write_cmd(u8 cmd){
	is_lcd1602_busy();
	Lcd1602RSLow();
	Lcd1602RWLow();
	Lcd1602WriteData(cmd);
	Lcd1602ENHigh();
	Delay(5);
	Lcd1602ENLow();
}

void lcd1602_write_data(u8 dat){
	is_lcd1602_busy();
	Lcd1602RSHigh();
	Lcd1602RWLow();
	Lcd1602WriteData(dat);
	Lcd1602ENHigh();
	Delay(5);
	Lcd1602ENLow();
}

//清屏函数
void lcd1602_clear(void)
{
	lcd1602_write_cmd(CMD_clear);
}

void lcd1602_init_cgram(void) {	// 装入CGRAM //
	u8 i;
	lcd1602_write_cmd(0x06);			// CGRAM地址自动加1
	lcd1602_write_cmd(0x40);			// CGRAM地址设为00处
	for(i=0;i<64;i++) {
		lcd1602_write_data(Xword[i]);// 按数组写入数据
	}
}

void lcd1602_init()
{
	Lcd1602DataOut();
	lcd1602_write_cmd(CMD_set82);
	lcd1602_write_cmd(CMD_clear);
	lcd1602_write_cmd(CMD_back);
	lcd1602_write_cmd(CMD_add1);
	lcd1602_write_cmd(CMD_dis_gb3);
	lcd1602_init_cgram();
}

/********************************************************************************************
// 打印单字符程序 // 
// 第一行位置 0x00~0x15  第二行位置 0x40~0x55 
// 向LCD发送一个字符,以十六进制（0x00）表示 
// 应用举例：print(0xc0,0x30); //在第二行第一位处打印字符“0”
/********************************************************************************************/
void lcd1602_show_char(u8 pos, u8 dat)
{
	lcd1602_write_cmd(pos|0x80);
	lcd1602_write_data(dat);
}

/********************************************************************************************
// 打印字符串程序 // （本函数调用指针函数）
// 向LCD发送一个字符串,长度48字符之内 
// 第一行位置 0x00~0x15  第二行位置 0x40~0x55 
// 应用举例：print(0x80,"doyoung.net"); //在第一行第一位处从左向右打印doyoung.net字符串
/********************************************************************************************/
void lcd1602_show_str(u8 pos,u8 *str)
{
	lcd1602_write_cmd(pos | 0x80);
	while(*str != '\0'){
		lcd1602_write_data(*str++);
	}
}
