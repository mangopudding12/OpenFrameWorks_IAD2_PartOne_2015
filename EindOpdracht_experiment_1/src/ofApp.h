#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void exit(); 


		// Arduino 
		bool arduino_opstarten; 
		ofArduino Arduino; 

		// Licht sensor 
		float minimum; 
		float maximum;
		float sersorvalua; 
		float blub; 

		// Timer 
		int timer; 


 	private: 
 		void setupArduino(const int & version); 
 		void analogPinChanged(const int & pinNum); 
		void digitalPinChanged(const int & pinNum); 
};
