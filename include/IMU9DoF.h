#ifndef IMU9DOF_H
#define IMU9DOF_H

#include <SPI.h>
#include <HardwareSerial.h>
#include "MPU9250.h"
#include "custom_defs.h"

class IMU9DoF {
    public:
    IMU9DoF(uint8_t mosi, uint8_t miso, uint8_t sclk, uint8_t cs, HardwareSerial* serial = nullptr) {
        spi = new SPIClass(mosi, miso, sclk, cs);
        imu = new MPU9250(*spi, cs);
        uartpc = serial;
        int status = imu->begin();
        while(status < 0) {
            if (uartpc != nullptr) {
                uartpc->println("IMU failed to initialize");
                uartpc->print("Status: ");
                uartpc->println(status);
            }
            delay(1000);
            status = imu->begin();
        }
        imu->setAccelRange(MPU9250::ACCEL_RANGE_2G);
        imu->setGyroRange(MPU9250::GYRO_RANGE_250DPS);
        imu->setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
        imu->setSrd(19);    // 50 Hz update rate
    }

    private:
    MPU9250* imu;
    SPIClass* spi;
    HardwareSerial* uartpc;
};



#endif