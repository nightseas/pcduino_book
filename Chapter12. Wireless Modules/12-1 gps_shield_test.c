/********************************************
程序名称：gps_shield_test
功能：GPS Sheild范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量

//功能函数部分

//初始化设置部分
void setup()
{
  //初始化连接GPS的串口
  Serial.begin(9600); 
  while(!Serial); //等待串口准备好
}

//循环执行部分
void loop()
{
  //将从串口接收到的GPS数据打印在屏幕上
  if(Serial.available() > 0) 
  {
    printf("%c", char(Serial.read()));
    fflush(stdout);
  }
}