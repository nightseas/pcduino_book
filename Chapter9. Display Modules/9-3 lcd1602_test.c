/********************************************
程序名称：lcd1602_test
功能：LCD1602使用范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>
#include <LiquidCrystal.h> //LiquidCrystal库头文件

//宏定义及全局变量
//通过LiquidCrystal类定义LCD引脚(4-Bit模式)，对应方式如下：
//LCD RS -- GPIO8
//LCD EN -- GPIO9
//LCD D4 -- GPIO4
//LCD D5 -- GPIO5
//LCD D6 -- GPIO6
//LCD D7 -- GPIO7
LiquidCrystal lcd1602( 8, 9, 4, 5, 6, 7 ); 

//功能函数部分

//初始化设置部分
void setup()
{
  //初始化1602LCD
  lcd1602.begin(16, 2);
  //在LCD上打印信息
  lcd1602.print("Hello pcDuino!");
}

//循环执行部分
void loop()
{
  lcd1602.setCursor(0, 1);      //设置光标位置至第2行，第1列
  lcd1602.print(millis()/1000); //打印软件运行时间
}