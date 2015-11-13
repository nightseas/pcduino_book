/********************************************
程序名称：analog_test
功能：JavaScript控制控制ADC和PWM范例代码
*********************************************/
//实例化pcduino和analog类
var pcduino = require("pcduino");
var analog = pcduino.analog;

function delay(ms)
{
  var start = new Date().getTime();
  for (var i = 0; i < 1e7; i++)
  if ((new Date().getTime() - start) > ms) break;
}

//初始化设置部分
function setup()
{
  console.log("Set GPIO5 to 50.");
  analog.analogWrite(5, 50);
}

//循环执行部分
function loop()
{
  var readValue = analog.analogRead(0);
  console.log("The analog value of A0 is " + readValue + ".");
  delay(2000);
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
