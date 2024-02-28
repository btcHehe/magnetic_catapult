#ifndef SIDE_RANGE_SENSOR_H
#define SIDE_RANGE_SENSOR_H

#include <Adafruit_VL6180X.h>
#include <Adafruit_VL53L0X.h>
#include "custom_defs.h"


class SideRangeSensor {
    public:
        SideRangeSensor(SensorSide_t side=right, HardwareSerial* uart=nullptr) {
            this->sensor_side = side;
            this->uart_pc = uart;                                   // uart must be started
            if(this->sensor_side == right) {                        // which side the sensor is on
                this->i2c = new TwoWire(I2C1_SDA, I2C1_SCL);
                this->sensor_6180 = new Adafruit_VL6180X();
                this->sensor_53L0 = nullptr;
            } else if(this->sensor_side == left) {
                this->i2c = new TwoWire(I2C2_SDA, I2C2_SCL);
                this->sensor_6180 = new Adafruit_VL6180X();
                this->sensor_53L0 = nullptr;
            } else if(this->sensor_side == back) {
                this->i2c = new TwoWire(I2C3_SDA, I2C3_SCL);
                this->sensor_53L0 = new Adafruit_VL53L0X();
                this->sensor_6180 = nullptr;
            } else if (this->sensor_side == front) {
            } else {
            }

            if (sensor_53L0 == nullptr){
                while(!this->sensor_6180->begin(this->i2c)) {
                    if(this->sensor_side == right){
                         this->uart_pc->println("Failed to find right sensor");
                    } else if(this->sensor_side == left) {
                        this->uart_pc->println("Failed to find left sensor");
                    } else if(this->sensor_side == back) {
                        this->uart_pc->println("Failed to find back sensor");
                    } else {
                    }
                    delay(500);
                }
            } else {
                while(!this->sensor_53L0->begin(VL53L0X_I2C_ADDR, false, this->i2c)) {
                    if(this->sensor_side == right){
                         this->uart_pc->println("Failed to find right sensor");
                    } else if(this->sensor_side == left) {
                        this->uart_pc->println("Failed to find left sensor");
                    } else if(this->sensor_side == back) {
                        this->uart_pc->println("Failed to find back sensor");
                    }
                    delay(500);
                }
            }
            if(this->sensor_side == right){
                 this->uart_pc->println("Right sensor found");
            } else if(this->sensor_side == left) {
                this->uart_pc->println("Left sensor found");
            } else if(this->sensor_side == back) {
                this->uart_pc->println("Back sensor found");
            }
        }

        ~SideRangeSensor() {
            delete sensor_53L0;
            delete sensor_6180;
            delete i2c;
            delete uart_pc;
        }

        uint8_t get_range();
        uint8_t get_range_status();
    private:
        SensorSide_t sensor_side;
        Adafruit_VL6180X* sensor_6180;
        Adafruit_VL53L0X* sensor_53L0;
        TwoWire* i2c;
        HardwareSerial* uart_pc;

};


#endif