

#pragma once 

#include "ofMain.h"

class Rat 
{
public:
	// Constuctor 
	Rat(); 

	// Functions 
	void setup(); 
	void ren(); 
	void display(); 

	// Variable 
	float speedX; 
	float speedY; 

	float x; 
	float y; 
	int grote; 
	ofColor kleur; 

private:
};
