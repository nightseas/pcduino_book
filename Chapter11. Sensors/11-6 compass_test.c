/********************************************
�������ƣ�compass_test
���ܣ�pcDuinoʹ��I2C�ӿ������HMC5883L��������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "Wire.h"

//�궨�弰ȫ�ֱ���
#define I2C_HMC5883L_ADDR               (0x1E) //7-Bit Addresss

#define REG_HMC5883L_CFG_A              0x00
#define REG_HMC5883L_CFG_B              0x01
#define REG_HMC5883L_MODE               0x02
#define REG_HMC5883L_X_HBYTE            0x03
#define REG_HMC5883L_X_LBYTE            0x04
#define REG_HMC5883L_Z_HBYTE            0x05
#define REG_HMC5883L_Z_LBYTE            0x06
#define REG_HMC5883L_Y_HBYTE            0x07
#define REG_HMC5883L_Y_LBYTE            0x08

#define CONST_PI  3.1415926535

//���ܺ�������
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

void HMC5883L_Init(void)
{
  //I2C_WaitStandby(I2C_HMC5883L_ADDR);
  //I2C_WriteByte(I2C_HMC5883L_ADDR, HMC5883L_REG_CONFIG_A, 0x78);
  //I2C_WriteByte(I2C_HMC5883L_ADDR, HMC5883L_REG_CONFIG_B, 0x20);
  I2C_WriteByte(I2C_HMC5883L_ADDR, REG_HMC5883L_MODE, 0x00);
}

void HMC5883L_Shutdown(void)
{
  I2C_WriteByte(I2C_HMC5883L_ADDR, REG_HMC5883L_MODE, 0x01);
}

void HMC5883L_MultiRead(short* x, short* y, short* z)
{
  byte ReadBuffer[6];
  I2C_RandomRead(I2C_HMC5883L_ADDR, REG_HMC5883L_X_HBYTE, ReadBuffer, 6);
  *x = (ReadBuffer[0]<<8) + ReadBuffer[1];
  *y = (ReadBuffer[4]<<8) + ReadBuffer[5];
  *z = (ReadBuffer[2]<<8) + ReadBuffer[3];
}

double HMC5883L_GetAngleDouble(void)
{
  double Angle;
  short x, y, z;
  HMC5883L_MultiRead(&x, &y, &z);
  Angle = atan2((double)y,(double)x)*(180/CONST_PI)+180;
  return Angle;
}

int HMC5883L_GetAngleInt(void)
{
  return((int)(HMC5883L_GetAngleDouble()*10));
}

//��ʼ�����ò���
void setup()
{
  Wire.begin();
  printf("Init HMC5883L...\n");
  HMC5883L_Init();
}

//ѭ��ִ�в���
void loop()
{
  double angle;
  angle = HMC5883L_GetAngleDouble();
  printf("Direction Angle: %.4fDegree(s)\n", angle);
  delay(500);
}
