#pragma once

#include "ofMain.h"
#define CAM_WIDTH  512
#define CAM_HEIGHT 384
#define aantal 4


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		ofVideoPlayer video;
		ofVideoGrabber grabber; 
};
