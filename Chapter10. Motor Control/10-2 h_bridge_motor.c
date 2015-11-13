/********************************************
�������ƣ�h_bridge_motor
���ܣ�H������ֱ�����
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
//������
#define FORWARD   0
#define BACKWARD  1
#define LEFT      2
#define RIGHT     4

//�����ź����Ŷ���
int pinInA1 = 8;
int pinInA2 = 11;
int pinEnA = 9;
int pinInB1 = 12;
int pinInB2 = 13;
int pinEnB = 10;


//���ܺ�������
//�����������ר�����С������
void motorSetDirection(int method)
{
  switch(method)
  {
    //ǰ��
    case FORWARD:
      digitalWrite(pinInA1, HIGH);
      digitalWrite(pinInA2, LOW);
      digitalWrite(pinInB1, LOW);
      digitalWrite(pinInB2, HIGH);
      break;
      
    //����
    case BACKWARD:
      digitalWrite(pinInA1, LOW);
      digitalWrite(pinInA2, HIGH);
      digitalWrite(pinInB1, HIGH);
      digitalWrite(pinInB2, LOW);
      break;
      
    //��ת
    case LEFT:
      digitalWrite(pinInA1, LOW);
      digitalWrite(pinInA2, HIGH);
      digitalWrite(pinInB1, LOW);
      digitalWrite(pinInB2, HIGH);
      break;
      
    //��ת
    case RIGHT:
      digitalWrite(pinInA1, HIGH);
      digitalWrite(pinInA2, LOW);
      digitalWrite(pinInB1, HIGH);
      digitalWrite(pinInB2, LOW);
      break;
      
    default:
      digitalWrite(pinInA1, LOW);
      digitalWrite(pinInA2, LOW);
      digitalWrite(pinInB1, LOW);
      digitalWrite(pinInB2, LOW);
      break;
  }
}

//ͨ��PWMռ�ձ����õ��ת��
void motorSetSpeed(int spead)
{
  analogWrite(pinEnA, spead);
  analogWrite(pinEnB, spead);
}

//��ʼ�����ò���
void setup()
{
  pinMode(pinInA1, OUTPUT);
  pinMode(pinInA2, OUTPUT);
  pinMode(pinInB1, OUTPUT);
  pinMode(pinInB2, OUTPUT);
  pinMode(pinEnA, OUTPUT);
  pinMode(pinEnB, OUTPUT);
}

//ѭ��ִ�в���
void loop()
{
  //����С���ٶ�
  motorSetSpeed(120); 
  
  //ѭ��ִ���˶�ָ��
  motorSetDirection(FORWARD);
  delay(3000);
  motorSetDirection(BACKWARD);
  delay(3000);
  motorSetDirection(LEFT);
  delay(3000);
  motorSetDirection(RIGHT);
  delay(3000);
}