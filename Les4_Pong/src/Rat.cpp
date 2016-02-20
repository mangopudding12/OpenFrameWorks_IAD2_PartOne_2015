
#include "Rat.h"

Rat:: Rat() 
{
	
}


void Rat::setup() 
{
	kleur = ofColor (ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	grote = ofRandom(40,80); 
	x = ofRandom(800,ofGetWidth());
	y = ofRandom(0,ofGetHeight());
	speedX = ofRandom(-1,1);
	speedY = ofRandom(-1,1);
}


void Rat::ren() 
{
	if (x > ofGetWidth())
	{
		
		speedX *= -1;
	}

	if (y < 0 || y > ofGetHeight())
	{
		speedY *= -1;
	}

	x += speedX; 
	y += speedY; 
}


void Rat::display() 
{
	ofSetColor(kleur);  
	ofRect(x,y,grote,grote); 
}






