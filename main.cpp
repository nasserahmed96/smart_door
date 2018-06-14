/* Facedetection and recognition Software by AbdEl-Nasser Ahmed
 * I don't have any rights to the classifiers in this Software
 * For Detectors all rights reserved to the following papers
 *
@ARTICLE{Castrillon07-jvci,
  author =       "Castrill\'on Santana, M. and D\'eniz Su\'arez, O. and Hern\'andez Tejera, M. and Guerra Artal, C.",
  title =        "ENCARA2: Real-time Detection of Multiple Faces at Different Resolutions in Video Streams",
  journal =      "Journal of Visual Communication and Image Representation",
  year =         "2007",
  vol =          "18",
  issue =        "2",
  month =        "April",
  pages =        "130-140"
}

@INPROCEEDINGS{Castrillon07-swb,
  author =       "Castrill\'on Santana, M. and D\'eniz Su\'arez, O. and Hern\'andez Sosa, D. and Lorenzo Navarro, J. ",
  title =        "Using Incremental Principal Component Analysis to Learn a Gender Classifier Automatically",
  booktitle =    "1st Spanish Workshop on Biometrics",
  year =         "2007",
  month =        "June",
  address =      "Girona, Spain",
  file = F
}*/

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include <iostream>
#include "face_detection.hpp"
using namespace std;
using namespace cv;

//Global varibales

CascadeClassifier face_cascade, eye_cascade, nose_cascade, mouth_cascade;

//bool faceDetection();
//bool checkCascades();


int main(int argc, char* argv[]){
	testFunction();
	faceDetection();
	return 0;
}
	

bool checkCascades(){
	bool found = true;
	if(!(face_cascade.load("../cascade_models/haarcascade_frontalface_alt_tree.xml"))){
		cerr<<"Error while loading face model\n";
		found = false;
	}
	if(!(eye_cascade.load("../cascade_models/haarcascade_eye_tree_eyeglasses.xml"))){
			cerr<<"Error while loading eye model\n";
			found = false;
	}
	if(!(nose_cascade.load("../cascade_models/Nariz.xml"))){
		cerr<<"Error while loading nose model\n";
		found = false;
	}
	if(!(mouth_cascade.load("../cascade_models/Mouth.xml"))){
		cerr<<"Error while loading eye model\n";
		found = false;
	}
	return found;
}


bool faceDetection(){
	bool detected = true;	
	VideoCapture capture;
	Mat frame;
	if(!checkCascades())
		return false;
	else
		cout<<"All models are loaded\n";

	capture.open(0);
	if(!capture.isOpened()){
		cout<<"Error in opening the camera\n";
		return false;
	}
	else
		cout<<"Camera opening done\n";


	//Define a vector for each of the objects to be detected
	vector<Rect> faces;
	vector<Rect> eyes;
	vector<Rect> nose;
	vector<Rect> mouth;
	//First deal with each frame alone
	while(capture.read(frame)){
		//Convert the frame to gray scale image
		cvtColor(frame, frame, CV_BGR2GRAY);
		if(frame.empty()){
			cerr<<"no frame captured, aborting\n";
			return false;
		}
		//Equalize the frame to pass it to the model
		equalizeHist(frame, frame);
		//Using detectMultisScale to detect faces in each frame
		//parameters:
		//Mat& img: frame_gray the image to detect objects in
		//vector<Rect> objects: faces a vector to hold the detected objects(faces)
		//scal_factor:1.1 parameter specifies how much the image size is reduced at each image scale
		//minNeighbors: 2 parameter specifies how many neighbors each candidate rect should retain
		//flasg: 0 flags
		//minSize,maxSize: the min and max size of objects to detect if objects is less than the
		//minimum it's ignored, if it's more than the maximum it's ignored, here we used the 
		//minimum only size(30, 30)
		face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, 
				Size(30, 30));
		//Iterate over each face in faces vector
		for(int i = 0;i < faces.size(); i++){
			cout<<"Face detected\n";
			eye_cascade.detectMultiScale(frame, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE,
					Size(30, 30));
			if(eyes.size() != 0){
				cout<<"Eye detected\n";
				nose_cascade.detectMultiScale(frame, nose, 1.1, 2, 0 | CASCADE_SCALE_IMAGE,
						Size(30, 30));
				if(nose.size() != 0){
					cout<<"Nose detected\n";
					mouth_cascade.detectMultiScale(frame, mouth, 1.1, 2,
							0 | CASCADE_SCALE_IMAGE, Size(30, 30));
					if(mouth.size() != 0){
						cout<<"Mouth detected\n";
						imshow("The face", frame);
						waitKey(0);
						return true;
					}
				}					
			}
		}

	}
		
	return detected;
}



