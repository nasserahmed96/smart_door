#ifndef FACE_DETECTION
#define FACE_DETECTION

#include <opencv4/opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include "face_recognition.hpp"
using namespace cv;


typedef struct {
	Mat detected_face;
	bool detected;
}Face;

void testFunction();
bool checkCascades();
Face faceDetection();
#endif
