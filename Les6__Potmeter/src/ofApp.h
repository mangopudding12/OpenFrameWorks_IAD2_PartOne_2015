#pragma once

#include "ofMain.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();	
		void exit(); 

		DrieHoek kaas;


		bool arduino_opstarten; 
		ofArduino myArduino; 
 
 	private: 
 		void setupArduino(const int & version); 
 		void digitalPinChanged(const int & pinNum); 
 		void analogPinChanged(const int & pinNum); 
};
