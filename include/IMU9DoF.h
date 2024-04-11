#ifndef IMU9DOF_H
#define IMU9DOF_H

#include <SPI.h>
#include <HardwareSerial.h>
#include <MPU9250_WE.h>
#include "custom_defs.h"

class IMU9DoF {
    public:
    IMU9DoF(uint8_t mosi, uint8_t miso, uint8_t sclk, uint8_t cs, HardwareSerial* serial = nullptr) {
        SPI.setMISO(miso);
        SPI.setMOSI(mosi);
        SPI.setSCLK(sclk);
        SPI.setClockDivider(SPI_CLOCK_DIV4);
        SPI.begin();
        imu = new MPU9250_WE(&SPI, cs, true);
        uartpc = serial;
        bool status = imu->init();
        while(!status) {
            if (uartpc != nullptr) {
                uartpc->println("IMU failed to initialize");
                uartpc->print("Status: ");
                uartpc->println(status);
                break;
            }
            delay(1000);
            status = imu->init();
        }
        uartpc->println("IMU connected");
        imu->autoOffsets();
        imu->setSampleRateDivider(5);
        imu->setAccRange(MPU9250_ACC_RANGE_2G);
        imu->enableAccDLPF(true);
        imu->setAccDLPF(MPU9250_DLPF_6);
        delay(200);
    }

    void getGData(float* ret);
    angle_t getPitch();
    angle_t getRoll();
    angle_t getYaw();

    private:
    MPU9250_WE* imu;
    SPIClass* spi;
    HardwareSerial* uartpc;
};



#endif