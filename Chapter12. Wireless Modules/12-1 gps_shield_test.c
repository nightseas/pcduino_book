/********************************************
�������ƣ�gps_shield_test
���ܣ�GPS Sheild��������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  //��ʼ������GPS�Ĵ���
  Serial.begin(9600); 
  while(!Serial); //�ȴ�����׼����
}

//ѭ��ִ�в���
void loop()
{
  //���Ӵ��ڽ��յ���GPS���ݴ�ӡ����Ļ��
  if(Serial.available() > 0) 
  {
    printf("%c", char(Serial.read()));
    fflush(stdout);
  }
}