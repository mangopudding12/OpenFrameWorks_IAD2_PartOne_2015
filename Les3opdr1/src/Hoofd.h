#pragma once 

#include "ofMain.h"

class Hoofd 
{
public: 
	
	// Constuctor 
	Hoofd();

	// Functies 
	void setup(); 
	void bounce();

	// Variables 
	float speedX; 
	float speedY; 

	float kleur1;
	float kleur2;
	float kleur3; 

	float X;
	float Y;
	int radius; 
};