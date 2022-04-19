//
// Created by jacob on 4/16/2022.
//

#include <iostream>
#include <opencv2/highgui.hpp>
#include "Camera.h"

//Horrible constructor, will need to be refactored to add inputs, and with an adjustable FOV
Camera::Camera() {
    position = Vector3(0,0,-5);
    rotation = Vector3(50,50,0);
    imgPlane = Vector3(0,0,5);
    lightPosition = Vector3(2,-5,3);
    width = 1920;
    height = 1080;
    aspectRatio = width/(float)height;
    FOV = 90;
    epsilon = 0.001;

}

// The heart of the Ray Marching
cv::Mat Camera::CaptureImage(Sphere _sphere) {
    cv::Mat img2(height,width,CV_8UC3,cv::Scalar(0,0,0));

    //Looping over each pixel
    for (int h = 0; h<height;h++){
        for(int w = 0; w<width;w++){

            cv::Vec3b & color = img2.at<cv::Vec3b>(h,w);                                                          //color    - Current pixel colors
            Vector3 dir = GetDirection(w,h);                                                                     //dir      - Direction of the current ray
            Vector3 rayPoint = Vector3(position.x,position.y,position.z);                                     //raypoint - Current point of the marched ray, starting at camera position
            float rayDist = _sphere.SignedDistFunc(rayPoint);                                                      //rayDist  - Distance the ray can travel without hitting the sphere

            bool keepLoop = true;
            // Keep marching the ray
            while (keepLoop){
                // March the ray as far as it can travel without hitting the sphere
                rayPoint = (dir*rayDist)+rayPoint;
                // Find the distance from the ray point to the sphere
                rayDist = _sphere.SignedDistFunc(rayPoint);



                //If the ray point distance is less than 0.01 consider it as reaching the surface of the sphere
                if (rayDist<epsilon){
                    rayPoint = (dir*rayDist)+rayPoint;
                    keepLoop = false;

                    float c = CalculateNormal(rayPoint,_sphere);
                    color[2] = c*255;

//                    Vector3 c = CalculateNormals(rayPoint,_sphere);
//                    color[2] = c.x*255;
//                    color[1] = c.y*255;
//                    color[0] = c.z*255;

                    img2.at<cv::Vec3b>(cv::Point(w,h)) = color;
                }

                //If the ray point distance is greater than 50 we are obviously flying past it at this point
                if(rayDist>50){
                    keepLoop = false;
                }
            }
        }
    }


    return img2;
}

//Direction of the ray traveling through the center of a pixel of the image plane
Vector3 Camera::GetDirection(int px, int py) {


    float rotX = tanf((FOV/2)*((float)M_PI/180));
    float rotY = tanf((FOV/2)*((float)M_PI/180));

    float Px = (2*((px+0.5)/width)-1)*rotX*aspectRatio;
    float Py = (1-2*((py+0.5)/height))*rotY;

    return (Vector3(Px,Py,position.z+1)-position).Normalize();
}

// Bug somewhere in my current calculation
float Camera::CalculateNormal(Vector3 pos, Sphere _sphere) {

    Vector3 xyy = Vector3(epsilon,0,0);
    Vector3 yxy = Vector3(0,epsilon,0);
    Vector3 yyx = Vector3(0,0,epsilon);

    Vector3 normal = Vector3(_sphere.SignedDistFunc(pos+xyy)-_sphere.SignedDistFunc(pos-xyy),
                            _sphere.SignedDistFunc(pos+yxy)-_sphere.SignedDistFunc(pos-yxy),
                            _sphere.SignedDistFunc(pos+yyx)-_sphere.SignedDistFunc(pos-yyx)).Normalize();

    Vector3 direction_to_light  = pos-lightPosition;
    Vector3 normLight = direction_to_light.Normalize();
    float diffuseInt = normal.Dot(normLight);

    if (diffuseInt<0){
        diffuseInt = 0;
    }

    return diffuseInt;
}

Vector3 Camera::CalculateNormals(Vector3 pos, Sphere _sphere) {

    Vector3 xyy = Vector3(epsilon,0,0);
    Vector3 yxy = Vector3(0,epsilon,0);
    Vector3 yyx = Vector3(0,0,epsilon);

    Vector3 normal = Vector3(_sphere.SignedDistFunc(pos+xyy)-_sphere.SignedDistFunc(pos-xyy),
                             _sphere.SignedDistFunc(pos+yxy)-_sphere.SignedDistFunc(pos-yxy),
                             _sphere.SignedDistFunc(pos+yyx)-_sphere.SignedDistFunc(pos-yyx)).Normalize();

    float half = 0.5;

    return normal*half+half;
}