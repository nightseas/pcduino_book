/********************************************
程序名称：i2c_rtc_test
功能：pcDuino使用I2C接口操作DS1307范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>
#include "Wire.h"

//宏定义及全局变量
#define  DS1307_ADDR    0x68 //DS1307的7-Bit I2C设备地址

//功能函数部分
byte DEC2BCD(byte val) //数字转换至BCD码
{
   return ( (val/10*16) + (val%10) );
}

byte BCD2DEC(byte val) //BCD码转换至数字
{
  return ( (val/16*10) + (val%16) );
}

//设置RTC时间
void rtcSetTime(byte year, byte month, byte date, byte dayofWeek, byte hour, byte min ,byte sec)
{
  byte reg = 0x00;
  //开始I2C通信
  Wire.beginTransmission(DS1307_ADDR);  
  //寄存器地址，从寄存器0开始写入，每写一字节数据寄存器地址自动增加
  Wire.write(reg); 
  //写入数据
  Wire.write(DEC2BCD(sec));
  Wire.write(DEC2BCD(min));
  Wire.write(DEC2BCD(hour));
  Wire.write(DEC2BCD(dayofWeek));
  Wire.write(DEC2BCD(date));
  Wire.write(DEC2BCD(month));
  Wire.write(DEC2BCD(year));
  //I2C通信结束
  Wire.endTransmission();     
}

//读取并打印RTC时间
void rtcGetTime() 
{
  byte year, month, date, dayofWeek, hour, min ,sec;
  byte reg = 0x00;
  //开始I2C通信
  Wire.beginTransmission(DS1307_ADDR);
  //寄存器地址，从寄存器0开始读取
  Wire.write(reg);
  Wire.endTransmission();
  //连续读取7字节数据
  Wire.requestFrom(DS1307_ADDR, 7);

  sec       = BCD2DEC(Wire.read() & 0x7f);  //去除最高位（控制位）
  min       = BCD2DEC(Wire.read());
  hour      = BCD2DEC(Wire.read() & 0x3f);  //24小时计时法
  dayofWeek = BCD2DEC(Wire.read());
  date      = BCD2DEC(Wire.read());
  month     = BCD2DEC(Wire.read());
  year      = BCD2DEC(Wire.read());

  printf("Time: %d-%d-%d  %d:%d:%d.\n", year, month, date, hour, min ,sec);
}

//初始化设置部分
void setup()
{
  Wire.begin();
  //初始化RTC时间
  printf("Writing time 2013-12-01 Sundy 21:10:00 to RTC...\n");
  rtcSetTime(13,12,1,7,21,10,0);
}

//循环执行部分
void loop()
{
  //每秒读取一次RTC时间
  rtcGetTime();
  delay(1000);
}