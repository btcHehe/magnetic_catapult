#ifndef TOFSENSOR_H
#define TOFSENSOR_H

#include <Adafruit_VL6180X.h>
#include "custom_defs.h"


class SideRangeSensor {
    public:
        SideRangeSensor(SensorSide_t side=right, HardwareSerial* uart=nullptr) {
            this->sensor = new Adafruit_VL6180X();
            uart_pc = uart;                         // uart must be started
            if(side == right) {                     // which side the sensor is on
                this->i2c = new TwoWire(I2C1_SDA, I2C1_SCL);
            } else if(side == left) {
                this->i2c = new TwoWire(I2C2_SDA, I2C2_SCL);
            } else {
                // error, side sensor cannot have other side
            }
            while(!this->sensor->begin(this->i2c)) {
                uart_pc->println("Failed to find sensor");
            }
            uart_pc->println("Sensor found");
        }

        ~SideRangeSensor() {
            delete sensor;
            delete i2c;
            delete uart_pc;
        }

        uint8_t get_range();
        uint8_t get_range_status();
    private:
        Adafruit_VL6180X* sensor;
        TwoWire* i2c;
        HardwareSerial* uart_pc;

};


#endif