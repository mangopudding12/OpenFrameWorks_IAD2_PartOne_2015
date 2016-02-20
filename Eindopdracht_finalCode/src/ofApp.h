#pragma once

#include "ofMain.h"
#include "Aarde.h"
#include "Spook.h"
#include "Timer.h"



#define aantal 10
#define poorten 4
#define Sensors 4
#define Servos 6  // bij 2 =  1 servo  -->    6 = 4 servo's 
#define Lampjes 11    // bij 8 =  1 lampje -->    11 = 4 lampjes

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit(); 
		ofImage achtergrond; 

		// -----------------------Aarde & Spoken --------------------------------------
			Aarde aarde1; 
			Aarde duisterpoort[Sensors]; 
			Spook spook1[aantal]; 
			bool aan[Sensors]; 


		// ---------------------- Arduino  -------------------------------------------
			
			// Arduino 
			bool arduino_opstarten; 
			ofArduino Arduino; 


		// ----------------------Licht Sensor -----------------------------------------
			
			float maximum;
			bool licht_gekregen [Sensors];
			float minimum[Sensors]; 
			float lichtwaardes[Sensors];
			float sersorvalua[Sensors]; 
			float zaklamp_aan;
			float zaklamp_aan_extreem;


		// ----------------------Timer -----------------------------------------

			bool TimerReached [Sensors];
			bool TimerReached_extreem [Sensors];
			Timer tijd[Sensors]; 
			Timer tijd_extreme[Sensors]; 


			int fase [Sensors];
			int fase_extreem [Sensors];

			
		// ----------------------Elektronica -----------------------------------------

			int aantalServo; 
			int aantalsensors; 


		// ----------------------Bonus -----------------------------------------

			int bonus1; 
			int bonus2;
			int bonus3; 


		// ----------------------Stappen fase -----------------------------------------

			int state; 



	private: 
 		void setupArduino(const int & version); 
 		void analogPinChanged(const int & pinNum); 

};


		


		


