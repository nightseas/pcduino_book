/********************************************
程序名称：ir_pyro_test
功能：红外热释电模块范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>
#include <time.h>

//宏定义及全局变量
#define INT_MODE  RISING //中断模式，上升沿中断

time_t now;               //实例化time_t结构
struct tm *timenow;      //实例化tm结构指针

//功能函数部分
//热释电传感器中断执行函数
void pyroDetect(void)
{
  //获取本地时间
  time(&now);
  timenow = localtime(&now);
  printf("Human body detected! Time: %s\n", asctime(timenow));  
}

//初始化设置部分
void setup()
{
  //将GPIO2设为中断输入引脚，中断执行函数为pyroDetect
  attachInterrupt(0, pyroDetect, INT_MODE);
}

//循环执行部分
void loop()
{
}