// Include de header file die bij de class hoort. 
#include "BallH.h"


Rondje::Rondje()
{

}

void Rondje::setup()
{
		speedX = ofRandom(-2,2); 
		speedY = ofRandom(-2,2);

		X = ofRandom(0,ofGetWidth());
		Y = ofRandom(0,ofGetHeight()); 
		radius = ofRandom(40,60); 
		//color = (ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		kleur1 = ofRandom(0,255);
		kleur2 = ofRandom(0,255);
		kleur3 = ofRandom(0,255);
}


void Rondje::bounce()
{
	

	if (X < 0 || X > ofGetWidth() || Y < 0 || Y > ofGetHeight())
	{
		//color = (ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		kleur1 = ofRandom(0,255);
		kleur2 = ofRandom(0,255);
		kleur3 = ofRandom(0,255);

		speedX *= -1;
		speedY *= -1;
	}

	X += speedX; 
	Y += speedY; 
}


void Rondje::display() 
{
	//ofSetColor(color); 
	ofSetColor(kleur1,kleur2,kleur3);
	ofEllipse(X,Y,radius,radius); 
}


