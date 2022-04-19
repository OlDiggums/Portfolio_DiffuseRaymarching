#include <iostream>
#include "Sphere.h"
#include "Camera.h"
#include <opencv2/highgui/highgui.hpp>

int main() {
    std::cout << "Starting" << std::endl;
    Sphere mySphere  = Sphere(0,0,0,1);

    Camera cam = Camera();
    cam.lightPosition = Vector3(2,-5,3);
    cv::Mat img = cam.CaptureImage(mySphere); // Refactor to work with opencv images..........
    cv::imshow("Display window", img);
    int k = cv::waitKey(0); // Wait for a keystroke in the window
    std::cout << "Done" << std::endl;
    cv::imwrite("./Output.png", img);


    return 0;
}
