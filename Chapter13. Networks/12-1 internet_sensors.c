/********************************************
程序名称：internet_sensors
功能：pcDuino网络气象站范例代码
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
#define I2C_BMP085_ADDR                 (0x77) //7-Bit Addresss

#define REG_BMP085_AC1_MSB              0xAA
#define REG_BMP085_AC2_MSB              0xAC
#define REG_BMP085_AC3_MSB              0xAE
#define REG_BMP085_AC4_MSB              0xB0
#define REG_BMP085_AC5_MSB              0xB2
#define REG_BMP085_AC6_MSB              0xB4
#define REG_BMP085_B1_MSB               0xB6
#define REG_BMP085_B2_MSB               0xB8
#define REG_BMP085_MB_MSB               0xBA
#define REG_BMP085_MC_MSB               0xBC
#define REG_BMP085_MD_MSB               0xBE
#define REG_BMP085_CTRL                 0xF4
#define REG_BMP085_DATA_MSB             0xF6

#define BMP085_TEMP_DELAY()             delay( 5 )//MDelay_ms(5)
#define BMP085_PRSS_DELAY()             delay( 14 )//MDelay_ms(14)

#define CONST_P0                        101325.0f
#define OSS                             2 //From 0 to 2, and 3 is incorrect!

short ac1, ac2, ac3;
unsigned short ac4, ac5, ac6; 
short b1, b2, mb, mc, md;

int lightSensorPin = 0; //光照传感器连接模拟输入A0

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

void BMP085_Init(void)
{
  byte ReadBuffer[22];
  I2C_RandomRead(I2C_BMP085_ADDR, REG_BMP085_AC1_MSB, ReadBuffer, 22);
  ac1 = ((ReadBuffer[0]<<8) + ReadBuffer[1]);
  ac2 = ((ReadBuffer[2]<<8) + ReadBuffer[3]);
  ac3 = ((ReadBuffer[4]<<8) + ReadBuffer[5]);
  ac4 = ((ReadBuffer[6]<<8) + ReadBuffer[7]);
  ac5 = ((ReadBuffer[8]<<8) + ReadBuffer[9]);
  ac6 = ((ReadBuffer[10]<<8) + ReadBuffer[11]);
  b1 = ((ReadBuffer[12]<<8) + ReadBuffer[13]);
  b2 = ((ReadBuffer[14]<<8) + ReadBuffer[15]);
  mb = ((ReadBuffer[16]<<8) + ReadBuffer[17]);
  mc = ((ReadBuffer[18]<<8) + ReadBuffer[19]);
  md = ((ReadBuffer[20]<<8) + ReadBuffer[21]);
}

unsigned short BMP085_GetUT(void)
{
  byte ReadBuffer[2];
  unsigned short ut;
  
  I2C_WriteByte(I2C_BMP085_ADDR, REG_BMP085_CTRL, 0x2E);
  BMP085_TEMP_DELAY();
  I2C_RandomRead(I2C_BMP085_ADDR, REG_BMP085_DATA_MSB, ReadBuffer, 2);
  
  ut = (unsigned short)((ReadBuffer[0]<<8) + ReadBuffer[1]);
  return (ut);
}


unsigned int BMP085_GetUP(void)
{
  byte ReadBuffer[3];
  unsigned int up;

  I2C_WriteByte(I2C_BMP085_ADDR, REG_BMP085_CTRL, 0x34+(OSS<<6));
  BMP085_PRSS_DELAY();
  I2C_RandomRead(I2C_BMP085_ADDR, REG_BMP085_DATA_MSB, ReadBuffer, 3);
  
  up = (unsigned int)(((ReadBuffer[0]<<16) + (ReadBuffer[1]<<8) + ReadBuffer[2])>>(8-OSS));
  return (up);
}

//Temp in 0.1C, Pressure in 1Pa
void BMP085_GetTempPress(int* Temp, int* Pressure)
{
  unsigned int ut;
  unsigned int up;
  long x1, x2, b5, b6, x3, b3, p;
  unsigned long b4, b7;

  ut = BMP085_GetUT();
  up = BMP085_GetUP();
  
  //Calculate Temperautre
  x1 = ((long)ut - ac6) * ac5 >> 15;
  x2 = ((long) mc << 11) / (x1 + md);
  b5 = x1 + x2;
  *Temp = (b5 + 8) >> 4;

  //Calculate Pressure
  b6 = b5 - 4000;
  x1 = (b2 * (b6 * b6 >> 12)) >> 11;
  x2 = ac2 * b6 >> 11;
  x3 = x1 + x2;
  b3 = ((((long)ac1 * 4 + x3) << OSS) + 2) / 4;
  x1 = ac3 * b6 >> 13;
  x2 = (b1 * (b6 * b6 >> 12)) >> 16;
  x3 = ((x1 + x2) + 2) >> 2;
  b4 = (ac4 * (unsigned long) (x3 + 32768)) >> 15;
  b7 = ((unsigned long) up - b3) * (50000 >> OSS);
  if( b7 < 0x80000000)
    p = (b7 * 2) / b4 ;
  else  
    p = (b7 / b4) * 2;
  x1 = (p >> 8) * (p >> 8);
  x1 = (x1 * 3038) >> 16;
  x2 = (-7357 * p) >> 16;
  *Pressure = p + ((x1 + x2 + 3791) >> 4);
}

void saveData(char *fname, int data)
{
  FILE *fd = fopen(fname, "w");
  if(fd == NULL)
  {
    printf("File on error!\n");  
    exit(1);
  }
  fprintf(fd, "{\n");
  fprintf(fd, "  \"value\":%d\n", data);
  fprintf(fd, "}\n");
  
  fclose(fd);
}

//初始化设置部分
void setup()
{
  int temp = 0, press = 0, light = 0;
  
  Wire.begin();
  printf("Init BMP085...\n");
  BMP085_Init();  
  
  delay(1000);
  BMP085_GetTempPress(&temp, &press);
  light = analogRead(lightSensorPin);
  
  printf("Temperature: %dC, Pressure: %dPa, Light: %d\n", temp/10, press, light);
  
  saveData("temp.txt", temp/10);
  saveData("press.txt", press);
  saveData("light.txt", light);
  
  exit(0);
}

//循环执行部分
void loop()
{
}
