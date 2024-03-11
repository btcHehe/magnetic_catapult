#include "Pod.h"


mag_t Pod::get_value(mag_raw_t meas_num) {
    mag_t v = 0;
    v = (RB->get_value(meas_num) + LB->get_value(meas_num) + LF->get_value(meas_num) + RF->get_value(meas_num))/4;
    return v; 
}

mag_t Pod::get_rb_value(mag_raw_t meas_num) {
    return RB->get_value(meas_num);
}

mag_t Pod::get_lb_value(mag_raw_t meas_num) {
    return LB->get_value(meas_num);
}

mag_t Pod::get_lf_value(mag_raw_t meas_num) {
    return LF->get_value(meas_num);
}

mag_t Pod::get_rf_value(mag_raw_t meas_num) {
    return RF->get_value(meas_num);
}


void Pod::print_values(HardwareSerial* uart) {
    uart->print("Pod ");
    uart->println(this->id);
    uart->print("Sensor ");
    uart->println(RB->get_id());
    uart->println(RB->get_raw_value());
    uart->println(RB->get_value());
    uart->print("Sensor ");
    uart->println(LB->get_id());
    uart->println(LB->get_raw_value());
    uart->println(LB->get_value());
    uart->print("Sensor ");
    uart->println(LF->get_id());
    uart->println(LF->get_raw_value());
    uart->println(LF->get_value());
    uart->print("Sensor ");
    uart->println(RF->get_id());
    uart->println(RF->get_raw_value());
    uart->println(RF->get_value());
}