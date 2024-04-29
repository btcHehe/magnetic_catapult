#ifndef CUSTOM_DEFS_H
#define CUSTOM_DEFS_H

#include <Arduino.h>

#define ANALOG_VREF 3.3
#define MAX_MAG_RAW 4095    // 12-bit ADCs
typedef uint16_t mag_raw_t; // raw value of hall sensor
typedef float mag_t;        // processed value of hall sensor [V]
typedef float angle_t;      // value of angle 
typedef float range_t;      // range type [mm]
#define MATH_PI 3.1415
#define EPSILON_OMEGA 0.01  // ~0.5 deg threshold under which we say the cart is stationary
#define MEAS_PER_POINT 100   // number of measurements taken per point

#define UART2_TX PC10        // UART2 - serial connection to the PC
#define UART2_RX PC11
#define UART2_BAUD 115200

#define I2C1_SDA PB7        // I2C connections to range sensors
#define I2C1_SCL PA15

#define I2C2_SDA PA10
#define I2C2_SCL PA9

#define I2C3_SDA PC9
#define I2C3_SCL PA8

#define SPI2_MOSI PB15      // SPI connections to 9DoF IMU module
#define SPI2_MISO PB14
#define SPI2_SCLK PB13
#define SPI2_CS PB10

#define HALL0_PIN PC2       // LEFT BACK POD
#define HALL1_PIN PC3
#define HALL2_PIN PA0
#define HALL3_PIN PA1
#define HALL4_PIN PA4       // LEFT FRONT POD
#define HALL5_PIN PC4
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

#define LEFT_RANGE_SENSOR_OFFSET 17
#define RIGHT_RANGE_SENSOR_OFFSET 17
#define BACK_RANGE_SENSOR_OFFSET 5

enum SensorSide_t {         // range sensor side
    right = 0,
    left = 1,
    back = 2,
    front = 3
};

enum PodSide_t {
    RightBack = 0,
    LeftBack = 1,
    LeftFront = 2,
    RightFront = 3
};

#endif