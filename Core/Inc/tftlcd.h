#ifndef _tftlcd_H
#define _tftlcd_H


#include "main.h"


#define TFTLCD_ILI9327



//TFTLCD地址结构体
typedef struct
{
	unsigned short int LCD_CMD;
	unsigned short int LCD_DATA;
}TFTLCD_TypeDef;

    
#define TFTLCD_BASE        ((unsigned int)(0x6C000000 | 0x0000007E))
#define TFTLCD             ((volatile TFTLCD_TypeDef *) TFTLCD_BASE)

#define TFTDATA_ADDR    ((unsigned int)(0x6C000080))	

//TFTLCD重要参数集
typedef struct  
{										    
	unsigned short int width;			//LCD 宽度
	unsigned short int height;			//LCD 高度
	unsigned short int id;				//LCD ID
	unsigned char  dir;            //LCD 方向
}_tftlcd_data;


//LCD参数
extern _tftlcd_data tftlcd_data;	//管理LCD重要参数
//LCD的前端颜色和背景色	   
extern unsigned short int  FRONT_COLOR;//前端颜色 默认红色    
extern unsigned short int  BACK_COLOR; //背景颜色.默认为白色


//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色



void LCD_WriteCmd(unsigned short int cmd);
void LCD_WriteData(unsigned short int data);
void LCD_WriteCmdData(unsigned short int cmd,unsigned short int data);
void LCD_WriteData_Color(unsigned short int color);

void TFTLCD_Init(void);           //初始化
void LCD_Set_Window(unsigned short int sx,unsigned short int sy,unsigned short int width,unsigned short int height);
void LCD_Clear(unsigned short int Color);	 												//清屏
void LCD_Fill(unsigned short int xState,unsigned short int yState,unsigned short int xEnd,unsigned short int yEnd,unsigned short int color);
void LCD_DrawPoint(unsigned short int x,unsigned short int y);//画点
void LCD_DrawFRONT_COLOR(unsigned short int x,unsigned short int y,unsigned short int color);
unsigned short int LCD_ReadPoint(unsigned short int x,unsigned short int y);
void LCD_DrawLine(unsigned short int x1, unsigned short int y1, unsigned short int x2, unsigned short int y2);
void LCD_DrawLine_Color(unsigned short int x1, unsigned short int y1, unsigned short int x2, unsigned short int y2,unsigned short int color);
void LCD_DrowSign(uint16_t x, uint16_t y, uint16_t color);
void LCD_DrawRectangle(unsigned short int x1, unsigned short int y1, unsigned short int x2, unsigned short int y2);
void LCD_Draw_Circle(unsigned short int x0,unsigned short int y0,unsigned char r);
void LCD_ShowChar(unsigned short int x,unsigned short int y,unsigned char num,unsigned char size,unsigned char mode);
void LCD_ShowNum(unsigned short int x,unsigned short int y,unsigned int num,unsigned char len,unsigned char size);
void LCD_ShowxNum(unsigned short int x,unsigned short int y,unsigned int num,unsigned char len,unsigned char size,unsigned char mode);
void LCD_ShowString(unsigned short int x,unsigned short int y,unsigned short int width,unsigned short int height,unsigned char size,unsigned char *p);
void LCD_ShowFontHZ(unsigned short int x, unsigned short int y, unsigned char *cn);
void LCD_ShowPicture(unsigned short int x, unsigned short int y, unsigned short int wide, unsigned short int high,unsigned char *pic);





#endif
