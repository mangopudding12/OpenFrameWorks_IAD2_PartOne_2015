#pragma once 
#include "ofmain.h"

class Spook
{
public: 

	Spook() { }; // Default constructor -- anders doet andere contructor het niet. 
	Spook (int massa_,float x_,float y_ ); 

	// functions 
	void setup (); 
	void bounce(); 
	void applyforce(ofVec2f); 
	void move(); 
	void display(int welkplaatje_); 


	int welkeplaatje; 


	// variable 
	ofVec2f velocity;		// speed
	ofVec2f location;		// x and y 
	ofVec2f accelaration;   // versnellen - verlangzamen 

	int maxspeed; 
	ofColor kleur; 
	float massa; 
	ofImage afbeelding1; 
	ofImage afbeelding2; 

private: 
}; 