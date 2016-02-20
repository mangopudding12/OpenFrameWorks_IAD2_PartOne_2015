#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofLight licht; 
		ofEasyCam camera; 
		ofImage afbeelding1; 
		ofImage afbeelding2; 
		ofImage afbeelding3; 
};
