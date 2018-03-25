
/*
NodeManager is intended to take care on your behalf of all those common tasks a MySensors node has to accomplish, speeding up the development cycle of your projects.
NodeManager includes the following main components:
- Sleep manager: allows managing automatically the complexity behind battery-powered sensors spending most of their time sleeping
- Power manager: allows powering on your sensors only while the node is awake
- Battery manager: provides common functionalities to read and report the battery level
- Remote configuration: allows configuring remotely the node without the need to have physical access to it
- Built-in personalities: for the most common sensors, provide embedded code so to allow their configuration with a single line 
Documentation available on: https://github.com/mysensors/NodeManager
*/

 
// load user settings
#include "config.h"

// include supporting libraries
#ifdef MY_GATEWAY_ESP8266
  #include <ESP8266WiFi.h>
#endif
// load MySensors library
#include <MySensors.h>
// load NodeManager library
#include "NodeManager.h"
#define MY_SIGNAL_REPORT_ENABLED
// create a NodeManager instance
NodeManager nodeManager;


// before
void before() {
  // setup the serial port baud rate
  Serial.begin(MY_BAUD_RATE);  
  //pinMode(5,OUTPUT);
  //digitalWrite(5,HIGH);
  nodeManager.setReportIntervalMinutes(2);
  //int relais1Id;
  //int relais2Id;
  /*
   * Register below your sensors
  */
  //relais1Id=nodeManager.registerSensor(SENSOR_RELAY,4,1);
  //relais2Id=nodeManager.registerSensor(SENSOR_RELAY,5,2);
  nodeManager.registerSensor(SENSOR_RELAY,4,1);
  nodeManager.registerSensor(SENSOR_RELAY,5,2);
  nodeManager.registerSensor(SENSOR_SHT21,-1,3);
  //((SensorRelay*)nodeManager.getSensor(relais1Id))->setOnValue(LOW);
  

  /* #if SIGNAL_SENSOR == 1 && defined(MY_SIGNAL_REPORT_ENABLED)
      // [33] How frequenly to send a signal report to the controller (default: 60 minutes)
      nodeManager.setSignalReportMinutes(30);
      // [43] How frequenly to send a signal report to the controller (default: 60 minutes)
      // void setSignalReportSeconds(int value);
      // [44] How frequenly to send a signal report to the controller (default: 60 minutes)
      // void setSignalReportHours(int value);
      // [45] How frequenly to send a signal report to the controller (default: 60 minutes)
      // void setSignalReportDays(int value);
      // [34] define which signal report to send. Possible values are SR_UPLINK_QUALITY, SR_TX_POWER_LEVEL, SR_TX_POWER_PERCENT, SR_TX_RSSI, SR_RX_RSSI, SR_TX_SNR, SR_RX_SNR (default: SR_RX_RSSI)
      // nodeManager.setSignalCommand(SR_RX_RSSI);
      // [35] report the signal level to the controller
      // void signalReport();
  #endif */  

  
  /*
   * Register above your sensors
  */
  nodeManager.before();
}

// presentation
void presentation() {
  // call NodeManager presentation routine
  nodeManager.presentation();
}

// setup
void setup() {
  // call NodeManager setup routine
  nodeManager.setup();
}

// loop
void loop() {
  // call NodeManager loop routine
  nodeManager.loop();
}

// receive
void receive(const MyMessage &message) {
  // call NodeManager receive routine
  nodeManager.receive(message);
  //digitalWrite(8,HIGH);
}

// receiveTime
void receiveTime(unsigned long ts) {
  // call NodeManager receiveTime routine
  nodeManager.receiveTime(ts);
}
