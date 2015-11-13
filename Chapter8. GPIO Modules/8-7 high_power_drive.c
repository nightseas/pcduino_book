/********************************************
程序名称：high_power_drive
功能：三极管驱动范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int ctrlPin = 13; //GPIO13连接三极管控制引脚

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(ctrlPin, OUTPUT);
}

//循环执行部分
void loop()
{
  digitalWrite(ctrlPin, HIGH); //高电平三极管导通
  delay(1000);
  digitalWrite(ctrlPin, LOW);
  delay(1000);
}
