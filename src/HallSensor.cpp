#include "HallSensor.h"


uint32_t HallSensor::get_value(uint32_t meas_num) {
    uint32_t val = 0;
    for (uint32_t i=0; i<meas_num; i++) {
        val += analogRead(this->pin_num) - this->zeroing_val;
    }
    return val/meas_num;
}

void HallSensor::measure_zero(uint32_t meas_num) {
    this->zeroing_val = 0;
     for (uint32_t i=0; i<meas_num; i++) {
        this->zeroing_val += analogRead(this->pin_num);
    }
    this->zeroing_val /= meas_num;
}