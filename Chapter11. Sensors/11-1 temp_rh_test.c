/********************************************
程序名称：temp_rh_test
功能：DHT11温湿度传感器范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>
#include "dht11.h"

//宏定义及全局变量
dht11 DHT11;
int pinDHT11 = 2; //DHT11数据端连接GPIO2
int checkSum;     //DHT11数据校验和

//功能函数部分

//初始化设置部分
void setup()
{
}

//循环执行部分
void loop()
{
  //读取DHT11数据及校验和
  printf("\nReading data from DHT11...\n");
  checkSum = DHT11.read(pinDHT11);
  
  //判断校验和
  switch (checkSum)
  {
    case DHTLIB_OK: 
      printf("Correct checksum.\n"); 
      break;
    case DHTLIB_ERROR_CHECKSUM: 
      printf("Incorrect checksum！\n"); 
      break;
    case DHTLIB_ERROR_TIMEOUT: 
      printf("Timeout error！\n");  
      break;
    default: 
      printf("Unknown error!\n"); 
      break;
  }
  
  //校验和正确，显示数据
  if(checkSum == DHTLIB_OK)
  {
    printf("Humidity: %.1f, Temperature: %.1f\n", (float)DHT11.humidity, (float)DHT11.temperature);
  }
  delay(3000);
}