

#pragma once
#include "ofMain.h"
#include "Timer.h"

#define VOICES 6
#define buttons 6 

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit(); 

		void keyPressed(int key);
		ofSoundPlayer voicePlayer[VOICES];
		bool voicePaused[VOICES];

		bool arduino_opstarten; 
		ofArduino myArduino; 
		float speed[buttons]; 
		
		int fase[buttons]; 
		Timer tijd[buttons];
		bool tijdis_gestart[buttons];

	private: 
 		void setupArduino(const int & version); 
 		void digitalPinChanged(const int & pinNum); 
};
