#ifndef POD_H
#define POD_H

#include "HallSensor.h"

class Pod {
    public:
    Pod(PodSide_t pod_id) {
        if(pod_id == RightBack) {
            id = pod_id;
            RB = new HallSensor(HALL12_PIN, 12);
            LB = new HallSensor(HALL13_PIN, 13);
            LF = new HallSensor(HALL14_PIN, 14);
            RF = new HallSensor(HALL15_PIN, 15);
        } else if(pod_id == LeftBack) {
            id = pod_id;
            RB = new HallSensor(HALL0_PIN, 0);
            LB = new HallSensor(HALL1_PIN, 1);
            LF = new HallSensor(HALL2_PIN, 2);
            RF = new HallSensor(HALL3_PIN, 3);
        } else if(pod_id == LeftFront) {
            id = pod_id;
            RB = new HallSensor(HALL4_PIN, 4);
            LB = new HallSensor(HALL5_PIN, 5);
            LF = new HallSensor(HALL6_PIN, 6);
            RF = new HallSensor(HALL7_PIN, 7);
        } else if(pod_id == RightFront) {
            id = pod_id;
            RB = new HallSensor(HALL8_PIN, 8);
            LB = new HallSensor(HALL9_PIN, 9);
            LF = new HallSensor(HALL10_PIN, 10);
            RF = new HallSensor(HALL11_PIN, 11);
        }
    }

    mag_t get_value(mag_raw_t meas_num=10);
    mag_t get_rb_value(mag_raw_t meas_num=10);
    mag_t get_lb_value(mag_raw_t meas_num=10);
    mag_t get_lf_value(mag_raw_t meas_num=10);
    mag_t get_rf_value(mag_raw_t meas_num=10);

    void print_values(HardwareSerial* uart);

    private:
    PodSide_t id;
    HallSensor* RB;      // right back
    HallSensor* LB;      // left back
    HallSensor* LF;      // left front 
    HallSensor* RF;      // right front

};

#endif