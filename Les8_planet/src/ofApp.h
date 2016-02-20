#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Planet.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key); 

		ofxPanel gui;	// is hoofd  --- deze kan maar een kind hebben
		ofParameterGroup planetParams; // zit in de hoofd en hierin kan je voor elke planeet de parameters in zetten -- meerdere kinderen

		Planet planet01; 
		Planet planet02; 
		Planet planet03; 
		Planet planet04; 
		Planet planet05; 



		bool drawGrid; 

		ofEasyCam cam; 
		ofLight light;
		bool drawLight; 
};
