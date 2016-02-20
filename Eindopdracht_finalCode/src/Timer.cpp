#include "Timer.h"

Timer :: Timer () 
{

}

void Timer :: start () 
{ 
	savetime = ofGetElapsedTimeMillis(); 
} 

void Timer:: bereken_eindtijd()
{
	eindtijd = ofGetElapsedTimeMillis() - savetime;
}


void Timer :: tikking () 
{ 
	passedTime = ofGetElapsedTimeMillis() - savetime;				
} 

void Timer :: finished () 
{

	if (passedTime > eindtijd)
	{
		klaar = true; 
	} else { 
		klaar = false; 
	}
}
