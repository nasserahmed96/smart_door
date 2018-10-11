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
#include "face_recognition.hpp"
#include "wiringPi.h"
#include "sys/types.h"
#include "socket_server.h"
#include "c_sockets_nasser.h"
#include "unistd.h"
#include "pthread.h"
using namespace std;
using namespace cv;

#define PUSH_BUTTON 0
#define BUZZER 1
#define GREEN_LED 2
#define RED_LED 3

void server();
void flashing();
void initializeWiringPi();

int main(int argc, char* argv[]){
	//initializeWiringPi();
	Face face;
	Person person; 
	/*for(;;){
		digitalWrite(GREEN_LED, HIGH);
		if(digitalRead(PUSH_BUTTON) == 0){	
			//Run the buzzer for 10s after pressing the push button
			digitalWrite(BUZZER, HIGH);
			delay(1000);
			digitalWrite(BUZZER, LOW);
			digitalWrite(GREEN_LED, LOW);
			*/
			server();
			face = faceDetection();
			if(face.detected){		
				person = predict(face.detected_face);
				cout<<"Person name: "<<person.person_name<<endl;
				digitalWrite(RED_LED, HIGH);
				printf("characters %s\n", person.person_name.c_str());
				
				}
			/*else{
				//Flashing in case of error
				flashing();
			}*/

	return 0;
}

void initializeWiringPi(){
	wiringPiSetup();
	//Push button
	pinMode(PUSH_BUTTON, INPUT);
	//The Buzzer
	pinMode(BUZZER, OUTPUT);
	//Green LEd
	pinMode(GREEN_LED, OUTPUT);
	//Door 	
	pinMode(RED_LED, OUTPUT);
	//Pull up resistor
	pullUpDnControl(PUSH_BUTTON, PUD_UP);
	digitalWrite(BUZZER, LOW);
	digitalWrite(GREEN_LED, LOW);
	digitalWrite(RED_LED, LOW);
}

//Flashing the red led 10 times, seconde for each time
void flashing(){
	for(int i = 0;i < 10;i++){
		digitalWrite(RED_LED, HIGH);
		delay(1000);
		digitalWrite(RED_LED, HIGH);
		delay(1000);
	}
}
	
void server(){
	//digitalWrite(GREEN_LED, HIGH);
	searchList(NULL);
	bindSocket();
	startServer();
	//digitalWrite(GREEN_LED, LOW);
}
