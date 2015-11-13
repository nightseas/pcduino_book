/********************************************
�������ƣ�ext_interrupt_test
���ܣ�pcDuinoͨ���ⲿ�жϷ�ʽ��ⰴ����������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
#define INT_MODE    RISING//�ж�ģʽ���������ж�
int cntButton1 = 0, cntButton2 = 0;

//���ܺ�������
//����1�ж�ִ�к���
void button1Pressed()
{
  cntButton1++; 
  printf("Button1 pressed %d time(s).\n", cntButton1);  
}

//����2�ж�ִ�к���
void button2Pressed()
{
  cntButton2++;
  printf("Button2 pressed %d time(s).\n", cntButton2); 
}

//��ʼ�����ò���
void setup()
{
  //��GPIO2(INT0)��GPIO3(INT1)��Ϊ�ж��������ţ��ж�ִ�к����ֱ�Ϊbutton1Pressed��button2Pressed
  printf("Attaching interrupt pins.\n");
  attachInterrupt(0, button1Pressed, INT_MODE);
  attachInterrupt(1, button2Pressed, INT_MODE);
}

//ѭ��ִ�в���
void loop()
{
}