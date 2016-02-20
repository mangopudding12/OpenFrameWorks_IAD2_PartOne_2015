
#pragma once 

#include "ofMain.h"

class Timer 
{

public:
	Timer () { } 
	Timer(int eindtijd_); 

	void start(); 
	void tikking(); 
	void finished(); 

	float savetime; 
	float passedTime; 
	int eindtijd; 

	bool klaar; 

private: 






};