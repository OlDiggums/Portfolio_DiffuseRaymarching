//
// Created by jacob on 4/13/2022.
//

#include "Vector3.h"


Vector3::Vector3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3::Vector3(float xx, float yy, float zz) {
    this->x = xx;
    this->y = yy;
    this->z = zz;
}

void Vector3::SetPosition(float xx, float yy, float zz) {
    this->x= xx;
    this->y= yy;
    this->z= zz;
}

Vector3 Vector3::Normalize() {
    float mag = this->getMagnitude();
    return Vector3(x/mag,y/mag,z/mag);
}

