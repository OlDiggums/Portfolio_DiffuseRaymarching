//
// Created by jacob on 4/13/2022.
//

#include "Sphere.h"

Sphere::Sphere() {
    position = Vector3(0,0,-5);
    radius = 1;
}

Sphere::Sphere(Vector3 pos, float _radius) {
    position = pos;
    radius = _radius;
}

Sphere::Sphere(float xx,float yy,float zz, float _radius) {
    position = Vector3(xx,yy,zz);
    radius = _radius;
}

// Distance from sphere function using the input point
float Sphere::SignedDistFunc(Vector3 point) {
    return (point-position).getMagnitude()-radius;
}
