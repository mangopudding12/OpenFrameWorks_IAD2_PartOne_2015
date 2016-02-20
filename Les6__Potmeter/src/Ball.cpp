#include "Ball.h"


// Constuctor 
DrieHoek :: DrieHoek()
{

}

void DrieHoek :: setup()
{
	speedX = ofRandom(0.5,1); 
	speedY = ofRandom(0.5,1);

	X = ofRandom(0,ofGetWidth());
	Y = ofRandom(0,ofGetHeight()); 
	radius = ofRandom(40,110); 
	color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));

}


// Int speedpotmeter ontvangt van de ofApp.cpp de data van de potmeter
// Deze gegevens van de potmeter zijn nu alleen bruikbaar in de bounce functie 
void DrieHoek :: bounce(int speedpotmoter)
{

	if (X < 0 || X > ofGetWidth())
	{
		radius = ofRandom(40,110); 
		speedX *= -1;


		// Als aanuit is true zet hem dan op false
		// als aanuit is false zet hem dan op true 
		aanuit = !aanuit; 
	}

	if (Y < 0 || Y > ofGetHeight())
	{
		color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));   
		speedY *= -1;

		// Als aanuit is true zet hem dan op false
		// als aanuit is false zet hem dan op true 
		aanuit = !aanuit; 
	}

	
	// je deelt speedX door 1024 dat is maximale getal wat de potmoter kan geven. 
	// Dus speedX = 1   dus 1 : 1024 = ......... en dit doe je keer het getal van de speedpotmoter. 
	// speedpotmotor is een getal dat ligt waar je hem zelf op schijft. -- maximale snelheid die bal bereikt is 1 
	X += (speedX  / 1024) * speedpotmoter; 
	Y += speedY; 

}


void DrieHoek :: display()
{
	ofSetColor(color);
	ofSetCircleResolution(6);
	ofEllipse(X,Y,radius,radius);




	// Als de arduino aan is doe dit 
	if (arduinoConnected) 
 	{ 

		// Wanneer aanuit is true ?? dan doe dit 
 		if (aanuit) 
		{
			    // Zet pin 8 op hoog doe de lamp aan 
				arduinoO->sendDigital(8, ARD_HIGH); 
		} else { 
			    // zet pin 8 op laag doe de lamp uit 
		 		arduinoO->sendDigital(8, ARD_LOW); 
		}
	} 

}