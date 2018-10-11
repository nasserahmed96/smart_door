#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/face.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "face_recognition.hpp"
#include "string"

using namespace std;
using namespace cv;
Person person;

Ptr<cv::face::LBPHFaceRecognizer> model = cv::face::LBPHFaceRecognizer::create();
string model_path = "/home/nasser/myproject/Smart_Door/LBH_model.xml";
Person predict(Mat img){
	model -> read(model_path);
	int predictLabel = model -> predict(img);
	string name = model ->getLabelInfo(predictLabel);
	cout<<"Label is: "<<predictLabel<<endl<<"This is: "<<name<<endl;
	person.person_name = name;
	person.person_label = predictLabel;
	return person;
}

void training(vector<Mat> train_images, vector<int> train_labels,
		char *person_name){
	model->train(train_images, train_labels);
	model->setLabelInfo(train_labels[0], person_name);
	model->write(model_path);
}

void update(vector<Mat> new_images,vector<int> new_labels,char* person_name){
	model->read(model_path);
	model->update(new_images, new_labels);
	model->setLabelInfo(new_labels[0], person_name);
	model->write(model_path);
}





