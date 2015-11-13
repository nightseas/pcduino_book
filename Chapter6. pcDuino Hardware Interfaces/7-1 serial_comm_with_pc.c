/********************************************
程序名称：serial_comm_with_pc
功能：pcDuino使用UART接口与PC机通信范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
byte readByte;

//初始化设置部分
void setup() {
  Serial.begin(115200, SERIAL_8N1); //设置串口波特率为115200，8位数据位，无校验位，1位停止位
  while(!Serial); //等待串口准备好
  Serial.println("Hello pcDuino!"); //打印一行字符串
}

//循环执行部分
void loop() {
  if(Serial.available() > 0)
  {
    readByte = Serial.read(); //读取一个字节数据
    Serial.write(readByte); //将读取到的数据则通过串口发回PC
  }
}
