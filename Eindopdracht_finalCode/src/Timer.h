
#pragma once 
#include "ofMain.h"

class Timer 
{
public: 
	Timer(); 

	void start();
	void bereken_eindtijd(); 
	void tikking(); 
	void finished(); 

	// variable 
	float savetime; 
	float passedTime;
	int eindtijd; 

	// boolean 
	bool klaar; 
private: 


}; 