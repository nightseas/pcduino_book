/********************************************
�������ƣ�stepper_test
���ܣ��������������������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
//���������������ӵ�GPIO
//A -- GPIO0
//B -- GPIO1
//C -- GPIO2
//D -- GPIO3
int pinA = 0;
int pinB = 1;
int pinC = 2;
int pinD = 3;

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
}

//ѭ��ִ�в���
void loop()
{
  //˫��������    
  digitalWrite(pinA,1);
  digitalWrite(pinB,0);
  digitalWrite(pinC,0);
  digitalWrite(pinD,1);
  delay(2);
  digitalWrite(pinA,1);
  digitalWrite(pinB,1);
  digitalWrite(pinC,0);
  digitalWrite(pinD,0);
  delay(2);
  digitalWrite(pinA,0);
  digitalWrite(pinB,1);
  digitalWrite(pinC,1);
  digitalWrite(pinD,0);
  delay(2);
  digitalWrite(pinA,0);
  digitalWrite(pinB,0);
  digitalWrite(pinC,1);
  digitalWrite(pinD,1);
  delay(2);
}