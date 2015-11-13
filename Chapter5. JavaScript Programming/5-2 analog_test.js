/********************************************
�������ƣ�analog_test
���ܣ�JavaScript���ƿ���ADC��PWM��������
*********************************************/
//ʵ����pcduino��analog��
var pcduino = require("pcduino");
var analog = pcduino.analog;

function delay(ms)
{
  var start = new Date().getTime();
  for (var i = 0; i < 1e7; i++)
  if ((new Date().getTime() - start) > ms) break;
}

//��ʼ�����ò���
function setup()
{
  console.log("Set GPIO5 to 50.");
  analog.analogWrite(5, 50);
}

//ѭ��ִ�в���
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
