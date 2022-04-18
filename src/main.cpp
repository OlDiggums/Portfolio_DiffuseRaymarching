#include <iostream>
#include "Sphere.h"
#include "Camera.h"
#include <opencv2/highgui/highgui.hpp>

int main() {
    std::cout << "Starting" << std::endl;
    Sphere mySphere  = Sphere(0,0,-5,1);

    Camera cam = Camera();
    cv::Mat img = cam.CaptureImage(mySphere); // Refactor to work with opencv images..........
    std::cout << "Done" << std::endl;
    cv::imshow("Display window", img);
    cv::imwrite("./Output.png", img);
    int k = cv::waitKey(0); // Wait for a keystroke in the window

    return 0;
}
