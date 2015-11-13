/********************************************
�������ƣ�gas_sensor_test
���ܣ����崫������������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int gasSensorPin = 0; //���崫��������ģ������A0
int ledPin = 13;      //LED����GPIO13

int gasData = 0;

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(ledPin, OUTPUT);
}

//ѭ��ִ�в���
void loop()
{  
  gasData = analogRead(gasSensorPin);
  //������Ũ�ȳ�����ֵ������LED
  if(gasData > 45)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
  printf("Gas sensor data: %d\n", gasData);
  delay(500);
}