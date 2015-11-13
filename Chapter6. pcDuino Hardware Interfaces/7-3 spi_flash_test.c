/********************************************
�������ƣ�spi_flash_test
���ܣ�pcDuinoʹ��SPI�ӿڲ���Flash��������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <core.h>
#include "SPI.h"

//�궨�弰ȫ�ֱ���

//���ܺ�������
int spiFlashReadID(void)
{
  char CMD_RDID = 0x9f;
  char id[3];
  int flashid = 0;

  memset(id, 0x0, sizeof(id));

  //д���Flash IDָ�������ȡ3���ֽ�����
  SPI.transfer(CMD_RDID, SPI_CONTINUE);
  id[0] = SPI.transfer(0x00, SPI_CONTINUE);
  id[1] = SPI.transfer(0x00, SPI_CONTINUE);
  id[2] = SPI.transfer(0x00, SPI_LAST); //SPI_LAST��ʾ���1�ֽ�

  //��3�ֽ�Flash ID�ϲ�����λ��ǰ 
  flashid = id[0] << 8;
  flashid |= id[1];
  flashid = flashid << 8;
  flashid |= id[2];

  return flashid;
}

//��ʼ�����ò���
void setup()
{
    //��ʼ��SPI�ӿ�
    SPI.begin(); 
    SPI.setDataMode(SPI_MODE3); //CPOL=1, CPHA=1
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV16); //SPIʱ��Ϊ16��Ƶʱ�ӣ�750KHz
}

//ѭ��ִ�в���
void loop()
{
    printf("SPI Flash ID = 0x%x\n", spiFlashReadID());
    delay(2000);
}
