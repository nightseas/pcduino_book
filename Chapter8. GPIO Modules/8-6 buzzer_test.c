/********************************************
程序名称：buzzer_test
功能：蜂鸣器播放乐曲范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
//包含头文件
#include <core.h>

//宏定义及全局变量
#define NOTE_LEN   15 //乐曲音符个数
char notes[50] = "ccggaagffeeddc "; //《小星星》乐谱
int beats[50] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 }; //每个音符所占节拍
int tempo = 300;

int buzzerPin1 = 1; //GPIO1连接蜂鸣器模块D1
int buzzerPin2 = 2; //GPIO2连接蜂鸣器模块D2

//功能函数部分
//按照节拍播放音符
void playNote(char note, int duration) 
{ 
  //names[]中的名称与tones[]中的延时时间一一对应
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };   
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };   
  for (int i = 0; i < 8; i++) 
  {     
    if (names[i] == note) 
    {       
      for (long j = 0; j < duration * 1000L; j += tones[i] * 2) 
      {     
        //输出音符对应频率的方波
        digitalWrite(buzzerPin1, HIGH);     
        delayMicroseconds(tones[i]);     
        digitalWrite(buzzerPin1, LOW);     
        delayMicroseconds(tones[i]);   
      }    
    }   
  } 
}
//初始化设置部分
void setup()
{
  pinMode(buzzerPin1, OUTPUT); 
  pinMode(buzzerPin2, OUTPUT);
  digitalWrite(buzzerPin2, LOW);  
}

//循环执行部分
void loop()
{
  //循环播放乐曲
  for (int i = 0; i < NOTE_LEN; i++) 
  {     
     if (notes[i] == ' ') //检测到空格，播放空节拍 
     {       
         delay(beats[i] * tempo);   
     }
     else 
     {       
        playNote(notes[i], beats[i] * tempo);     
     }  
     delay(tempo / 2);
  }
}