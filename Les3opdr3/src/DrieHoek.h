#pragma once 

#include "ofMain.h"

class DrieHoek 
{
	public: 
		
		// constuctor 
		DrieHoek(float snelY_, float vorm_); 

		// Functions 
		void setup(float Snel_);
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