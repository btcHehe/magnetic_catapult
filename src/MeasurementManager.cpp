#include "MeasurementManager.h"


void MeasurementManager::sendMenu() {
    this->uartpc->println("System ready for measurement, please select one option: ");
    this->uartpc->println("1 - start full measurement");
    this->uartpc->println("2 - perform sensor tests");
    this->uartpc->println("3 - restart system");

}

void MeasurementManager::readUART() {
    this->restMeasurement(MEAS_PER_POINT);
    return;
    int s = this->uartpc->read();
    if(s == 1) {
        this->fullMeasurement();
    } else if(s == 2) {
        
    } else if(s == 3) {
        SystemInit();
    } else {
        this->uartpc->println("It is not the correct option, please try again");
        this->sendMenu();
    }
}

void MeasurementManager::fullMeasurement() {
    this->uartpc->println("Performing integration measusrement");
    this->uartpc->println("omega.x, omega.y, omega.z, pitch, roll, yaw");
    //this->YawMeasurement();
    this->uartpc->println("Yaw measurement finished, the cart is stationary");
    this->restMeasurement(MEAS_PER_POINT);
    this->uartpc->println("The rest of the measurements finished, place the cart to another point");
    //this->sendMenu();
}

void MeasurementManager::selfCheck() {

}

void MeasurementManager::YawMeasurement() {
    float omegas[3];
    this->IMU->setIntegratingStartPoint(micros());
    do {        // 
        this->IMU->integrateOmega();
        this->IMU->getOmega(omegas);
        this->sendIntegratedData(omegas, this->IMU->getIntPitch(), this->IMU->getIntRoll(), this->IMU->getIntYaw());
    } while(abs(omegas[0]) <= EPSILON_OMEGA && abs(omegas[1]) <= EPSILON_OMEGA && abs(omegas[2]) <= EPSILON_OMEGA);
}


void MeasurementManager::sendIntegratedData(float* ome, float pitch, float roll, float yaw) {
    this->uartpc->print(ome[0]);
    this->uartpc->print(", ");
    this->uartpc->print(ome[1]);
    this->uartpc->print(", ");
    this->uartpc->print(ome[2]);
    this->uartpc->print(", ");
    this->uartpc->print(pitch);
    this->uartpc->print(", ");
    this->uartpc->print(roll);
    this->uartpc->print(", ");
    this->uartpc->println(yaw);
}

void MeasurementManager::restMeasurement(int iters) {
    this->uartpc->print(back_sensor->get_range());
    this->uartpc->print(", ");
    this->uartpc->print(left_sensor->get_range());
    this->uartpc->print(", ");
    this->uartpc->print(right_sensor->get_range());
    this->uartpc->print(", ");
    this->uartpc->print(RB_pod->get_value());
    this->uartpc->print(", ");
    this->uartpc->print(LB_pod->get_value());
    this->uartpc->print(", ");
    this->uartpc->print(LF_pod->get_value());
    this->uartpc->print(", ");
    this->uartpc->print(RF_pod->get_value());
    this->uartpc->print(", ");
    this->uartpc->print(IMU->getPitch()*180/MATH_PI);
    this->uartpc->print(", ");
    this->uartpc->print(IMU->getRoll()*180/MATH_PI);
    this->uartpc->print(", ");
    this->uartpc->println(IMU->getYaw()*180/MATH_PI);
    delay(100);
}