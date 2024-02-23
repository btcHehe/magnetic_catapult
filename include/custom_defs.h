#ifndef CUSTOM_DEFS_H
#define CUSTOM_DEFS_H

#include <Arduino.h>

#define UART2_TX PA2        // UART2 - serial connection to the PC
#define UART2_RX PA3
#define UART2_BAUD 115200

#define I2C1_SDA PB7        // I2C connections to range sensors
#define I2C1_SCL PA15

#define I2C2_SDA PF0
#define I2C2_SCL PF1

#define I2C3_SDA PC9
#define I2C3_SCL PA8

#define HALL0_PIN PC2       // LEFT BACK POD
#define HALL1_PIN PC3
#define HALL2_PIN PA0
#define HALL3_PIN PA1
#define HALL4_PIN PA4       // LEFT FRONT POD
#define HALL5_PIN PB0
#define HALL6_PIN PC1
#define HALL7_PIN PC0

#define HALL8_PIN PA5       // RIGHT FRONT POD
#define HALL9_PIN PA6
#define HALL10_PIN PA7
#define HALL11_PIN PA2
#define HALL12_PIN PA3      // RIGHT BACK POD
#define HALL13_PIN PC5
#define HALL14_PIN PB11
#define HALL15_PIN PB2

#define HALL_SENSOR_NUM 16

enum SensorSide_t {
    right = 0,
    left = 1,
    back = 2,
    front = 3
};

#endif