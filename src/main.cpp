#include "MeasurementManager.h"

MeasurementManager* mm;

void setup() {
  analogReadResolution(12);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SPI2_CS, OUTPUT);
  mm = new MeasurementManager();





}

void loop() {
  
  mm->fullMeasurement();
  delay(500);
}
