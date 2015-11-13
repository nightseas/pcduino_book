/********************************************
�������ƣ�pwm_led_test
���ܣ�pcDuinoʹ��PWM�ӿڿ���LED�����Ʒ�������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
#define LED_MAX_PWM   0x25  //LED������ȶ�Ӧ��PWM����
#define DELAY_TIME    700  //ÿ������ֵ������ʱ�����

int ledPin=10;//LED����GPIO10

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(ledPin, OUTPUT);
}

//ѭ��ִ�в���
void loop()
{
  //����������
  for(int i=0;i<=LED_MAX_PWM;i++)
  {
    analogWrite(ledPin, i); //����PWMռ�ձ�
    delayMicroseconds(DELAY_TIME*(LED_MAX_PWM-i));
  }
  //������˥��
  for(int i=LED_MAX_PWM;i>=0;i--)
  {
    analogWrite(ledPin, i);
    delayMicroseconds(DELAY_TIME*(LED_MAX_PWM-i));
  }
  delay(1500);
}