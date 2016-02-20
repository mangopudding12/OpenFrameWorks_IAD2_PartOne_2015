#pragma once

#include "ofMain.h"
#include "Hoofd.h"
#include "DrieH.h"
#include "RectH.h"
#include "Rond.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// Soort  array
		vector<DrieH> DrieHoek;  
		vector<RectH> VierKant; 
		vector<RondH> Rondjes; 

		int hoeveelheid; 
};
