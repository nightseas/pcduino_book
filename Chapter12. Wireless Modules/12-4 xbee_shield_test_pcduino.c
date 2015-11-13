/********************************************
程序名称：xbee_shield_test_pcduino
功能：XBee模块范例代码（pcDuino端）
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int ledPin    = 9;  //LED连接Arduino D9
int buttonPin = 10; //按键连接Arduino D10
int ledOnFlag = 0;

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  digitalWrite(ledPin,HIGH);
  Serial.begin(9600);
}

//循环执行部分
void loop()
{
    //如果按键按下通过XBee模块发送字符'a'
  if(digitalRead(buttonPin) == LOW)
  {
    //延时10ms消除按键抖动
    delay(10);
    if(digitalRead(buttonPin) == LOW)
    {
      Serial.print('b');
      delay(200);
    } 
  }
  
  //如果接收到XBee模块发来的字符'a'，LED闪烁
  if (Serial.available() > 0)
  {
    byte dataRead;
    dataRead = Serial.read();
    if(dataRead == 'a')
    {
      printf("The data received is %c\n", (char)dataRead);
      if(ledOnFlag == 1)
      {
        printf("led off\n");
        digitalWrite(ledPin,HIGH);
        ledOnFlag = 0;
      }
      else
      {
        printf("led on\n");
        digitalWrite(ledPin,LOW);
        ledOnFlag = 1;
      }      
    }
  }
}