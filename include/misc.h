#ifndef MISC_H
#define MISC_H

#include <Arduino.h>
#include "custom_defs.h"

void signal_boot_finish(int blinks_no=5) {
    for (int i=0; i<blinks_no; i++) {
        delay(100);   
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);   
        digitalWrite(LED_BUILTIN, LOW);
    }
}

angle_t rad2deg_own(angle_t angle_rad) {
    return 180*angle_rad/MATH_PI;
}

angle_t deg2rad_own(angle_t angle_deg) {
    return MATH_PI*angle_deg/180;
}

#endif