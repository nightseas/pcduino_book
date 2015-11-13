/********************************************
程序名称：accelerometer_test
功能：pcDuino使用I2C接口与操作ADXL345范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "Wire.h"

//宏定义及全局变量
#define I2C_ADXL345_ADDR                (0x53) //7-Bit Addresss

#define REG_ADXL345_ID                  0x00
#define REG_ADXL345_DAT_FORMAT          0x31
#define REG_ADXL345_BW_RATE             0x2C
#define REG_ADXL345_PWR_CTRL            0x2D
#define REG_ADXL345_INT_EN              0x2E
#define REG_ADXL345_OFFSET_X            0x1E
#define REG_ADXL345_OFFSET_Y            0x1F
#define REG_ADXL345_OFFSET_Z            0x20
#define REG_ADXL345_X_LBYTE             0x32
#define REG_ADXL345_X_HBYTE             0x33
#define REG_ADXL345_Y_LBYTE             0x34
#define REG_ADXL345_Y_HBYTE             0x35
#define REG_ADXL345_Z_LBYTE             0x36
#define REG_ADXL345_Z_HBYTE             0x37

//功能函数部分
void I2C_WriteByte(byte devAddr, byte regAddr, byte value)
{
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);            
  Wire.write(value);              
  Wire.endTransmission();
}

void I2C_RandomRead(byte devAddr, byte regAddr, byte* value, int count)
{
  Wire.beginTransmission(devAddr);
  Wire.write(regAddr);            
  Wire.endTransmission();

  Wire.requestFrom(devAddr, count);
  while(Wire.available())
  {
     *value = Wire.read();
     value++;
  }
}

void ADXL345_Init(void)
{
  //I2C_WaitStandby(I2C_ADXL345_ADDR);
  I2C_WriteByte(I2C_ADXL345_ADDR, REG_ADXL345_DAT_FORMAT, 0x0B);  //±16g，13-bit
  I2C_WriteByte(I2C_ADXL345_ADDR, REG_ADXL345_BW_RATE, 0x08); //Sample rate 12.5
  I2C_WriteByte(I2C_ADXL345_ADDR, REG_ADXL345_PWR_CTRL, 0x08);  //Power Config
  I2C_WriteByte(I2C_ADXL345_ADDR, REG_ADXL345_INT_EN, 0x80);  //Enable DATA_READY interrupt
  delay(500);
}

void ADXL345_Shutdown(void)
{
  I2C_WriteByte(I2C_ADXL345_ADDR, REG_ADXL345_PWR_CTRL, 0x01);
}

void ADXL345_MultiRead(short* x, short* y, short* z)
{
  byte ReadBuffer[6];
  I2C_RandomRead(I2C_ADXL345_ADDR, REG_ADXL345_X_LBYTE, ReadBuffer, 6);
  *x = (ReadBuffer[1]<<8) + ReadBuffer[0];
  *y = (ReadBuffer[3]<<8) + ReadBuffer[2];
  *z = (ReadBuffer[5]<<8) + ReadBuffer[4];
}


//Acceleration in 0.1mg
void ADXL345_GetAcceleration(int* x, int* y, int* z)
{
  short tmpx, tmpy, tmpz;
  ADXL345_MultiRead(&tmpx, &tmpy, &tmpz);
  *x = (int)tmpx * 39;
  *y = (int)tmpy * 39;
  *z = (int)tmpz * 39;
}

//初始化设置部分
void setup()
{
  Wire.begin();
  printf("Init ADXL345...\n");
  ADXL345_Init();
}

//循环执行部分
void loop()
{
  int accX, accY, accZ;
  ADXL345_GetAcceleration(&accX, &accY, &accZ);
  printf("Acceleration Data: X=%dmg, Y=%dmg, Z=%dmg\n", accX/10, accY/10, accZ/10);
  delay(500);
}
