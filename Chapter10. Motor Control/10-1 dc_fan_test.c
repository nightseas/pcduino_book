/********************************************
程序名称：dc_fan_test
功能：直流风扇控制范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int fanPin=10;//GPIO10连接风扇

//功能函数部分
//设置PWM占空比
void setDuty(int pin, int percent)
{
  int duty = percent*255/100;
  analogWrite(pin, duty);
}

//初始化设置部分
void setup()
{
  pinMode(fanPin, OUTPUT);
}

//循环执行部分
void loop()
{
  //从0-100%循环改变风扇占空比
  for(int i=0;i<=100;i+=10)
  {
    setDuty(fanPin, i);
    printf("Duty cycle of the fan is %d\%\n", i);
    delay(3000);
  } 
}
