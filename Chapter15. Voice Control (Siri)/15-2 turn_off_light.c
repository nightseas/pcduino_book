/********************************************
程序名称：turn_off_light
功能：为语音控制提供关灯功能
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int ctrlPin = 13; //GPIO13连接LED

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(ctrlPin, OUTPUT);
  digitalWrite(ctrlPin, LOW); //关闭LED
  exit(0); //退出程序
}

//循环执行部分
void loop()
{
}
