#include "HallSensor.h"


uint32_t HallSensor::get_raw_value(uint32_t meas_num) {
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


uint32_t HallSensor::get_raw_zero() {
    return this->zeroing_val;
}


float HallSensor::get_value(uint32_t meas_num) {
    uint32_t val = this->get_raw_value(meas_num);
    float ret = 0 + ((val - 0)*(ANALOG_VREF - 0))/(UINT32_MAX - 0);
    return ret;
}