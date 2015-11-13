/********************************************
�������ƣ�nfc_shield_test
���ܣ�NFC Shield��������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>
#include "SPI.h"
#include "PN532.h"

//�궨�弰ȫ�ֱ���
//������NFC Shield���ӵ�SPI����
int spiSckPin   = 13;
int spiMosiPin  = 11;
int spiSsPin    = 10;
int spiMisoPin  = 12;

PN532 nfc(spiSckPin, spiMisoPin, spiMosiPin, spiSsPin);

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  unsigned int nfcVersion;
  //��ʼ��NFC Shield
  nfc.begin();
  
  //��ȡNFC Shield�̼��汾
  nfcVersion = nfc.getFirmwareVersion();
  
  //δ������Ч�İ汾�����ֹͣ����
  if (nfcVersion == 0)
  {
    printf("NFC Shield not connected!\n");
    while(1);
  }
  
  //��ӡ�汾��Ϣ
  printf("Found NFC Shield with PN5%x\n", (nfcVersion>>24) & 0xFF);
  printf("Firmware version: %d.%d", (nfcVersion>>16) & 0xFF, (nfcVersion>>8) & 0xFF);
  printf("Supports: ", nfcVersion & 0xFF);

  //����NFC Shield��׼����ȡRFID��
  nfc.SAMConfig();
}

//ѭ��ִ�в���
void loop()
{
  unsigned cardId;
  
  //����MIFARE��RFID������ȡID
  cardId = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A);

  if (cardId != 0)
  {
    printf("Card ID:0x%x\n", cardId);
  }
}