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
        integratedYaw = 0;
        integratedPitch = 0;
        integratedRoll = 0;
        Roll = 0;
        Yaw = 0;
        Pitch = 0;
        delay(200);
    }

    angle_t getPitch();
    angle_t getRoll();
    angle_t getYaw();
    void getOmega(float* ome);
    void integrateOmega();
    angle_t getIntPitch();
    angle_t getIntRoll();
    angle_t getIntYaw();
    void setIntegratingStartPoint(int start_microsecond);

    private:
    void getGData();
    void readOmega();
    angle_t integratedYaw;
    angle_t integratedRoll;
    angle_t integratedPitch;
    angle_t Yaw;
    angle_t Pitch;
    angle_t Roll;
    MPU9250_WE* imu;
    SPIClass* spi;
    HardwareSerial* uartpc;
    float g[3];
    float omega[3]; // angular velocity (x, y, z)
    int last_microsecond;     // last time measurement in microsecond (for integration purposes) !!WARNING!! micros() function overflows in 70 minutes !!!
};



#endif