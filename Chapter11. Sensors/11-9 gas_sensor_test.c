/********************************************
程序名称：gas_sensor_test
功能：气体传感器范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int gasSensorPin = 0; //气体传感器连接模拟输入A0
int ledPin = 13;      //LED连接GPIO13

int gasData = 0;

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(ledPin, OUTPUT);
}

//循环执行部分
void loop()
{  
  gasData = analogRead(gasSensorPin);
  //当气体浓度超过阈值，点亮LED
  if(gasData > 45)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
  printf("Gas sensor data: %d\n", gasData);
  delay(500);
}