/********************************************
�������ƣ�turn_off_light
���ܣ�Ϊ���������ṩ�صƹ���
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int ctrlPin = 13; //GPIO13����LED

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(ctrlPin, OUTPUT);
  digitalWrite(ctrlPin, LOW); //�ر�LED
  exit(0); //�˳�����
}

//ѭ��ִ�в���
void loop()
{
}
