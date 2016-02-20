#pragma once

#include "ofMain.h"
#include "Timer.h"

#define Sensors 1
#define Servos 3     // bij 2 =  1 servo  -->    5 = 4 servo's 
#define Lampjes 8    // bij 8 =  1 lampje -->    11 = 4 lampjes

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
		float maximum;


		// alle electronica variable 

			//float sersorvalua;
			float sersorvalua[Sensors]; 

			//float lichtwaardes; 
			float lichtwaardes[Sensors];

			//bool  TimerReached; // used as a trigger when we hit the timer
			bool TimerReached [Sensors];
			bool TimerReached_extreem [Sensors];

			//bool licht_gekregen; 
			bool licht_gekregen [Sensors];

			//int hoi;
			int fase [Sensors];
			int fase_extreem [Sensors];

			//float minimum; 
			float minimum[Sensors]; // -- 4 plekken 


		float zaklamp_aan;
		float zaklamp_aan_extreem;

		int bonus1; 
		int bonus2;
		int bonus3; 




		// Timer normaal
		Timer tijd[Sensors]; 
		
		// Timer Extreem veel licht
		Timer tijd_extreme[Sensors]; 


		// Elektronica 
		int aantalServo; 
		int aantalsensors; 

		// Stappen fase 
		int state; 


 	private: 
 		void setupArduino(const int & version); 
 		void analogPinChanged(const int & pinNum); 
		void digitalPinChanged(const int & pinNum); 
};
