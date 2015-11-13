/********************************************
程序名称：nfc_shield_test
功能：NFC Shield范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>
#include "SPI.h"
#include "PN532.h"

//宏定义及全局变量
//定义与NFC Shield连接的SPI引脚
int spiSckPin   = 13;
int spiMosiPin  = 11;
int spiSsPin    = 10;
int spiMisoPin  = 12;

PN532 nfc(spiSckPin, spiMisoPin, spiMosiPin, spiSsPin);

//功能函数部分

//初始化设置部分
void setup()
{
  unsigned int nfcVersion;
  //初始化NFC Shield
  nfc.begin();
  
  //获取NFC Shield固件版本
  nfcVersion = nfc.getFirmwareVersion();
  
  //未读到有效的版本则程序停止运行
  if (nfcVersion == 0)
  {
    printf("NFC Shield not connected!\n");
    while(1);
  }
  
  //打印版本信息
  printf("Found NFC Shield with PN5%x\n", (nfcVersion>>24) & 0xFF);
  printf("Firmware version: %d.%d", (nfcVersion>>16) & 0xFF, (nfcVersion>>8) & 0xFF);
  printf("Supports: ", nfcVersion & 0xFF);

  //配置NFC Shield，准备读取RFID卡
  nfc.SAMConfig();
}

//循环执行部分
void loop()
{
  unsigned cardId;
  
  //查找MIFARE型RFID卡并读取ID
  cardId = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A);

  if (cardId != 0)
  {
    printf("Card ID:0x%x\n", cardId);
  }
}