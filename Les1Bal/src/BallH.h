#pragma once 

#include "ofMain.h"

class Rondje 
{
	public: 

		// Constuctor 
		Rondje(); 

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



}; // Belangrijk vergeet semicolon niet !! 