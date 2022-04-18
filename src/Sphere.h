//
// Created by jacob on 4/13/2022.
//

#ifndef PROJECT1_BASICS_SPHERE_H
#define PROJECT1_BASICS_SPHERE_H
#include "Vector3.h"

class Sphere {
public:
    Vector3 position;
    float radius;
    Sphere();
    Sphere(Vector3 pos,float _radius);
    Sphere(float xx,float yy,float zz,float _radius);
    void SetPosition(float xx,float yy,float zz){position.SetPosition(xx,yy,zz);}
    float SignedDistFunc(Vector3 point);
};


#endif //PROJECT1_BASICS_SPHERE_H
