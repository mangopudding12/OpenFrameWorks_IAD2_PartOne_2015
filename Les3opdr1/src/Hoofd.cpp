#include "Hoofd.h"

Hoofd::Hoofd()
{
}



void Hoofd::setup()
{
	    speedX = ofRandom(-1,1); 
		speedY = ofRandom(-1,1);

		X = ofRandom(0,ofGetWidth());
		Y = ofRandom(0,ofGetHeight()); 
		radius = ofRandom(40,60); 
		
		kleur1 = ofRandom(0,255);
		kleur2 = ofRandom(0,255);
		kleur3 = ofRandom(0,255);

}



void Hoofd::bounce()
{
	if (X < 0 || X > ofGetWidth())
	{
		//color = (ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		kleur1 = ofRandom(0,255);
		kleur2 = ofRandom(0,255);
		kleur3 = ofRandom(0,255);

		speedX *= -1;
	}

	if ( Y < 0 || Y > ofGetHeight())
	{
		kleur1 = ofRandom(0,255);
		kleur2 = ofRandom(0,255);
		kleur3 = ofRandom(0,255);

		speedY *= -1;
	}

	X += speedX; 
	Y += speedY; 
}