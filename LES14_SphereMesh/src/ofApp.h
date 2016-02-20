#pragma once

#include "ofMain.h"

#define IMAGE_WIDTH 400
#define IMAGE_HEIGHT 563
#define MESH_SIZE 10

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofEasyCam cam;
		ofLight light; 

		ofImage image; 
		ofSpherePrimitive sphere; 

		vector <int> origz;
		
};
