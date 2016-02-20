#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include <iostream> 
using namespace std; 


class ofApp : public ofBaseApp {

public:

    void setup();
    void update();

    void setupArduino(); 
    void updateArduino(); 
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

         //allows for serial output  
         ofSerial serial; 
 
         //an arduino object 
         ofArduino myArduino; 
 
         //this variable will only be false when the code first runs arduino 
         bool bSetupArduino; 
		 void digitalPinChanged(const int & pinNum);
         void analogPinChanged(const int & pinNum);

private:

 };
