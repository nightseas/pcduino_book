/********************************************
�������ƣ�seg7_test
���ܣ��߶�����ܷ�������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
//GPIO����������ӹ�ϵ����
//a -- GPIO0
//b -- GPIO3
//c -- GPIO2
//d -- GPIO4
//e -- GPIO5
//f -- GPIO8
//g -- GPIO7
//dp -- GPIO1
#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define dp 7

//���ֶ����
int segTable[10] =  {1<<a | 1<<b | 1<<c | 1<<d | 1<<e | 1<<f,        //����0
                     1<<b | 1<<c,                                    //����1
                     1<<a | 1<<b | 1<<d | 1<<e | 1<<g,               //����2
                     1<<a | 1<<b | 1<<c | 1<<d | 1<<g,               //����3
                     1<<b | 1<<c | 1<<f | 1<<g,                      //����4
                     1<<a | 1<<c | 1<<d | 1<<f | 1<<g,               //����5
                     1<<a | 1<<c | 1<<d | 1<<e | 1<<f | 1<<g,        //����6
                     1<<a | 1<<b | 1<<c,                             //����7
                     1<<a | 1<<b | 1<<c | 1<<d | 1<<e | 1<<f | 1<<g, //����8
                     1<<a | 1<<b | 1<<c | 1<<d | 1<<f | 1<<g};       //����9

//���ܺ�������
//��ʾ����
void displayNumber(int numMask)
{
  for(int i=0;i<=8;i++)
  {
    if((segTable[numMask]>>i)&0x1)
      digitalWrite(i, LOW); //�����������ָ���Ķ�
    else
      digitalWrite(i, HIGH); //������Ϩ��
  }
}

//��ʼ�����ò���
void setup()
{
  for(int i=0;i<=8;i++)
    pinMode(i,OUTPUT);  //����GPIO0-GPIO8Ϊ���
}

//ѭ��ִ�в���
void loop()
{
  //ѭ����ʾ����0-9
  for(int i=0;i<=9;i++)
  {
    printf("seg[%d]=0x%03x\n", i, segTable[i]);
    displayNumber(i);
    delay(1000);
  }
}