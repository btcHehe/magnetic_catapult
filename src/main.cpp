#include "SideRangeSensor.h"
#include "HallSensor.h"
#include "Pod.h"

HardwareSerial* uartpc;
SideRangeSensor* right_sensor;
SideRangeSensor* left_sensor;
SideRangeSensor* back_sensor;
Pod* RB_pod;
Pod* LB_pod;
Pod* LF_pod;
Pod* RF_pod;
// HallSensor* h1;

void setup() {
  analogReadResolution(12);
  uartpc = new HardwareSerial(UART2_RX, UART2_TX);
  // put your setup code here, to run once:
  uartpc->begin(UART2_BAUD);

  pinMode(LED_BUILTIN, OUTPUT);
  uartpc->println("SETUP");
  uartpc->println(MAX_MAG_RAW);
  right_sensor = new SideRangeSensor(right, uartpc);
  left_sensor = new SideRangeSensor(left, uartpc);
  back_sensor = new SideRangeSensor(back, uartpc);

  // h1 = new HallSensor(PC4, 0);
  RB_pod = new Pod(RightBack);
  LB_pod = new Pod(LeftBack);
  LF_pod = new Pod(LeftFront);
  RF_pod = new Pod(RightFront);
}

void loop() {

  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  uartpc->println("Right sensor range [mm]:");
  uartpc->println(right_sensor->get_range());
  uartpc->println("Left sensor range [mm]:");
  uartpc->println(left_sensor->get_range());
  uartpc->println("Back sensor range [mm]:");
  uartpc->println(back_sensor->get_range());
  uartpc->println("Hall sensor data:");

  RB_pod->print_values(uartpc);
  LB_pod->print_values(uartpc);
  LF_pod->print_values(uartpc);
  // RF_pod->print_values(uartpc);
  // uartpc->println(h1->get_raw_value());
  // uartpc->println(h1->get_raw_zero());
  // uartpc->println(h1->get_value());
  // uartpc->println(h1->get_zero());
  uartpc->println("-------------------------------------");

  //uartpc->println("hi");
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);      
}
