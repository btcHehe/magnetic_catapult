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

    uint32_t get_raw_value(uint32_t meas_num=10);
    void measure_zero(uint32_t meas_num=10);
    uint32_t get_raw_zero();
    float get_value(uint32_t meas_num=10);

    private:
    uint8_t id;
    uint8_t pin_num;
    uint32_t zeroing_val;
};


#endif