cmake_minimum_required(VERSION 3.21)
project(Portfolio_NormalsRaymarching)

set(OpenCV_DIR "Z:/opencv/build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)
include_directories(${OpenCV_INCLUDE_DIRS}) # Not needed for CMake >= 2.8.11
set(CMAKE_CXX_STANDARD 11)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

add_executable(Portfolio_NormalsRaymarching src/main.cpp src/Sphere.cpp src/Sphere.h src/Vector3.cpp src/Vector3.h src/Camera.cpp src/Camera.h)
target_link_libraries(Portfolio_NormalsRaymarching ${OpenCV_LIBS})