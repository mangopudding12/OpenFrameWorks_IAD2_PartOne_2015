

#pragma once 

#include "ofMain.h"

class Balk 
{
public:
	// Constuctor 
	Balk(); 

	// Functions 
	void setup(); 
	void move(int beweging_); 
	void display(); 

	// Variable  
	float speedY; 

	float x; 
	float y; 
	int hoogte;
	int breedte; 

	ofColor kleur; 

	int beweging; 



private:
};
