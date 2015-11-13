/********************************************
程序名称：cap_touch_test
功能：电容式触摸按键模块范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int TouchPin = 0; //GPIO0连接触摸模块输出端
int TouchStatus; //用于保存按键状态

//功能函数部分

//初始化设置部分
void setup() {                
  pinMode(TouchPin , INPUT);
}

//循环执行部分
void loop() {
  TouchStatus = digitalRead(TouchPin); //读取按键状态
  if(TouchStatus == HIGH)
    printf("The key is pressed!\n");
  else
    printf("The key is released!\n");
  delay(1000);
}