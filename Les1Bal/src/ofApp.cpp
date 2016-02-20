#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup()
{
	 hoeveelheid = 20; 

	  for (int t = 0; t < hoeveelheid; t++)
	  {
		  Rondje newRond;
		  newRond.setup(); 
		  Rond.push_back(newRond);
	  }
}

//--------------------------------------------------------------
void ofApp::update()
{
	 
	  for (int t = 0; t < Rond.size(); t++)
	  {
		  Rond[t].bounce(); 
	  }
	  
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
	  for (int t = 0; t < Rond.size(); t++)
	  {
		  Rond[t].display(); 
	  }
	 	
}
