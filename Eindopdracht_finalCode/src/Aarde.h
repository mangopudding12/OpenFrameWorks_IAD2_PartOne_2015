#pragma once 
#include "ofmain.h"

class Aarde
{
public: 

	Aarde() { }; // Default constructor -- anders doet andere contructor het niet. 
	Aarde (float x_, float y_); 

	// functions 
	void setup (); 
	void attractor(float massa_spook, ofVec2f location_spook,int afstroten_ja_nee,float zwaartekrachtconstante_); 
	void display(int welkeplaatje_); 

	// variable 
	ofVec2f location;		// x and y 
	ofVec2f force_final; 
	ofColor kleur; 
	int welkeplaatje;
	ofImage afbeelding1; 
	ofImage afbeelding2; 

	int massa; 
	float zwaartekrachtconstante; // kracht zwakker of sterker mee maken

private: 
};