#include "SideRangeSensor.h"

        
range_t SideRangeSensor::get_range(int meas_num) {
    uint16_t r = 0;
    for (int i=0; i<meas_num; i++) {
        if(this->sensor_side == right || this->sensor_side == left) {
            r += this->sensor_6180->readRange() + SENSOR_OFFSET_MM;
        } else {
            r += this->sensor_53L0->readRange() + SENSOR_OFFSET_MM;
        }
    }
    return ((range_t)r)/meas_num;
}


uint8_t SideRangeSensor::get_range_status() {
    if(this->sensor_side == right || this->sensor_side == left) {
        return this->sensor_6180->readRangeStatus();
    } else {
        return this->sensor_53L0->readRangeStatus();
    }
}