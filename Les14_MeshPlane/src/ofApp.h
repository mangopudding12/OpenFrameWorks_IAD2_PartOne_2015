#pragma once

#include "ofMain.h"

#define IMAGE_WIDTH 400
#define IMAGE_HEIGHT 563
#define MESH_WIDTH 400 
#define MESH_HEIGHT 300 
#define MESH_SIZE_X 50 
#define MESH_SIZE_Y 30 


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		ofPlanePrimitive plane; 
		ofImage image; 
		ofEasyCam cam; 
};
