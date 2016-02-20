#pragma once

#include "ofMain.h"

#define CAM_WIDTH 320 
#define CAM_HEIGHT 240


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofVideoGrabber grabber; 
		ofImage image; 
		ofPixels workspace; 
};
