

#pragma once 

#include "ofMain.h"
#include "BallH.h"

class ofApp : public ofSimpleApp{

	public:
		void setup();
		void update();
		void draw();

		

		// Soort  array
		vector<Rondje> Rond;  

		int hoeveelheid; 

	private:
		
};


 