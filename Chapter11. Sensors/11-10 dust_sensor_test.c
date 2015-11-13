/********************************************
程序名称：dust_sensor_test
功能：Dust Sensor模块使用范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
#define SAMPLE_TIME   30000   //30s采样时间

int sensorPin = 8;            //Dust Sensor输出端连接GPIO8

unsigned long lowPulseTime;
unsigned long sampleStartTime;
float lowPulseRatio;
float dustConcentration;

//功能函数部分

//初始化设置部分
void setup()
{
  pinMode(sensorPin,INPUT);
}

//循环执行部分
void loop()
{
  lowPulseTime = 0;
  sampleStartTime = millis(); //获取采样启动时间
  
  //进行30s采样，记录低电平时间之和
  while((millis() - sampleStartTime) < SAMPLE_TIME)
  {
    lowPulseTime += pulseIn(sensorPin, LOW, 1000000);
  }
  
  //计算低电平时间比和固体颗粒物浓度
  lowPulseRatio = lowPulseTime / SAMPLE_TIME / 1000.0 * 100.0; //换算成百分比
  dustConcentration = 1.1 * pow(lowPulseRatio, 3) - 3.8 * pow(lowPulseRatio, 2) + 520 * lowPulseRatio + 0.62;
  
  printf("lowPulseTime = %ldus, lowPulseRatio = %f\%, dustConcentration = %f\n", lowPulseTime, lowPulseRatio, dustConcentration);
}
