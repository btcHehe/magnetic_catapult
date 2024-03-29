#include "SideRangeSensor.h"
#include "HallSensor.h"
#include "Pod.h"
#include "IMU9DoF.h"
#include "misc"

HardwareSerial* uartpc;
SideRangeSensor* right_sensor;
SideRangeSensor* left_sensor;
SideRangeSensor* back_sensor;
Pod* RB_pod;
Pod* LB_pod;
Pod* LF_pod;
Pod* RF_pod;

// IMU9DoF* IMU;

void setup() {
  analogReadResolution(12);
  uartpc = new HardwareSerial(UART2_RX, UART2_TX);
  uartpc->begin(UART2_BAUD);

  pinMode(LED_BUILTIN, OUTPUT);
  uartpc->println("SETUP");
  uartpc->println(MAX_MAG_RAW);
  right_sensor = new SideRangeSensor(right, uartpc);
  left_sensor = new SideRangeSensor(left, uartpc);
  back_sensor = new SideRangeSensor(back, uartpc);

  RB_pod = new Pod(RightBack);
  LB_pod = new Pod(LeftBack);
  LF_pod = new Pod(LeftFront);
  RF_pod = new Pod(RightFront);

  // IMU = new IMU9DoF(SPI2_MOSI, SPI2_MISO, SPI2_SCLK, SPI2_CS);

  uartpc->println("back range, left range, right range, RB, LB, LF, RF");
  signal_boot_finish();
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  uartpc->print(back_sensor->get_range());
  uartpc->print(", ");
  uartpc->print(left_sensor->get_range());
  uartpc->print(", ");
  uartpc->print(right_sensor->get_range());
  uartpc->print(", ");
  uartpc->print(RB_pod->get_value());
  uartpc->print(", ");
  uartpc->print(LB_pod->get_value());
  uartpc->print(", ");
  uartpc->print(LF_pod->get_value());
  uartpc->print(", ");
  uartpc->println(RF_pod->get_value());

   
}
