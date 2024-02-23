#include "SideRangeSensor.h"
#include "HallSensor.h"

HardwareSerial* uartpc;
SideRangeSensor* right_sensor;
SideRangeSensor* left_sensor;
SideRangeSensor* back_sensor;

void setup() {
  uartpc = new HardwareSerial(UART2_RX, UART2_TX);
  // put your setup code here, to run once:
  uartpc->begin(UART2_BAUD);

  pinMode(LED_BUILTIN, OUTPUT);
  uartpc->println("SETUP");
  right_sensor = new SideRangeSensor(right, uartpc);
  left_sensor = new SideRangeSensor(left, uartpc);
  back_sensor = new SideRangeSensor(back, uartpc);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  uartpc->println(right_sensor->get_range());
  //uartpc->println("hi");
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);      
}
