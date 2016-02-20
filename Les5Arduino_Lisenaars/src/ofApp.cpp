#include "ofApp.h"

void ofApp::setup() 
{
	arduino.connect("COM3", 57600); 
	
  
    isArduinoInitialized = false;
	
	cout << "ben connext "  << endl;
 }



void ofApp::setupArduino() {
	cout << " ik begin aan arduino setup "  << endl;


    // set flag: Arduino now ready for use
    isArduinoInitialized = true;

    // print firmware name and version to the console
    ofLog(OF_LOG_NOTICE,"Arduino found: %s", arduino.getFirmwareName());
    ofLog(OF_LOG_NOTICE,"Firmata v%s.%s", arduino.getMajorFirmwareVersion(), arduino.getMinorFirmwareVersion());

	arduino.sendDigitalPinMode(2,ARD_INPUT);
    arduino.sendDigitalPinMode(13, ARD_OUTPUT);

    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	
	cout << "Ben klaar met setup "  << endl;
}


void ofApp::update() 
{

	

	if ( arduino.isArduinoReady()) 
 		 { 
 			   // 1st: setup the arduino if haven't already: 
 			   if (  isArduinoInitialized  == false) 
 			   { 
              
 			      //this fundtion assigns the pins 
 			     setupArduino(); 
 			
 			   } 
          
              // 2nd do the update of the arduino 
			   arduino.update();
			  cout << "Arduino update"  << endl;
         } 

	   arduino.update();
}




void ofApp::digitalPinChanged(const int& pinNum) {




	// Edwin help ..................................... !!!!!!!!!!1 
	// Alweer voert die dit maar 1 keer uit precies hetzelfde probleem wat ik in mijn andere arduino schets had
	// waarom gebeurt dit en wat is de oplossen ?? 
	if (arduino.getDigital(2) == ARD_HIGH)
	{
		  arduino.sendDigital(13, ARD_HIGH);

	} else if (arduino.getDigital(2) == ARD_LOW) {
		  arduino.sendDigital(13, ARD_LOW);
	}


}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
}


void ofApp::mousePressed(int x, int y, int button) {
}

void ofApp::mouseReleased(int x, int y, int button) {
}
