/********************************************
程序名称：led_test
功能：Arduino控制LED范例代码
版本：v1.0
作者：懒兔子 <haixiaoli2@163.com>
*********************************************/
int led_pin = 13; // 定义13脚为LED引脚
void setup()
{
  pinMode(led_pin, OUTPUT);     // 设置LED引脚为输出模式
}
void loop()
{
  digitalWrite(led_pin, HIGH);  // 设置引脚为高电平，LED点亮
  delay(1000);  // 等待1s
  digitalWrite(led_pin, LOW);   // 设置引脚为高电平，LED熄灭
  delay(1000);  // 等待1s
}
