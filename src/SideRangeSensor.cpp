#include "SideRangeSensor.h"

        
uint8_t SideRangeSensor::get_range() {
    return this->sensor->readRange();
}


uint8_t SideRangeSensor::get_range_status() {
    return this->sensor->readRangeStatus();
}