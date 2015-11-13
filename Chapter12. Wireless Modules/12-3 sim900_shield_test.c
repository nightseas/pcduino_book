/********************************************
�������ƣ�sim900_shield_test
���ܣ�SIM900 Shield��������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>
#include "Serial.h"

//�궨�弰ȫ�ֱ���
//����LED���������ӵ�GPIO
//���Ű��� -- GPIO2
//�Ҷϰ��� -- GPIO3
//״̬LED  -- GPIO4
int buttonPin1  = 2;
int buttonPin2  = 3;
int ledPin      = 4;
//���ܺ�������

//��ʼ�����ò���
void setup()
{
  //��ʼ��GPIO
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  pinMode(ledPin,OUTPUT);
  //��ʼ������
  Serial.begin(19200);
  while(!Serial);
}

//ѭ��ִ�в���
void loop()
{
  int buttonStatus1 = digitalRead(buttonPin1);
  int buttonStatus2 = digitalRead(buttonPin2);
  
  digitalWrite(ledPin,LOW);
  delay(200);
  digitalWrite(ledPin,HIGH);
  delay(200);
  
  //����1���£������ƶ�����
  if(buttonStatus1)
  {
    delay(5);
    buttonStatus1 = digitalRead(buttonPin1);
    if(buttonStatus1)
    {
     //ATDָ��+�����롱�����ƶ����룬�˴�����Ϊ�鹹
     Serial.println("ATD + +8618612345678;");
     digitalWrite(ledPin, HIGH);
     
     //��ⰴ��2�Ƿ��£�������Ҷ�
     do{ 
        buttonStatus2 = digitalRead(buttonPin2);
        //ͨ����ʱ10ms������������
        if(buttonStatus2)
        {
          delay(10);
          buttonStatus2 = digitalRead(buttonPin2);
        }
     }while(!buttonStatus2);
     
     //ATHָ��Ҷ�
     Serial.println("ATH");
     digitalWrite(ledPin, LOW);
     delay(2000);
    }
  }
}
