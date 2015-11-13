/********************************************
程序名称：adc_keypad_test
功能：ADC按键范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
#define BTN_NUM 5
int adcButtonVal[5] ={50, 200, 400, 600, 800};//存放按键对应的ADC采样值
char buttonName[5][10] = {"RIGHT", //按键名称
                          "UP",               
                          "DOWN",
                          "LEFT",
                          "SELECT"};
int buttonStatus;

//功能函数部分
//将ADC数据转换成按键编号
int getButton(unsigned int adcInput)
{
    int i;
    for (i=0;i<BTN_NUM;i++)
    {
      if(adcInput<adcButtonVal[i])
      {
        return i;
      }
    } 
    return -1;
}

//初始化设置部分
void setup()
{
}

//循环执行部分
void loop()
{
  buttonStatus = getButton(analogRead(0)); //读取按键状态
  if(buttonStatus != -1) //如果有按键按下，打印按键名称
    printf("Button %s pressed!\n",buttonName[buttonStatus]);
  delay(50);
}