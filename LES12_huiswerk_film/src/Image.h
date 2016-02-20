#include "ofmain.h"

class Image
{
public: 

	Image() { }; // Default constructor -- anders doet andere contructor het niet. 
	Image (int massa_,float radius_,float x_ ); 

	// functions 
	void setup (); 
	void bounce(); 
	void applyforce(ofVec2f); 
	void move(); 
	void display(ofPixels workspace2_); 

	// variable 
	ofVec2f velocity;		// speed
	ofVec2f location;		// x and y 
	ofVec2f accelaration;   // versnellen - verlangzamen 

	int maxspeed; 
	ofColor kleur; 
	float radius; 
	int massa; 
	ofImage image; 
	ofPixels workspace2; 

private: 
}; 