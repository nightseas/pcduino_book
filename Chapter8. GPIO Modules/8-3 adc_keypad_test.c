/********************************************
�������ƣ�adc_keypad_test
���ܣ�ADC������������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
#define BTN_NUM 5
int adcButtonVal[5] ={50, 200, 400, 600, 800};//��Ű�����Ӧ��ADC����ֵ
char buttonName[5][10] = {"RIGHT", //��������
                          "UP",               
                          "DOWN",
                          "LEFT",
                          "SELECT"};
int buttonStatus;

//���ܺ�������
//��ADC����ת���ɰ������
int getButton(unsigned int adcInput)
{
    int i;
    for (i=0;i<BTN_NUM;i++)
    {
      if(adcInput<adcButtonVal[i])
      {
        return i;
      }
    } 
    return -1;
}

//��ʼ�����ò���
void setup()
{
}

//ѭ��ִ�в���
void loop()
{
  buttonStatus = getButton(analogRead(0)); //��ȡ����״̬
  if(buttonStatus != -1) //����а������£���ӡ��������
    printf("Button %s pressed!\n",buttonName[buttonStatus]);
  delay(50);
}