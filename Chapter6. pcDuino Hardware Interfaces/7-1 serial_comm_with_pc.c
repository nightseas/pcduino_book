/********************************************
�������ƣ�serial_comm_with_pc
���ܣ�pcDuinoʹ��UART�ӿ���PC��ͨ�ŷ�������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
byte readByte;

//��ʼ�����ò���
void setup() {
  Serial.begin(115200, SERIAL_8N1); //���ô��ڲ�����Ϊ115200��8λ����λ����У��λ��1λֹͣλ
  while(!Serial); //�ȴ�����׼����
  Serial.println("Hello pcDuino!"); //��ӡһ���ַ���
}

//ѭ��ִ�в���
void loop() {
  if(Serial.available() > 0)
  {
    readByte = Serial.read(); //��ȡһ���ֽ�����
    Serial.write(readByte); //����ȡ����������ͨ�����ڷ���PC
  }
}
