#include "IMU9DoF.h"

void IMU9DoF::getGData(float* ret) {
    xyzFloat gvals = this->imu->getGValues();
    ret[0] = gvals.x;
    ret[1] = gvals.y;
    ret[2] = gvals.z;
}

angle_t IMU9DoF::getPitch() {
    float g[3];    // gx, gy, gz
    this->getGData(g);
    float G = sqrt(g[0]*g[0] + g[1]*g[1] + g[2]*g[2]);
    angle_t alfa1 = asin(g[0]/G);
    angle_t alfa2 = acos(sqrt(g[1]*g[1]/(G*G) + g[2]*g[2]/(G*G)));
    angle_t alfa3 = 0;
    if(alfa1 >= -MATH_PI/4 && alfa1 <= MATH_PI/4) {
        alfa3 = alfa1;
    } else { 
        alfa3 = alfa2;
    }
    angle_t w1 = cos(alfa3)*cos(alfa3);
    angle_t w2 = sin(alfa3)*sin(alfa3);
    angle_t alfa4 = w1*alfa1 + w2*alfa2;
    if(g[2] > 0 ) {
        return alfa4;
    } else if(g[2] < 0 && alfa4 > 0) {
        return MATH_PI-alfa4;
    } else if(g[2] < 0 && alfa4 < 0) {
        return -MATH_PI-alfa4;
    }
}

angle_t IMU9DoF::getRoll() {
    float g[3];    // gx, gy, gz
    this->getGData(g);
    float G = sqrt(g[0]*g[0] + g[1]*g[1] + g[2]*g[2]);
    angle_t beta1 = asin(g[1]/G);
    angle_t beta2 = acos(sqrt(g[0]*g[0] + g[2]*g[2])/G);
    angle_t beta3 = 0;
    if(beta1 >= -MATH_PI/4 && beta1 <= MATH_PI/4) {
        beta3 = beta1;
    } else { 
        beta3 = beta2;
    }
    angle_t w1 = cos(beta3)*cos(beta3);
    angle_t w2 = sin(beta3)*sin(beta3);
    angle_t beta4 = w1*beta1 + w2*beta2;
    if(g[2] > 0 ) {
        return beta4;
    } else if(g[2] < 0 && beta4 > 0) {
        return MATH_PI-beta4;
    } else if(g[2] < 0 && beta4 < 0) {
        return -MATH_PI-beta4;
    }
}

angle_t IMU9DoF::getYaw() {

}