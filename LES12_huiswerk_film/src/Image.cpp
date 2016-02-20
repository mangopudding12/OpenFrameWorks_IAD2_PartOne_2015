#include "Image.h"

Image :: Image (int massa_,float radius_,float x_) 
{
	massa = massa_; 
	radius = radius_; 

	location.set(radius*massa + x_,0); 	
} 

void Image :: setup() 
{ 
	kleur = ofColor(ofRandom(100,255),ofRandom(100,255),ofRandom(0,100));
	
	velocity.set(0,0);
	accelaration.set(0,0);
	
	maxspeed = 4; // anders wordt snelheid eindeloos snel	
}


void Image :: applyforce(ofVec2f force) 
{
	ofVec2f f = force / massa; 
	accelaration += f; 
}


void Image::move() 
{
	velocity += accelaration; 
	location += velocity; 

	// Reset accelation 
	accelaration *= 0; 
}


void Image:: bounce() 
{
	
	if (location.x > ofGetWidth() - radius/2*massa)
	{
		kleur = ofColor (0,0,0);
		location.x =  ofGetWidth();
		velocity.x *= -1;
	} 
	 
	if (location.x  < 0)
	{
		kleur = ofColor (0,0,0);
		location.x =  0;
		velocity.x *= -1;
	}

	if (location.y < 0)
	{
		kleur = ofColor (ofRandom(100,255),ofRandom(0,150),ofRandom(100,255));
		location.y =  0;
		velocity.y *= -1; 
	}

	if (location.y > ofGetHeight() - radius/2*massa)
	{
		kleur = ofColor (ofRandom(100,255),ofRandom(0,150),ofRandom(100,255));
		location.y =  ofGetHeight() - radius/2 * massa;
		velocity.y *= -1; 
	}
}

void Image :: display(ofPixels workspace2_) 
{
	workspace2 = workspace2_;
	image.setFromPixels(workspace2); 

	ofSetColor(kleur);
	image.draw(location.x,location.y,radius*massa,radius*massa);
}