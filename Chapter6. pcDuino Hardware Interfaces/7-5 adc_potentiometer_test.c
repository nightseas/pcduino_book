/********************************************
�������ƣ�adc_potentiometer_test
���ܣ�pcDuinoʹ��ADC�ӿڼ���λ��λ�÷�������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int ledPin=10;//LED����GPIO10
int adcResult;

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(ledPin, OUTPUT);
}

//ѭ��ִ�в���
void loop()
{
  //��ȡA0��ѹ����(A0Ϊ6-Bit�ֱ��ʣ�ֵ��0-63)
  adcResult = analogRead(A0);
  //ͨ������ռ�ձȵ���
  analogWrite(ledPin, adcResult);
  delay(10);
}