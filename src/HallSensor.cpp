#include "HallSensor.h"


mag_raw_t HallSensor::get_raw_value(mag_raw_t meas_num) {
    mag_raw_t val = 0;
    for (mag_raw_t i=0; i<meas_num; i++) {
        val += analogRead(this->pin_num);
    }
    return val/meas_num;
}

void HallSensor::measure_zero(mag_raw_t meas_num) {
    this->zeroing_raw_val = 0;
     for (mag_raw_t i=0; i<meas_num; i++) {
        this->zeroing_raw_val += analogRead(this->pin_num);
    }
    this->zeroing_raw_val /= meas_num;
    this->zeroing_val = this->zeroing_raw_val*ANALOG_VREF/MAX_MAG_RAW;
}

mag_raw_t HallSensor::get_raw_zero() {
    return this->zeroing_raw_val;
}


mag_t HallSensor::get_zero() {
    return this->zeroing_val;
}


mag_t HallSensor::get_value(mag_raw_t meas_num) {
    mag_raw_t val = this->get_raw_value(meas_num);
    float ret = val*ANALOG_VREF/MAX_MAG_RAW;
    return ret;
}


uint8_t HallSensor::get_id() {
    return this->id;
}