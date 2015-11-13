/********************************************
�������ƣ�servo_test
���ܣ�������Ʒ�������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
#define PWM_PERIOD  20000 //PWM����Ϊ20ms��20000us��
int servoPin = 0;

//���ܺ�������
//���øߵ�ƽʱ�䣬��Χ��1000-2000us
void servoSetPulse(int pin, int pulse)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(pin, LOW);
  delayMicroseconds(PWM_PERIOD - pulse);
}

//���ö��ת���Ƕȣ���Χ0-180��
void servoSetAngle(int pin, int angle)
{
  if(angle >= 0 && angle <= 180)
    servoSetPulse(pin, angle*11+1000);
}

//��ʼ�����ò���
void setup()
{
  pinMode(servoPin,OUTPUT);
}

//ѭ��ִ�в���
void loop()
{
  //0-180��֮��ѭ��ת�����
  for(int i=0;i<=180;i++)
  {
    servoSetAngle(servoPin, i);
  }
  for(int i=180;i>=0;i--)
  {
    servoSetAngle(servoPin, i);
  }
}