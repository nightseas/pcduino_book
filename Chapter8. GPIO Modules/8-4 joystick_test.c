/********************************************
�������ƣ�joystick_test
���ܣ�Joystick��������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int valX, valY;

//���ܺ�������


//��ʼ�����ò���
void setup()
{
}

//ѭ��ִ�в���
void loop()
{
  valX = analogRead(0); //ͨ��ADC0��ȡX������ֵ
  valY = analogRead(1); //ͨ��ADC1��ȡY������ֵ
  printf("JoyStick_X=%d, JoyStick_Y=%d\n", valX, valY);
  delay(800);
}
