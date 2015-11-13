/********************************************
程序名称：spi_flash_test
功能：pcDuino使用SPI接口操作Flash范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <stdio.h>
#include <string.h>
#include <core.h>
#include "SPI.h"

//宏定义及全局变量

//功能函数部分
int spiFlashReadID(void)
{
  char CMD_RDID = 0x9f;
  char id[3];
  int flashid = 0;

  memset(id, 0x0, sizeof(id));

  //写入读Flash ID指令，连续读取3个字节数据
  SPI.transfer(CMD_RDID, SPI_CONTINUE);
  id[0] = SPI.transfer(0x00, SPI_CONTINUE);
  id[1] = SPI.transfer(0x00, SPI_CONTINUE);
  id[2] = SPI.transfer(0x00, SPI_LAST); //SPI_LAST表示最后1字节

  //将3字节Flash ID合并，高位在前 
  flashid = id[0] << 8;
  flashid |= id[1];
  flashid = flashid << 8;
  flashid |= id[2];

  return flashid;
}

//初始化设置部分
void setup()
{
    //初始化SPI接口
    SPI.begin(); 
    SPI.setDataMode(SPI_MODE3); //CPOL=1, CPHA=1
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV16); //SPI时钟为16分频时钟，750KHz
}

//循环执行部分
void loop()
{
    printf("SPI Flash ID = 0x%x\n", spiFlashReadID());
    delay(2000);
}
