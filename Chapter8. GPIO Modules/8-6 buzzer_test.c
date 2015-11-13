/********************************************
�������ƣ�buzzer_test
���ܣ�����������������������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//����ͷ�ļ�
#include <core.h>

//�궨�弰ȫ�ֱ���
#define NOTE_LEN   15 //������������
char notes[50] = "ccggaagffeeddc "; //��С���ǡ�����
int beats[50] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 }; //ÿ��������ռ����
int tempo = 300;

int buzzerPin1 = 1; //GPIO1���ӷ�����ģ��D1
int buzzerPin2 = 2; //GPIO2���ӷ�����ģ��D2

//���ܺ�������
//���ս��Ĳ�������
void playNote(char note, int duration) 
{ 
  //names[]�е�������tones[]�е���ʱʱ��һһ��Ӧ
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };   
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };   
  for (int i = 0; i < 8; i++) 
  {     
    if (names[i] == note) 
    {       
      for (long j = 0; j < duration * 1000L; j += tones[i] * 2) 
      {     
        //���������ӦƵ�ʵķ���
        digitalWrite(buzzerPin1, HIGH);     
        delayMicroseconds(tones[i]);     
        digitalWrite(buzzerPin1, LOW);     
        delayMicroseconds(tones[i]);   
      }    
    }   
  } 
}
//��ʼ�����ò���
void setup()
{
  pinMode(buzzerPin1, OUTPUT); 
  pinMode(buzzerPin2, OUTPUT);
  digitalWrite(buzzerPin2, LOW);  
}

//ѭ��ִ�в���
void loop()
{
  //ѭ����������
  for (int i = 0; i < NOTE_LEN; i++) 
  {     
     if (notes[i] == ' ') //��⵽�ո񣬲��ſս��� 
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