/********************************************
�������ƣ�high_power_drive
���ܣ�������������������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int ctrlPin = 13; //GPIO13���������ܿ�������

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(ctrlPin, OUTPUT);
}

//ѭ��ִ�в���
void loop()
{
  digitalWrite(ctrlPin, HIGH); //�ߵ�ƽ�����ܵ�ͨ
  delay(1000);
  digitalWrite(ctrlPin, LOW);
  delay(1000);
}
