/********************************************
�������ƣ�xbee_shield_test_arduino
���ܣ�XBeeģ�鷶�����루Arduino�ˣ�
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
//�궨�弰ȫ�ֱ���
int ledPin    = 9;  //LED����Arduino D9
int buttonPin = 10; //��������Arduino D10

//���ܺ�������

//��ʼ�����ò���
void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  digitalWrite(ledPin,HIGH);
  Serial.begin(9600);
}

//ѭ��ִ�в���
void loop()
{
  //�����������ͨ��XBeeģ�鷢���ַ�'a'
  if(digitalRead(buttonPin) == LOW)
  {
    //��ʱ10ms������������
    delay(10);
    if(digitalRead(buttonPin) == LOW)
    {
      Serial.print('a');
      delay(200);
    } 
  }
  
  //������յ�XBeeģ�鷢�����ַ�'b'��LED��˸
  if (Serial.available() > 0)
  {
    byte dataRead;
    dataRead = Serial.read();
    if(dataRead == 'b')
    {
    digitalWrite(ledPin,LOW);
    delay(1500);
    digitalWrite(ledPin,HIGH);
    }
  }
}