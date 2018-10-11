#ifndef FACE_RECOGNITION
#define FACE_RECOGNITION
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

typedef struct{
	string person_name;
	int person_label;
}Person;


Person predict(Mat);
void training(vector<Mat>, vector<int>, char*);
void update(vector<Mat>, vector<int>, char*);


#endif

