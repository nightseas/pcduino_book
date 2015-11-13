/********************************************
程序名称：pwm_led_test
功能：pcDuino使用PWM接口控制LED呼吸灯范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
#define LED_MAX_PWM   0x25  //LED最高亮度对应的PWM参数
#define DELAY_TIME    700  //每个亮度值持续的时间基数

int ledPin=10;//LED连接GPIO10

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(ledPin, OUTPUT);
}

//循环执行部分
void loop()
{
  //亮度逐渐增加
  for(int i=0;i<=LED_MAX_PWM;i++)
  {
    analogWrite(ledPin, i); //设置PWM占空比
    delayMicroseconds(DELAY_TIME*(LED_MAX_PWM-i));
  }
  //亮度逐渐衰减
  for(int i=LED_MAX_PWM;i>=0;i--)
  {
    analogWrite(ledPin, i);
    delayMicroseconds(DELAY_TIME*(LED_MAX_PWM-i));
  }
  delay(1500);
}