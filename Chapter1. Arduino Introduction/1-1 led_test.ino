/********************************************
�������ƣ�led_test
���ܣ�Arduino����LED��������
�汾��v1.0
���ߣ������� <haixiaoli2@163.com>
*********************************************/
int led_pin = 13; // ����13��ΪLED����
void setup()
{
  pinMode(led_pin, OUTPUT);     // ����LED����Ϊ���ģʽ
}
void loop()
{
  digitalWrite(led_pin, HIGH);  // ��������Ϊ�ߵ�ƽ��LED����
  delay(1000);  // �ȴ�1s
  digitalWrite(led_pin, LOW);   // ��������Ϊ�ߵ�ƽ��LEDϨ��
  delay(1000);  // �ȴ�1s
}
