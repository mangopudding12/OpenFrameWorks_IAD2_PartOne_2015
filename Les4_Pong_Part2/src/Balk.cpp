
#include "Balk.h"


Balk::Balk()
{

}

void Balk :: setup() 
{
	kleur = ofColor (ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	x = 100;
	y = ofGetHeight()/2; 
	speedY = ofRandom(-1,1);
	hoogte = 100;
	breedte = 20; 
}


void Balk :: move(int beweging_) 
{
	beweging = beweging_; 

	y += beweging; 

	// Zodat de balk niet uit het scherm kan verdwijnen 
	if (y < 0)
	{
		y = 0 ; 
	} else if ( y > ofGetHeight()-hoogte){
		y = ofGetHeight() - hoogte; 
	}
}



void Balk :: display() 
{
	ofSetColor(kleur); 
	ofRect(x,y,breedte,hoogte); 
}
