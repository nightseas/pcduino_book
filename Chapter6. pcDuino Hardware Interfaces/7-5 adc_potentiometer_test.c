/********************************************
程序名称：adc_potentiometer_test
功能：pcDuino使用ADC接口检测电位器位置范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int ledPin=10;//LED连接GPIO10
int adcResult;

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(ledPin, OUTPUT);
}

//循环执行部分
void loop()
{
  //读取A0电压数据(A0为6-Bit分辨率，值：0-63)
  adcResult = analogRead(A0);
  //通过设置占空比调光
  analogWrite(ledPin, adcResult);
  delay(10);
}