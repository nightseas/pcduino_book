/********************************************
�������ƣ�relay_test
���ܣ��̵���ģ�鷶������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int relayPin = 13; //GPIO13Ϊ�̵�����������

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(relayPin, OUTPUT);
}

//ѭ��ִ�в���
void loop()
{
  digitalWrite(relayPin, HIGH); //�̵�������
  delay(1000);
  digitalWrite(relayPin, LOW);  //�̵����Ͽ�
  delay(1000);
}