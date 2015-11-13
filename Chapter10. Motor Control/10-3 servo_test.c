/********************************************
程序名称：servo_test
功能：舵机控制范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
#define PWM_PERIOD  20000 //PWM周期为20ms（20000us）
int servoPin = 0;

//功能函数部分
//设置高电平时间，范围：1000-2000us
void servoSetPulse(int pin, int pulse)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(pin, LOW);
  delayMicroseconds(PWM_PERIOD - pulse);
}

//设置舵机转动角度，范围0-180°
void servoSetAngle(int pin, int angle)
{
  if(angle >= 0 && angle <= 180)
    servoSetPulse(pin, angle*11+1000);
}

//初始化设置部分
void setup()
{
  pinMode(servoPin,OUTPUT);
}

//循环执行部分
void loop()
{
  //0-180°之间循环转动舵机
  for(int i=0;i<=180;i++)
  {
    servoSetAngle(servoPin, i);
  }
  for(int i=180;i>=0;i--)
  {
    servoSetAngle(servoPin, i);
  }
}