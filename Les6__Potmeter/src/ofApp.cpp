#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{
	kaas.setup(); 
	kaas.arduinoO = &myArduino; // Vertel de arduinoO die in class kaas zit is een copie van myArduino

	ofAddListener(myArduino.EInitialized, this, &ofApp::setupArduino); 
    arduino_opstarten = false; 
 	myArduino.connect("COM3", 57600); // aan deze poort zit de arduino 

	myArduino.sendFirmwareVersionRequest(); // Deze regel code niet weg halen anders werkt het niet meer
}

//--------------------------------------------------------------
void ofApp::update()
{
	myArduino.update();
	kaas.arduinoConnected =  arduino_opstarten; // als opstarten is true dan zorgen dat connect ook true is 

	// Stuurt gegevens van potmeter naar de ball class. 
	// Deze data wordt ontvangen in de bounce functie 
	kaas.bounce(myArduino.getAnalog(0));  

}

//--------------------------------------------------------------
void ofApp::draw()
{
	kaas.display();
}

void ofApp::setupArduino(const int& version) 
{
	ofRemoveListener(myArduino.EInitialized, this, &ofApp::setupArduino);

	arduino_opstarten = true; 

	// Vertellen welke electronica op welke pin zit en wat het doet 
	myArduino.sendDigitalPinMode(2, ARD_INPUT); // hier zit een button aan 
	myArduino.sendDigitalPinMode(8, ARD_OUTPUT);
	myArduino.sendDigitalPinMode(13, ARD_OUTPUT);
	myArduino.sendAnalogPinReporting(0, ARD_ANALOG); // hier zit de potmotor aan 

	ofAddListener(myArduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
}


void ofApp::digitalPinChanged(const int& pinNum) 
{
	cout << myArduino.getDigital(2) << endl; 

	// wanneer je op de knop druk gaat de lamp aan anders is led 13 uit 
	if (myArduino.getDigital(2) == ARD_HIGH)
	{
		myArduino.sendDigital(13,ARD_HIGH); 
	} else { 
		myArduino.sendDigital(13,ARD_LOW); 
	}
}


void ofApp:: exit() 
{
	myArduino.disconnect();
}