/********************************************
程序名称：tilt_test
功能：倾斜开关模块范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
int tiltPin = 0; //GPIO0连接倾斜开关输出端
int tiltStatus; //用于保存倾斜开关状态

//功能函数部分

//初始化设置部分
void setup() {                
  pinMode(tiltPin , INPUT);
}

//循环执行部分
void loop() {
  tiltStatus = digitalRead(tiltPin); //读取倾斜开关状态
  if(tiltStatus == HIGH)
    printf("The object tilt to left side!\n");
  else
    printf("The object tilt to right side!\n");
  delay(1000);
}