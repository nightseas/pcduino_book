/********************************************
程序名称：tft_lcd_test
功能：TFT LCD范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <stdint.h>
#include <core.h>
#include <SPI.h>
#include "TFTv2.h" //TFT LCD库所需头文件

//宏定义及全局变量

//功能函数部分

//初始化设置部分
void setup()
{
  TFT_BL_ON;     //打开LCD背光
  Tft.TFTinit(); //初始化TFT LCD库
  
  Tft.drawString("welcome",30,50,4,RED);        //打印字符串，坐标：(30,50),大小: 4，颜色：红色   
  Tft.drawString("to",90,110,4,YELLOW);         //打印字符串，坐标：(90,110),大小: 4，颜色：黄色 
  Tft.drawString("pcDuino!",30,170,4,CYAN);     //打印字符串，坐标：(30,170),大小: 4，颜色：青色   
  Tft.drawString("16/03/2013",80,280,2,WHITE);  //打印字符串，坐标：(80,280),大小: 2，颜色：白色  
}

//循环执行部分
void loop()
{   
}