/********************************************
程序名称：joystick_test
功能：Joystick范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int valX, valY;

//功能函数部分


//初始化设置部分
void setup()
{
}

//循环执行部分
void loop()
{
  valX = analogRead(0); //通过ADC0读取X方向数值
  valY = analogRead(1); //通过ADC1读取Y方向数值
  printf("JoyStick_X=%d, JoyStick_Y=%d\n", valX, valY);
  delay(800);
}
