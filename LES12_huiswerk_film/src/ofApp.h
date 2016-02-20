#pragma once

#include "ofMain.h"
#include "Image.h"

#define CAM_WIDTH 320 
#define CAM_HEIGHT 240


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		vector <Image> plaatje;
		int hoeveelheid; 
		
		ofVec2f wind; 
		ofVec2f zwaartekracht;
		ofVec2f weerstand; 
		float wgrote; 
		float wspeed; 

		ofVideoGrabber grabber; 
		ofPixels workspace; 
};
