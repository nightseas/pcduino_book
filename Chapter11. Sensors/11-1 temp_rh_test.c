/********************************************
�������ƣ�temp_rh_test
���ܣ�DHT11��ʪ�ȴ�������������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>
#include "dht11.h"

//�궨�弰ȫ�ֱ���
dht11 DHT11;
int pinDHT11 = 2; //DHT11���ݶ�����GPIO2
int checkSum;     //DHT11����У���

//���ܺ�������

//��ʼ�����ò���
void setup()
{
}

//ѭ��ִ�в���
void loop()
{
  //��ȡDHT11���ݼ�У���
  printf("\nReading data from DHT11...\n");
  checkSum = DHT11.read(pinDHT11);
  
  //�ж�У���
  switch (checkSum)
  {
    case DHTLIB_OK: 
      printf("Correct checksum.\n"); 
      break;
    case DHTLIB_ERROR_CHECKSUM: 
      printf("Incorrect checksum��\n"); 
      break;
    case DHTLIB_ERROR_TIMEOUT: 
      printf("Timeout error��\n");  
      break;
    default: 
      printf("Unknown error!\n"); 
      break;
  }
  
  //У�����ȷ����ʾ����
  if(checkSum == DHTLIB_OK)
  {
    printf("Humidity: %.1f, Temperature: %.1f\n", (float)DHT11.humidity, (float)DHT11.temperature);
  }
  delay(3000);
}