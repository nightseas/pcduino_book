/********************************************
�������ƣ�lcd1602_test
���ܣ�LCD1602ʹ�÷�������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>
#include <LiquidCrystal.h> //LiquidCrystal��ͷ�ļ�

//�궨�弰ȫ�ֱ���
//ͨ��LiquidCrystal�ඨ��LCD����(4-Bitģʽ)����Ӧ��ʽ���£�
//LCD RS -- GPIO8
//LCD EN -- GPIO9
//LCD D4 -- GPIO4
//LCD D5 -- GPIO5
//LCD D6 -- GPIO6
//LCD D7 -- GPIO7
LiquidCrystal lcd1602( 8, 9, 4, 5, 6, 7 ); 

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  //��ʼ��1602LCD
  lcd1602.begin(16, 2);
  //��LCD�ϴ�ӡ��Ϣ
  lcd1602.print("Hello pcDuino!");
}

//ѭ��ִ�в���
void loop()
{
  lcd1602.setCursor(0, 1);      //���ù��λ������2�У���1��
  lcd1602.print(millis()/1000); //��ӡ��������ʱ��
}