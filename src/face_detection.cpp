#include <iostream>
#include <face_detection.hpp>
#include "face_recognition.hpp"
using namespace std;
CascadeClassifier face_cascade, eye_cascade, nose_cascade, mouth_cascade;

void testFunction(){
	cout<<"Bism Allah\n";
}

bool checkCascades(){
	bool found = true;
	if(!(face_cascade.load("/home/nasser/myproject/Smart_Door/cascade_models/haarcascade_frontalface_alt_tree.xml"))){
		cerr<<"Error while loading face model\n";
		found = false;
	}
	if(!(eye_cascade.load("/home/nasser/myproject/Smart_Door/cascade_models/haarcascade_eye_tree_eyeglasses.xml"))){
			cerr<<"Error while loading eye model\n";
			found = false;
	}
	if(!(nose_cascade.load("/home/nasser/myproject/Smart_Door/cascade_models/Nariz.xml"))){
		cerr<<"Error while loading nose model\n";
		found = false;
	}
	if(!(mouth_cascade.load("/home/nasser/myproject/Smart_Door/cascade_models/Mouth.xml"))){
		cerr<<"Error while loading eye model\n";
		found = false;
	}
	return found;
}




Face faceDetection(){
	Face face;	
	VideoCapture capture;
	Mat frame;
	face.detected = false;
	face.detected_face = frame;
	if(!checkCascades())
		return face;
	else
		cout<<"All models are loaded\n";

	capture.open(0);
	if(!capture.isOpened()){
		cout<<"Error in opening the camera\n";
		return face;
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
			return face;
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
			Point center( faces[i].x + faces[i].width * 0.5,
				       	faces[i].y + faces[i].height * 0.5);
			ellipse(frame, center,
				       	Size(faces[i].width * 0.5, faces[i].height * 0.5),
				       0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);	
			eye_cascade.detectMultiScale(frame, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE,
					Size(30, 30));
			if(eyes.size() != 0){
			Point center( faces[i].x + eyes[0].x + eyes[0].width * 0.5,
				       	faces[i].y + eyes[0].y + eyes[0].height * 0.5);
			ellipse(frame, center,
				       	Size(faces[i].width * 0.5, faces[i].height * 0.5),
				       0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);	
				cout<<"Eye detected\n";
				nose_cascade.detectMultiScale(frame, nose, 1.1, 2, 0 | CASCADE_SCALE_IMAGE,
						Size(30, 30));
				if(nose.size() != 0){
					cout<<"Nose detected\n";
					mouth_cascade.detectMultiScale(frame, mouth, 1.1, 2,
							0 | CASCADE_SCALE_IMAGE, Size(30, 30));
					if(mouth.size() != 0){
						cout<<"Mouth detected\n";								
						Face face;
						face.detected_face = frame;
						face.detected = true;
						imwrite("face_image.jpg", frame);
						return face;
					}
				}					
			}
		}

	}
		
	return face;
}



