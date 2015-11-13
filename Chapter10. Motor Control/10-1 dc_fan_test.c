/********************************************
�������ƣ�dc_fan_test
���ܣ�ֱ�����ȿ��Ʒ�������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int fanPin=10;//GPIO10���ӷ���

//���ܺ�������
//����PWMռ�ձ�
void setDuty(int pin, int percent)
{
  int duty = percent*255/100;
  analogWrite(pin, duty);
}

//��ʼ�����ò���
void setup()
{
  pinMode(fanPin, OUTPUT);
}

//ѭ��ִ�в���
void loop()
{
  //��0-100%ѭ���ı����ռ�ձ�
  for(int i=0;i<=100;i+=10)
  {
    setDuty(fanPin, i);
    printf("Duty cycle of the fan is %d\%\n", i);
    delay(3000);
  } 
}
