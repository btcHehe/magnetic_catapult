#ifndef CUSTOM_DEFS_H
#define CUSTOM_DEFS_H

#include <Arduino.h>

#define UART2_TX PA2
#define UART2_RX PA3
#define UART2_BAUD 115200

#define I2C1_SDA PB7
#define I2C1_SCL PA15

#define I2C2_SDA PF0
#define I2C2_SCL PF1

#define I2C3_SDA PC9
#define I2C3_SCL PA8

enum SensorSide_t {
    right = 0,
    left = 1,
    back = 2,
    front = 3
};

#endif