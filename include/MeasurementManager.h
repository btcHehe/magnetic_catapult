#ifndef MEASUREMENT_MANAGER_H
#define MEASUREMENT_MANAGER_H

#include "IMU9DoF.h"
#include "SideRangeSensor.h"
#include "Pod.h"


class MeasurementManager {
    public:
        MeasurementManager() {

            uartpc = new HardwareSerial(UART2_RX, UART2_TX);
            uartpc->begin(UART2_BAUD);
            uartpc->println("SETUP");
            right_sensor = new SideRangeSensor(right, uartpc);
            left_sensor = new SideRangeSensor(left, uartpc);
            back_sensor = new SideRangeSensor(back, uartpc);

            RB_pod = new Pod(RightBack);
            LB_pod = new Pod(LeftBack);
            LF_pod = new Pod(LeftFront);
            RF_pod = new Pod(RightFront);

            IMU = new IMU9DoF(SPI2_MOSI, SPI2_MISO, SPI2_SCLK, SPI2_CS, uartpc);
            //signal_boot_finish();
            uartpc->println("SETUP FINISHED");
            //sendMenu();
        }

        void sendMenu();
        void readUART();
        void fullMeasurement();
        void selfCheck();
        void sendIntegratedData(float* ome, float pitch, float roll, float yaw);


    private:
        void YawMeasurement();
        void restMeasurement(int iters);
        HardwareSerial* uartpc;
        SideRangeSensor* right_sensor;
        SideRangeSensor* left_sensor;
        SideRangeSensor* back_sensor;
        Pod* RB_pod;
        Pod* LB_pod;
        Pod* LF_pod;
        Pod* RF_pod;
        IMU9DoF* IMU;
};

#endif