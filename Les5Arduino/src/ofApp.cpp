#include "ofApp.h"

void ofApp::setup() {

	 myArduino.connect("COM3", 57600); 
     bSetupArduino= false; 
}


void ofApp::updateArduino()
{ 
     myArduino.update(); 
} 



void ofApp::setupArduino() 
{

 	myArduino.sendDigitalPinMode(2, ARD_INPUT); 
	myArduino.sendDigitalPinMode(13, ARD_OUTPUT);

	ofAddListener(myArduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(myArduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}




void ofApp::update() {

		 updateArduino(); 

 		 if ( myArduino.isArduinoReady()) 
 		 { 
 			   if (bSetupArduino == false) 
 			   { 
 			      setupArduino(); 
 				  
 			      bSetupArduino = true;	
 			   } 
         } 

}


void ofApp::digitalPinChanged(const int& pinNum) 
{
	// Hey Edwin 
	// Er is iets raar aan de hand. 
	// Wanneer je de code aanzet en dan op de button drukt 
	// werk het perfect hij zet 1 als je hem indrukt en 0 als je hem indrukt. 
	// Dit werkt ongeveer 5 seconden of zo iets en dan .................
	// Niks meer hij reageert gewoon niet meer op de button 
	// Hoe kan dit ??? 
	// Snap jij het ??? 
	cout << myArduino.getDigital(2) << endl; 
}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
}

void ofApp::mousePressed(int x, int y, int button) {
    myArduino.sendDigital(13, ARD_HIGH); // this will switch the on-board Arduino LED on
}

void ofApp::mouseReleased(int x, int y, int button) {
    myArduino.sendDigital(13, ARD_LOW); // this will switch the on-board Arduino LED off
}

