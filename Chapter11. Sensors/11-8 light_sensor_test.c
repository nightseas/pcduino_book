/********************************************
�������ƣ�light_sensor_test
���ܣ����մ�������������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int lightSensorPin = 0; //���մ���������ģ������A0
int ledPin = 13;        //LED����GPIO13

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(ledPin, OUTPUT);
}

//ѭ��ִ�в���
void loop()
{
  //�����ߵ���һ���̶ȣ�����LED
  if(analogRead(lightSensorPin) < 30)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
