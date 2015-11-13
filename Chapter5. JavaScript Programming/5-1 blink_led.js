/********************************************
程序名称：blink_led
功能：JavaScript控制LED范例代码
*********************************************/
//定义基础变量
var fs = require('fs');
var led_pin;
var INPUT = 0;
var OUTPUT = 1;
var LOW = 0;
var HIGH = 1;

//定义基础功能函数
function digitalWrite(pin, value)
{
  fs.writeFileSync("/sys/devices/virtual/misc/gpio/mode/gpio" + pin, String(value));
}

function pinMode(pin, mode)
{
  fs.writeFileSync("/sys/devices/virtual/misc/gpio/mode/gpio" + pin, String(mode));
}

function delay(ms)
{
  var start = new Date().getTime();
  for (var i = 0; i < 1e7; i++)
  if ((new Date().getTime() - start) > ms) break;
}

//初始化设置部分
function setup()
{
  led_pin = 18;
  pinMode(led_pin, OUTPUT);
}

//循环执行部分
function loop()
{
  digitalWrite(led_pin, HIGH);
  delay(1000);
  digitalWrite(led_pin, LOW);
  delay(1000);
}

function main()
{
  setup();
  while(1)
  {
    loop();
  }
}

main();
