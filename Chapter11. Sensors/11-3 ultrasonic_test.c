/********************************************
程序名称：ultrasonic_test
功能：超声波模块范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
//定义热释电模块连接的GPIO
//TRIG -- GPIO2
//ECHO -- GPIO3
int trigPin = 2;
int echoPin = 3;

//功能函数部分
//将回波脉冲时间转换成距离，单位：英寸
long microsecondsToInches(long microseconds)
{
  return (microseconds / 74 / 2);
}

//将回波脉冲时间转换成距离，单位：厘米
long microsecondsToCentimeters(long microseconds)
{
  return (microseconds / 29 / 2);
}

//初始化设置部分
void setup()
{
  //ECHO设置为输入，用于检测回波
  pinMode(echoPin,INPUT);
  //TRIG设置为输出，用于触发模块发射超声波
  pinMode(trigPin,OUTPUT);
  digitalWrite(trigPin,LOW);
  delay(100);
}

//循环执行部分
void loop()
{
  long duration, inches, cm;
  
  //发送20us高电平脉冲
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  
  //接收回波并测量脉冲时间
  duration = pulseIn(echoPin, HIGH, 1000000);
  //将回波脉冲转换成与被测物体间的距离并显示
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);  
  printf("Distance=%ldcm (%ldinches)\n", cm, inches);
  delay(1000);
}