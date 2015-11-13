/********************************************
程序名称：light_sensor_test
功能：光照传感器范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int lightSensorPin = 0; //光照传感器连接模拟输入A0
int ledPin = 13;        //LED连接GPIO13

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(ledPin, OUTPUT);
}

//循环执行部分
void loop()
{
  //当光线低于一定程度，点亮LED
  if(analogRead(lightSensorPin) < 30)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
