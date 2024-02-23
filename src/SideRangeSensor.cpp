#include "SideRangeSensor.h"

        
uint8_t SideRangeSensor::get_range() {
    if(this->sensor_side == right || this->sensor_side == left) {
        return this->sensor_6180->readRange();
    } else {
        return this->sensor_53L0->readRange();
    }
}


uint8_t SideRangeSensor::get_range_status() {
    if(this->sensor_side == right || this->sensor_side == left) {
        return this->sensor_6180->readRangeStatus();
    } else {
        return this->sensor_53L0->readRangeStatus();
    }
}