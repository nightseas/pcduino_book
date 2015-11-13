/********************************************
程序名称：seg7_test
功能：七段数码管范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
//GPIO与数码管连接关系定义
//a -- GPIO0
//b -- GPIO3
//c -- GPIO2
//d -- GPIO4
//e -- GPIO5
//f -- GPIO8
//g -- GPIO7
//dp -- GPIO1
#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define dp 7

//数字段码表
int segTable[10] =  {1<<a | 1<<b | 1<<c | 1<<d | 1<<e | 1<<f,        //数字0
                     1<<b | 1<<c,                                    //数字1
                     1<<a | 1<<b | 1<<d | 1<<e | 1<<g,               //数字2
                     1<<a | 1<<b | 1<<c | 1<<d | 1<<g,               //数字3
                     1<<b | 1<<c | 1<<f | 1<<g,                      //数字4
                     1<<a | 1<<c | 1<<d | 1<<f | 1<<g,               //数字5
                     1<<a | 1<<c | 1<<d | 1<<e | 1<<f | 1<<g,        //数字6
                     1<<a | 1<<b | 1<<c,                             //数字7
                     1<<a | 1<<b | 1<<c | 1<<d | 1<<e | 1<<f | 1<<g, //数字8
                     1<<a | 1<<b | 1<<c | 1<<d | 1<<f | 1<<g};       //数字9

//功能函数部分
//显示数字
void displayNumber(int numMask)
{
  for(int i=0;i<=8;i++)
  {
    if((segTable[numMask]>>i)&0x1)
      digitalWrite(i, LOW); //点亮断码表中指定的段
    else
      digitalWrite(i, HIGH); //其他段熄灭
  }
}

//初始化设置部分
void setup()
{
  for(int i=0;i<=8;i++)
    pinMode(i,OUTPUT);  //设置GPIO0-GPIO8为输出
}

//循环执行部分
void loop()
{
  //循环显示数字0-9
  for(int i=0;i<=9;i++)
  {
    printf("seg[%d]=0x%03x\n", i, segTable[i]);
    displayNumber(i);
    delay(1000);
  }
}