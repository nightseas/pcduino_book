/********************************************
程序名称：h_bridge_motor
功能：H桥驱动直流电机
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
//方向定义
#define FORWARD   0
#define BACKWARD  1
#define LEFT      2
#define RIGHT     4

//控制信号引脚定义
int pinInA1 = 8;
int pinInA2 = 11;
int pinEnA = 9;
int pinInB1 = 12;
int pinInB2 = 13;
int pinEnB = 10;


//功能函数部分
//设置两个电机专项控制小车方向
void motorSetDirection(int method)
{
  switch(method)
  {
    //前进
    case FORWARD:
      digitalWrite(pinInA1, HIGH);
      digitalWrite(pinInA2, LOW);
      digitalWrite(pinInB1, LOW);
      digitalWrite(pinInB2, HIGH);
      break;
      
    //后退
    case BACKWARD:
      digitalWrite(pinInA1, LOW);
      digitalWrite(pinInA2, HIGH);
      digitalWrite(pinInB1, HIGH);
      digitalWrite(pinInB2, LOW);
      break;
      
    //左转
    case LEFT:
      digitalWrite(pinInA1, LOW);
      digitalWrite(pinInA2, HIGH);
      digitalWrite(pinInB1, LOW);
      digitalWrite(pinInB2, HIGH);
      break;
      
    //右转
    case RIGHT:
      digitalWrite(pinInA1, HIGH);
      digitalWrite(pinInA2, LOW);
      digitalWrite(pinInB1, HIGH);
      digitalWrite(pinInB2, LOW);
      break;
      
    default:
      digitalWrite(pinInA1, LOW);
      digitalWrite(pinInA2, LOW);
      digitalWrite(pinInB1, LOW);
      digitalWrite(pinInB2, LOW);
      break;
  }
}

//通过PWM占空比设置电机转速
void motorSetSpeed(int spead)
{
  analogWrite(pinEnA, spead);
  analogWrite(pinEnB, spead);
}

//初始化设置部分
void setup()
{
  pinMode(pinInA1, OUTPUT);
  pinMode(pinInA2, OUTPUT);
  pinMode(pinInB1, OUTPUT);
  pinMode(pinInB2, OUTPUT);
  pinMode(pinEnA, OUTPUT);
  pinMode(pinEnB, OUTPUT);
}

//循环执行部分
void loop()
{
  //设置小车速度
  motorSetSpeed(120); 
  
  //循环执行运动指令
  motorSetDirection(FORWARD);
  delay(3000);
  motorSetDirection(BACKWARD);
  delay(3000);
  motorSetDirection(LEFT);
  delay(3000);
  motorSetDirection(RIGHT);
  delay(3000);
}