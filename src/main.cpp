#include "MeasurementManager.h"

MeasurementManager* mm;

void setup() {
  analogReadResolution(12);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SPI2_CS, OUTPUT);
  mm = new MeasurementManager();





}

void loop() {
  delay(50);
  mm->readUART();
}
