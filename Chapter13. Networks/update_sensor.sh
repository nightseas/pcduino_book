$ ./internet_sensors
$ curl --request POST --data-binary @"./temp.txt" --header "U-ApiKey:f0a9b0354be0f92f66c8f9c92ec7d44d" http://api.yeelink.net/v1.0/device/7964/sensor/12620/datapoints
$ curl --request POST --data-binary @"./press.txt" --header "U-ApiKey:f0a9b0354be0f92f66c8f9c92ec7d44d" http://api.yeelink.net/v1.0/device/7964/sensor/12621/datapoints
$ curl --request POST --data-binary @"./light.txt" --header "U-ApiKey:f0a9b0354be0f92f66c8f9c92ec7d44d" http://api.yeelink.net/v1.0/device/7964/sensor/12622/datapoints
