/********************************************
�������ƣ�tilt_test
���ܣ���б����ģ�鷶������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int tiltPin = 0; //GPIO0������б���������
int tiltStatus; //���ڱ�����б����״̬

//���ܺ�������

//��ʼ�����ò���
void setup() {                
  pinMode(tiltPin , INPUT);
}

//ѭ��ִ�в���
void loop() {
  tiltStatus = digitalRead(tiltPin); //��ȡ��б����״̬
  if(tiltStatus == HIGH)
    printf("The object tilt to left side!\n");
  else
    printf("The object tilt to right side!\n");
  delay(1000);
}