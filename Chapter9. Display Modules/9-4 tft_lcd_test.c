/********************************************
�������ƣ�tft_lcd_test
���ܣ�TFT LCD��������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <stdint.h>
#include <core.h>
#include <SPI.h>
#include "TFTv2.h" //TFT LCD������ͷ�ļ�

//�궨�弰ȫ�ֱ���

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  TFT_BL_ON;     //��LCD����
  Tft.TFTinit(); //��ʼ��TFT LCD��
  
  Tft.drawString("welcome",30,50,4,RED);        //��ӡ�ַ��������꣺(30,50),��С: 4����ɫ����ɫ   
  Tft.drawString("to",90,110,4,YELLOW);         //��ӡ�ַ��������꣺(90,110),��С: 4����ɫ����ɫ 
  Tft.drawString("pcDuino!",30,170,4,CYAN);     //��ӡ�ַ��������꣺(30,170),��С: 4����ɫ����ɫ   
  Tft.drawString("16/03/2013",80,280,2,WHITE);  //��ӡ�ַ��������꣺(80,280),��С: 2����ɫ����ɫ  
}

//ѭ��ִ�в���
void loop()
{   
}