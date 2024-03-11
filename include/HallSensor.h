#ifndef HALL_SENSOR_H
#define HALL_SENSOR_H

#include "Arduino.h"
#include "custom_defs.h"

class HallSensor {
    public:
    HallSensor(uint8_t pin, uint8_t sensor_id) {
        this->id = sensor_id;
        this->pin_num = pin;
        pinMode(this->pin_num, INPUT);
        this->measure_zero();
    }

    mag_raw_t get_raw_value(mag_raw_t meas_num=10);
    void measure_zero(mag_raw_t meas_num=10);
    mag_raw_t get_raw_zero();
    mag_t get_zero();
    mag_t get_value(mag_raw_t meas_num=10);

    private:
    uint8_t id;
    uint8_t pin_num;
    mag_raw_t zeroing_raw_val;
    mag_t zeroing_val;
};


#endif