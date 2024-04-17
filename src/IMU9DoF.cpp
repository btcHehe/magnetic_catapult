#include "IMU9DoF.h"

void IMU9DoF::getGData() {
    xyzFloat gvals = this->imu->getGValues();
    this->g[0] = gvals.x;
    this->g[1] = gvals.y;
    this->g[2] = gvals.z;
}

angle_t IMU9DoF::getPitch() {
    this->getGData();
    float G = sqrt(g[0]*g[0] + g[1]*g[1] + g[2]*g[2]);
    angle_t alfa1 = asin(g[0]/G);
    angle_t alfa2 = acos(sqrt(g[1]*g[1]/(G*G) + g[2]*g[2]/(G*G)));
    angle_t alfa3 = 0;
    if(alfa1 >= -MATH_PI/4 && alfa1 <= MATH_PI/4) {
        alfa3 = alfa1;
    } else if (alfa1 > MATH_PI/4){ 
        alfa3 = alfa2;
    } else {
        alfa3 = -alfa2;
    }
    return alfa3;

}

angle_t IMU9DoF::getRoll() {
    this->getGData();
    float G = sqrt(g[0]*g[0] + g[1]*g[1] + g[2]*g[2]);
    angle_t beta1 = asin(g[1]/G);
    angle_t beta2 = acos(sqrt(g[0]*g[0] + g[2]*g[2])/G);
    angle_t beta3 = 0;
    if(beta1 >= -MATH_PI/4 && beta1 <= MATH_PI/4) {
        beta3 = beta1;
    } else if (beta1 > MATH_PI/4) { 
        beta3 = beta2;
    } else {
        beta3 = -beta2;
    }
    return beta3;
}

angle_t IMU9DoF::getYaw() {
    return integratedYaw;
}


void IMU9DoF::integrateOmega() {
    float omx = this->omega[0];     // previous values of omega
    float omy = this->omega[1];
    float omz = this->omega[2];
    float dt = (micros() - this->last_microsecond)/1e6;     // timestep in seconds
    this->readOmega();
    this->integratedPitch += (omx + this->omega[0])*dt/2;
    this->integratedRoll += (omy + this->omega[1])*dt/2;
    this->integratedYaw += (omz + this->omega[2])*dt/2;
}


void IMU9DoF::readOmega() {
    xyzFloat gyr = this->imu->getGyrValues();
    this->omega[0] = gyr.x;
    this->omega[1] = gyr.y;
    this->omega[2] = gyr.z;
}


void IMU9DoF::getOmega(float* ome) {
    ome = this->omega;
}


void IMU9DoF::setIntegratingStartPoint(int start_microsecond) {
    this->last_microsecond = start_microsecond;
}

angle_t IMU9DoF::getIntPitch() {
    return integratedPitch;
}

angle_t IMU9DoF::getIntRoll() {
    return integratedRoll;
}

angle_t IMU9DoF::getIntYaw() {
    return integratedYaw;
}


void IMU9DoF::resetInegratedVals() {
    this->integratedPitch = 0;
    this->integratedRoll = 0;
    this->integratedYaw = 0;
}