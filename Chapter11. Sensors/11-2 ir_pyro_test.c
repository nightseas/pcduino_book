/********************************************
�������ƣ�ir_pyro_test
���ܣ��������͵�ģ�鷶������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>
#include <time.h>

//�궨�弰ȫ�ֱ���
#define INT_MODE  RISING //�ж�ģʽ���������ж�

time_t now;               //ʵ����time_t�ṹ
struct tm *timenow;      //ʵ����tm�ṹָ��

//���ܺ�������
//���͵紫�����ж�ִ�к���
void pyroDetect(void)
{
  //��ȡ����ʱ��
  time(&now);
  timenow = localtime(&now);
  printf("Human body detected! Time: %s\n", asctime(timenow));  
}

//��ʼ�����ò���
void setup()
{
  //��GPIO2��Ϊ�ж��������ţ��ж�ִ�к���ΪpyroDetect
  attachInterrupt(0, pyroDetect, INT_MODE);
}

//ѭ��ִ�в���
void loop()
{
}