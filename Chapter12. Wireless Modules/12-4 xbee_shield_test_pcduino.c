/********************************************
�������ƣ�xbee_shield_test_pcduino
���ܣ�XBeeģ�鷶�����루pcDuino�ˣ�
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int ledPin    = 9;  //LED����Arduino D9
int buttonPin = 10; //��������Arduino D10
int ledOnFlag = 0;

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  digitalWrite(ledPin,HIGH);
  Serial.begin(9600);
}

//ѭ��ִ�в���
void loop()
{
    //�����������ͨ��XBeeģ�鷢���ַ�'a'
  if(digitalRead(buttonPin) == LOW)
  {
    //��ʱ10ms������������
    delay(10);
    if(digitalRead(buttonPin) == LOW)
    {
      Serial.print('b');
      delay(200);
    } 
  }
  
  //������յ�XBeeģ�鷢�����ַ�'a'��LED��˸
  if (Serial.available() > 0)
  {
    byte dataRead;
    dataRead = Serial.read();
    if(dataRead == 'a')
    {
      printf("The data received is %c\n", (char)dataRead);
      if(ledOnFlag == 1)
      {
        printf("led off\n");
        digitalWrite(ledPin,HIGH);
        ledOnFlag = 0;
      }
      else
      {
        printf("led on\n");
        digitalWrite(ledPin,LOW);
        ledOnFlag = 1;
      }      
    }
  }
}