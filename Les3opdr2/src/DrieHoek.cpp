
#include "DrieHoek.h"


// Constuctor 
DrieHoek :: DrieHoek()
{

}

void DrieHoek :: setup()
{
	speedX = ofRandom(-1,1); 
	speedY = ofRandom(-1,1);

	X = ofRandom(0,ofGetWidth());
	Y = ofRandom(0,ofGetHeight()); 
	radius = ofRandom(40,60); 
	color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));

}


void DrieHoek :: bounce()
{

	if (X < 0 || X > ofGetWidth())
	{
		color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		
		speedX *= -1;
	}

	if (Y < 0 || Y > ofGetHeight())
	{
		color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));   
		speedY *= -1;
	}

	X += speedX; 
	Y += speedY; 

}


void DrieHoek :: display()
{
	ofSetColor(color);
	ofSetCircleResolution(6);
	ofEllipse(X,Y,radius,radius);
}