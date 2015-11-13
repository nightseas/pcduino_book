/********************************************
�������ƣ�ultrasonic_test
���ܣ�������ģ�鷶������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
//�������͵�ģ�����ӵ�GPIO
//TRIG -- GPIO2
//ECHO -- GPIO3
int trigPin = 2;
int echoPin = 3;

//���ܺ�������
//���ز�����ʱ��ת���ɾ��룬��λ��Ӣ��
long microsecondsToInches(long microseconds)
{
  return (microseconds / 74 / 2);
}

//���ز�����ʱ��ת���ɾ��룬��λ������
long microsecondsToCentimeters(long microseconds)
{
  return (microseconds / 29 / 2);
}

//��ʼ�����ò���
void setup()
{
  //ECHO����Ϊ���룬���ڼ��ز�
  pinMode(echoPin,INPUT);
  //TRIG����Ϊ��������ڴ���ģ�鷢�䳬����
  pinMode(trigPin,OUTPUT);
  digitalWrite(trigPin,LOW);
  delay(100);
}

//ѭ��ִ�в���
void loop()
{
  long duration, inches, cm;
  
  //����20us�ߵ�ƽ����
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  
  //���ջز�����������ʱ��
  duration = pulseIn(echoPin, HIGH, 1000000);
  //���ز�����ת�����뱻�������ľ��벢��ʾ
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);  
  printf("Distance=%ldcm (%ldinches)\n", cm, inches);
  delay(1000);
}