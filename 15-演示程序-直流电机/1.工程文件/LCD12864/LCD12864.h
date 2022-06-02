#ifndef	__LCD12864_H
#define	__LCD12864_H

#include	"config.h"
#include "GPIO.h"

//#include "FONT.h"
#define Lcd12864Data() 		P6
#define Lcd12864DataIn() 	P6M1 = 0xFF
#define Lcd12864DataOut() 	P6M1 = 0x00

#define Lcd12864WriteData(dat)  P6 = dat

#define Lcd12864RWHigh()  	P71 = 1
#define Lcd12864RWLow()   	P71 = 0

#define Lcd12864RSHigh()  	P70 = 1
#define Lcd12864RSLow()   	P70 = 0

#define Lcd12864ENHigh()  	P01 = 1
#define Lcd12864ENLow()   	P01 = 0

#define Lcd12864CS1High()  	P73 = 1
#define Lcd12864CS1Low()   	P73 = 0

#define Lcd12864CS2High()  	P74 = 1
#define Lcd12864CS2Low()   	P74 = 0
void lcd12864_init();
void Lcd12864_showStr(u8 row,u8 col,const u8 *s);
void lcd12864_write_cmd(u8 cmd);
void	LCD12864_GPIO_config(void);
#endif
