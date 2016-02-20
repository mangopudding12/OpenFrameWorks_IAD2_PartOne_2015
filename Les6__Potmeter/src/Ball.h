#pragma once 

#include "ofMain.h"

class DrieHoek 
{
	public: 
		
		// constuctor 
		DrieHoek(); 

		// Functions 
		void setup();

		// Zorgt dat je in de haken van bounce schrijft dat je int gaat gebruiken die speedpotmoter heet
		void bounce(int speedpotmoter); 
		void display(); 

		// Variables 
		float X; 
		float Y; 
		float speedX;
		float speedY; 
		int	radius; 
		ofColor color; 

		// Arduino stuff 
		bool aanuit; 
		bool arduinoConnected; 

		// Maak een nieuw arduino object aan 
		ofArduino* arduinoO; 


	private: 
};