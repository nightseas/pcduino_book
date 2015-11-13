/********************************************
�������ƣ�i2c_rtc_test
���ܣ�pcDuinoʹ��I2C�ӿڲ���DS1307��������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>
#include "Wire.h"

//�궨�弰ȫ�ֱ���
#define  DS1307_ADDR    0x68 //DS1307��7-Bit I2C�豸��ַ

//���ܺ�������
byte DEC2BCD(byte val) //����ת����BCD��
{
   return ( (val/10*16) + (val%10) );
}

byte BCD2DEC(byte val) //BCD��ת��������
{
  return ( (val/16*10) + (val%16) );
}

//����RTCʱ��
void rtcSetTime(byte year, byte month, byte date, byte dayofWeek, byte hour, byte min ,byte sec)
{
  byte reg = 0x00;
  //��ʼI2Cͨ��
  Wire.beginTransmission(DS1307_ADDR);  
  //�Ĵ�����ַ���ӼĴ���0��ʼд�룬ÿдһ�ֽ����ݼĴ�����ַ�Զ�����
  Wire.write(reg); 
  //д������
  Wire.write(DEC2BCD(sec));
  Wire.write(DEC2BCD(min));
  Wire.write(DEC2BCD(hour));
  Wire.write(DEC2BCD(dayofWeek));
  Wire.write(DEC2BCD(date));
  Wire.write(DEC2BCD(month));
  Wire.write(DEC2BCD(year));
  //I2Cͨ�Ž���
  Wire.endTransmission();     
}

//��ȡ����ӡRTCʱ��
void rtcGetTime() 
{
  byte year, month, date, dayofWeek, hour, min ,sec;
  byte reg = 0x00;
  //��ʼI2Cͨ��
  Wire.beginTransmission(DS1307_ADDR);
  //�Ĵ�����ַ���ӼĴ���0��ʼ��ȡ
  Wire.write(reg);
  Wire.endTransmission();
  //������ȡ7�ֽ�����
  Wire.requestFrom(DS1307_ADDR, 7);

  sec       = BCD2DEC(Wire.read() & 0x7f);  //ȥ�����λ������λ��
  min       = BCD2DEC(Wire.read());
  hour      = BCD2DEC(Wire.read() & 0x3f);  //24Сʱ��ʱ��
  dayofWeek = BCD2DEC(Wire.read());
  date      = BCD2DEC(Wire.read());
  month     = BCD2DEC(Wire.read());
  year      = BCD2DEC(Wire.read());

  printf("Time: %d-%d-%d  %d:%d:%d.\n", year, month, date, hour, min ,sec);
}

//��ʼ�����ò���
void setup()
{
  Wire.begin();
  //��ʼ��RTCʱ��
  printf("Writing time 2013-12-01 Sundy 21:10:00 to RTC...\n");
  rtcSetTime(13,12,1,7,21,10,0);
}

//ѭ��ִ�в���
void loop()
{
  //ÿ���ȡһ��RTCʱ��
  rtcGetTime();
  delay(1000);
}