//
// Created by jacob on 4/16/2022.
//

#ifndef PROJECT1_BASICS_CAMERA_H
#define PROJECT1_BASICS_CAMERA_H
#include "Vector3.h"
#include "Sphere.h"
#include <opencv2/core/core.hpp>

class Camera {
public:
    Vector3 position;
    Vector3 imgPlane;
    int width;
    int height;
    float epsilon;

    Camera();
    cv::Mat CaptureImage(Sphere inp);
    Vector3 GetDirection(int px,int py);
    float CalculateNormal(Vector3 p, Sphere _sphere);


private:
    float FOV;
    float aspectRatio;

};


#endif //PROJECT1_BASICS_CAMERA_H
