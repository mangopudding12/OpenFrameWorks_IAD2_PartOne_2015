#include "Aarde.h"

Aarde :: Aarde (float x_, float y_) 
{
	float x = x_; 
	float y = y_;

	location.set(x, y);
} 

void Aarde :: setup() 
{ 
	kleur = ofColor(ofRandom(100,255),ofRandom(100,255),ofRandom(0,100));
	massa = 80;

	afbeelding1.loadImage("planeet.png");
	afbeelding2.loadImage("poort.png");
}

void Aarde :: attractor (float massa_spook, ofVec2f location_spook,int afstroten_ja_nee,float zwaartekrachtconstante_)
{
	zwaartekrachtconstante = zwaartekrachtconstante_;

	ofVec2f force; 
	force = location - location_spook; 
	float distance = force.length(); //  is de afstand tussen Aarde en de spook 

	// Minimum & maximum zetten 
	if (distance < 5.0)
	{
		distance = 5.0; 
	} else if (distance > 25.0) { 
		distance = 25.0; 
	}

	force.normalize(); 
	float strength = ((zwaartekrachtconstante*massa*massa_spook) / (distance/distance)); 
	strength *= afstroten_ja_nee;

	force *= strength; 
	
	
	force_final = force; 
}

void Aarde :: display(int welkeplaatje_) 
{
	ofSetColor(255,255,255);
	//ofSetCircleResolution(100);
	//ofEllipse(location.x,location.y,massa,massa);

	welkeplaatje = welkeplaatje_;

	if (welkeplaatje == 1) // aarde
	{
		afbeelding1.draw(location.x-massa,location.y-massa,massa*3,massa*3);

	} else if (welkeplaatje == 2) { // duistere poort
		afbeelding2.draw(location.x-massa,location.y-massa,massa*2.5,massa*2.5);
	}




}