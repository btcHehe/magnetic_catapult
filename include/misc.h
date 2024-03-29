#ifndef MISC_H
#define MISC_H

#include <Arduino.h>

void signal_boot_finish(int blinks_no=5) {
    for (int i=0; i<blinks_no; i++) {
        delay(500);   
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);   
        digitalWrite(LED_BUILTIN, LOW);
    }
}


#endif