/********************************************
程序名称：ext_interrupt_test
功能：pcDuino通过外部中断方式检测按键范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
#define INT_MODE    RISING//中断模式，上升沿中断
int cntButton1 = 0, cntButton2 = 0;

//功能函数部分
//按键1中断执行函数
void button1Pressed()
{
  cntButton1++; 
  printf("Button1 pressed %d time(s).\n", cntButton1);  
}

//按键2中断执行函数
void button2Pressed()
{
  cntButton2++;
  printf("Button2 pressed %d time(s).\n", cntButton2); 
}

//初始化设置部分
void setup()
{
  //将GPIO2(INT0)和GPIO3(INT1)设为中断输入引脚，中断执行函数分别为button1Pressed和button2Pressed
  printf("Attaching interrupt pins.\n");
  attachInterrupt(0, button1Pressed, INT_MODE);
  attachInterrupt(1, button2Pressed, INT_MODE);
}

//循环执行部分
void loop()
{
}