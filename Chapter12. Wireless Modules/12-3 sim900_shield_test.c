/********************************************
程序名称：sim900_shield_test
功能：SIM900 Shield范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>
#include "Serial.h"

//宏定义及全局变量
//定义LED及按键连接的GPIO
//拨号按键 -- GPIO2
//挂断按键 -- GPIO3
//状态LED  -- GPIO4
int buttonPin1  = 2;
int buttonPin2  = 3;
int ledPin      = 4;
//功能函数部分

//初始化设置部分
void setup()
{
  //初始化GPIO
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  pinMode(ledPin,OUTPUT);
  //初始化串口
  Serial.begin(19200);
  while(!Serial);
}

//循环执行部分
void loop()
{
  int buttonStatus1 = digitalRead(buttonPin1);
  int buttonStatus2 = digitalRead(buttonPin2);
  
  digitalWrite(ledPin,LOW);
  delay(200);
  digitalWrite(ledPin,HIGH);
  delay(200);
  
  //按键1按下，拨打制定号码
  if(buttonStatus1)
  {
    delay(5);
    buttonStatus1 = digitalRead(buttonPin1);
    if(buttonStatus1)
    {
     //ATD指令+“号码”拨打制定号码，此处号码为虚构
     Serial.println("ATD + +8618612345678;");
     digitalWrite(ledPin, HIGH);
     
     //检测按键2是否按下，按下则挂断
     do{ 
        buttonStatus2 = digitalRead(buttonPin2);
        //通过延时10ms消除按键抖动
        if(buttonStatus2)
        {
          delay(10);
          buttonStatus2 = digitalRead(buttonPin2);
        }
     }while(!buttonStatus2);
     
     //ATH指令挂断
     Serial.println("ATH");
     digitalWrite(ledPin, LOW);
     delay(2000);
    }
  }
}
