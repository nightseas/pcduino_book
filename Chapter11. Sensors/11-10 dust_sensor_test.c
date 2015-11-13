/********************************************
�������ƣ�dust_sensor_test
���ܣ�Dust Sensorģ��ʹ�÷�������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
#define SAMPLE_TIME   30000   //30s����ʱ��

int sensorPin = 8;            //Dust Sensor���������GPIO8

unsigned long lowPulseTime;
unsigned long sampleStartTime;
float lowPulseRatio;
float dustConcentration;

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(sensorPin,INPUT);
}

//ѭ��ִ�в���
void loop()
{
  lowPulseTime = 0;
  sampleStartTime = millis(); //��ȡ��������ʱ��
  
  //����30s��������¼�͵�ƽʱ��֮��
  while((millis() - sampleStartTime) < SAMPLE_TIME)
  {
    lowPulseTime += pulseIn(sensorPin, LOW, 1000000);
  }
  
  //����͵�ƽʱ��Ⱥ͹��������Ũ��
  lowPulseRatio = lowPulseTime / SAMPLE_TIME / 1000.0 * 100.0; //����ɰٷֱ�
  dustConcentration = 1.1 * pow(lowPulseRatio, 3) - 3.8 * pow(lowPulseRatio, 2) + 520 * lowPulseRatio + 0.62;
  
  printf("lowPulseTime = %ldus, lowPulseRatio = %f\%, dustConcentration = %f\n", lowPulseTime, lowPulseRatio, dustConcentration);
}
