#pragma once

#include "ofMain.h"

#define VIDEO_WIDTH 320
#define VIDEO_HEIGHT 240
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
		ofVideoPlayer video; 
		ofEasyCam cam; 
		
};
