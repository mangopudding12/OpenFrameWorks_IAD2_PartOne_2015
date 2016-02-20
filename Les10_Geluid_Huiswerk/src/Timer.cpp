#include "Timer.h"


Timer :: Timer (int eindtijd_) 
{ 
	eindtijd = eindtijd_; 
}



void Timer ::  start() 
{
	savetime = ofGetElapsedTimeMillis(); 
}


void Timer :: tikking() 
{
	passedTime = ofGetElapsedTimeMillis() - savetime; 
} 

void Timer :: finished () 
{ 
	if (passedTime >= eindtijd)
	{
		klaar = true; 
	} else { 
		klaar = false; 
	}
} 

