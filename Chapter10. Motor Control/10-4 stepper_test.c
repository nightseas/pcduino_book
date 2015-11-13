/********************************************
程序名称：stepper_test
功能：步进电机驱动范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
//定义四相输入连接的GPIO
//A -- GPIO0
//B -- GPIO1
//C -- GPIO2
//D -- GPIO3
int pinA = 0;
int pinB = 1;
int pinC = 2;
int pinD = 3;

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
}

//循环执行部分
void loop()
{
  //双四拍驱动    
  digitalWrite(pinA,1);
  digitalWrite(pinB,0);
  digitalWrite(pinC,0);
  digitalWrite(pinD,1);
  delay(2);
  digitalWrite(pinA,1);
  digitalWrite(pinB,1);
  digitalWrite(pinC,0);
  digitalWrite(pinD,0);
  delay(2);
  digitalWrite(pinA,0);
  digitalWrite(pinB,1);
  digitalWrite(pinC,1);
  digitalWrite(pinD,0);
  delay(2);
  digitalWrite(pinA,0);
  digitalWrite(pinB,0);
  digitalWrite(pinC,1);
  digitalWrite(pinD,1);
  delay(2);
}