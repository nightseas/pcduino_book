/********************************************
�������ƣ�cap_touch_test
���ܣ�����ʽ��������ģ�鷶������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
int TouchPin = 0; //GPIO0���Ӵ���ģ�������
int TouchStatus; //���ڱ��水��״̬

//���ܺ�������

//��ʼ�����ò���
void setup() {                
  pinMode(TouchPin , INPUT);
}

//ѭ��ִ�в���
void loop() {
  TouchStatus = digitalRead(TouchPin); //��ȡ����״̬
  if(TouchStatus == HIGH)
    printf("The key is pressed!\n");
  else
    printf("The key is released!\n");
  delay(1000);
}