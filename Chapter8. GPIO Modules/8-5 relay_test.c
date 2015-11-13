/********************************************
程序名称：relay_test
功能：继电器模块范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int relayPin = 13; //GPIO13为继电器控制引脚

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(relayPin, OUTPUT);
}

//循环执行部分
void loop()
{
  digitalWrite(relayPin, HIGH); //继电器吸合
  delay(1000);
  digitalWrite(relayPin, LOW);  //继电器断开
  delay(1000);
}