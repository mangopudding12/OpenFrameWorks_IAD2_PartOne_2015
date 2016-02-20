#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofAddListener(Arduino.EInitialized, this, &ofApp::setupArduino); 

    arduino_opstarten = false; 
 	Arduino.connect("COM3", 57600); // aan deze poort zit de arduino 

	Arduino.sendFirmwareVersionRequest(); // Deze regel code niet weg halen anders werkt het niet meer

	timer = 0; 
	minimum = 0; 
	maximum = 1023;
}

//--------------------------------------------------------------
void ofApp::update()
{
	Arduino.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	     
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


	if (key == 100)
	{
			timer = 2; 
			//Arduino.sendServo(9, 180, false);
			cout << "gedrukt" << endl; 
	} 
         
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}


void ofApp::setupArduino(const int& version) 
{
	ofRemoveListener(Arduino.EInitialized, this, &ofApp::setupArduino);
	arduino_opstarten = true; 


	// Vertellen welke electronica op welke pin zit en wat het doet 
	Arduino.sendAnalogPinReporting(0, ARD_ANALOG); // hier zit de lichtsensor aan 
	Arduino.sendServoAttach(9);

	ofAddListener(Arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	ofAddListener(Arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
}



void ofApp:: analogPinChanged(const int & pinNum)
{
	if (timer == 0)
	{
		sersorvalua = Arduino.getAnalog(0);
		cout << sersorvalua << endl;  // print uit wat er binnen komt 


		if (sersorvalua > minimum) // zet omgeving licht als minimum zodat pas reageert als die meer licht ontvangt. 
		{
			minimum = sersorvalua;
		}

		cout << minimum << endl; 
		timer = 1; 

	}  else if (timer == 1) { 
		
		sersorvalua = Arduino.getAnalog(0);
		// Print de sersorvalua dat tussen de minimum en maximum ligt in een range van 0 255 -- Wordt naar die getallen omgezet 
		blub = ofMap(sersorvalua,minimum,maximum,0,255); 

		

	} else if (timer == 2){ // Start Experiment met servo's
		
		sersorvalua = Arduino.getAnalog(0);
		blub = ofMap(sersorvalua,minimum,maximum,0,255); 

		if (blub > 200)
		{ 
			 Arduino.sendServo(9, 0, false);
		} else if (blub < 100)
		{
			Arduino.sendServo(9, 180, false);
		} else if (blub > 100 && blub < 200)
		{
			Arduino.sendServo(9, 90, false);
		}

		cout <<  blub << endl; 
	}
}



void ofApp:: digitalPinChanged(const int & pinNum)
{
	 int getServo(4);
}

void ofApp:: exit() 
{
	Arduino.disconnect();
}