#pragma once

#include "ofMain.h"
#include "Rat.h"
#include "Balk.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit(); 

		void keyPressed(int key);
		void keyReleased(int key);
		
		// Pionter gemaakt naar Rat class 
		vector <Rat*> ratten; 
		Balk* BalkL; 

		int speedBalk; 
		int hoeveelheid; 
};
