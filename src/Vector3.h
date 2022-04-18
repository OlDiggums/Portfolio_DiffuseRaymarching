//
// Created by jacob on 4/13/2022.
//

#ifndef PROJECT1_BASICS_VECTOR3_H
#define PROJECT1_BASICS_VECTOR3_H
#include <cmath>

class Vector3 {
public:
    float x;
    float y;
    float z;

    Vector3();
    Vector3(float xx, float yy, float zz);
    void SetPosition(float xx,float yy,float zz);
    float getMagnitude() { return sqrtf(x*x+y*y+z*z);}
    float Dot(Vector3 p){return x*p.x+y*p.y+z*p.z;}
    Vector3 Normalize();
    Vector3 operator-(Vector3 &other){return Vector3(x-other.x,y-other.y,z-other.z);}
    Vector3 operator+(Vector3 &other){return Vector3(x+other.x,y+other.y,z+other.z);}
    Vector3 operator+(float &other){return Vector3(x+other,y+other,z+other);}
    Vector3 operator*(float &other){return Vector3(x*other,y*other,z*other);}
    Vector3 operator/(float &other){return Vector3(x/other,y/other,z/other);}

};


#endif //PROJECT1_BASICS_VECTOR3_H
