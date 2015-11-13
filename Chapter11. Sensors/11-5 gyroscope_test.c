/********************************************
�������ƣ�gyroscope_test
���ܣ�pcDuinoʹ��I2C�ӿ������L3G4200D��������
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
#define I2C_L3G4200_ADDR                (0x69) //7-Bit Addresss

#define REG_L3G4200_ID                  0x00
#define REG_L3G4200_CTRL1               0x20
#define REG_L3G4200_CTRL2               0x21
#define REG_L3G4200_CTRL3               0x22
#define REG_L3G4200_CTRL4               0x23
#define REG_L3G4200_CTRL5               0x24
#define REG_L3G4200_X_LBYTE             0x28
#define REG_L3G4200_X_HBYTE             0x29
#define REG_L3G4200_Y_LBYTE             0x2A
#define REG_L3G4200_Y_HBYTE             0x2B
#define REG_L3G4200_Z_LBYTE             0x2C
#define REG_L3G4200_Z_HBYTE             0x2D
#define REG_L3G4200_MULREAD             0xA8

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

void L3G4200_Init(void)
{
  //���ʴ���ѡ���XYZ��ʹ�ܿ���  
  I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL1, 0x0f);   //100Hz, 0:12.5 ,1:25 ,2:25 ,3:25
  //I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL1, 0x8f);   //400Hz, 0:20 ,1:25 ,2:50 ,3:110
  //I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL1, 0xCf);   //800Hz, 0:30 ,1:35 ,2:50 ,3:110
  
  //��ͨ����
  I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL2, 0x00); //100hzʹ��,��ͨ1Hz
  //I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL2, 0x03); //100hzʹ��,��ͨ1Hz
  //I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL2, 0x05); //400hzʹ��,��ͨ1Hz
  //I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL2, 0x05); //800hzʹ��,��ͨ1Hz
  
  //����ź���������
  //I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL3, 0xA8); //DRDY����,IDLE:0,
  I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL3, 0x08);
  
  //��������, ���ݸ��·�ʽ
  I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL4, 0x30|(0<<7)); //+-2000dps, 1:ʹ������,0:��ʵ����xyz
  
  //�ߵ�ͨ�˲�ѡ��
  I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL5, 0x00); //ֻʹ��ԭʼ��ͨLPF1
  //I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL5, 0x05); //ֻʹ��LPF1+HPF
  //I2C_WriteByte(I2C_L3G4200_ADDR, REG_L3G4200_CTRL5, 0x0F|(1<<4)); //ʹ����LPF1+LPF2,bit�����Ƿ�ʹ��HPF
  delay(500);
}

void L3G4200_MultiRead(short* x, short* y, short* z)
{
  byte ReadBuffer[6];
  I2C_RandomRead(I2C_L3G4200_ADDR, REG_L3G4200_MULREAD, ReadBuffer, 6);
  *x = (ReadBuffer[1]<<8) + ReadBuffer[0];
  *y = (ReadBuffer[3]<<8) + ReadBuffer[2];
  *z = (ReadBuffer[5]<<8) + ReadBuffer[4];
}

//Angular Acceleration in 0.1dps(Degree per Second)
void L3G4200_GetAngAcc(int* x, int* y, int* z)
{
  short tmpx, tmpy, tmpz;
  L3G4200_MultiRead(&tmpx, &tmpy, &tmpz);
  *x = (int)tmpx * 7 / 10;
  *y = (int)tmpy * 7 / 10;
  *z = (int)tmpz * 7 / 10;
}

//��ʼ�����ò���
void setup()
{
  Wire.begin();
  printf("Init L3G4200D...\n");
  L3G4200_Init();
}

//ѭ��ִ�в���
void loop()
{
  int accX, accY, accZ;
  L3G4200_GetAngAcc(&accX, &accY, &accZ);
  printf("Acceleration Data: X=%ddps, Y=%ddps, Z=%ddps\n", accX/10, accY/10, accZ/10);
  delay(500);
}
