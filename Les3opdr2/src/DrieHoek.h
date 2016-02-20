
#pragma once 

#include "ofMain.h"

class DrieHoek 
{
	public: 
		
		// constuctor 
		DrieHoek(); 

		// Functions 
		void setup();
		void bounce(); 
		void display(); 

		// Variables 
		float X; 
		float Y; 
		float speedX;
		float speedY; 
		int	radius; 
		ofColor color; 

	private: 
};