#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	hoeveelheid = 1; 

	// Vector of pionters naar Rat  
	for (int t = 0; t < hoeveelheid; t++)
	{
		
      ratten.push_back(new Rat());
      ratten.back()->setup();
	}
	

	BalkL = new Balk(); 
	BalkL -> setup(); 
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int t = 0; t < ratten.size(); t++)
	{
		ratten[t] -> ren();  


		if (ratten[t] -> x < 0)
		{
			ratten.erase( ratten.begin());
			delete ratten[t];
			cout << "Buiten het scherm" << endl; 
		}
	}


		

	

	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int t = 0; t < ratten.size(); t++)
	{
		ratten[t] -> display(); 
	}

	BalkL -> display(); 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 97)
	{
		speedBalk = -20; 
		BalkL -> move(speedBalk);
	} else if (key == 100) { 
		speedBalk = 20; 
		BalkL -> move(speedBalk);
	}
 
		// a = 97 -- Naar boven 
		// d = 100 -- Naar beneden
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

// ................. Hier mee verwijder je de pointers die je hebt gebruikt....................
void ofApp::exit() {

	// Gooi alle pionters weg 
    for (int t = 0; t < ratten.size(); t++)
	{
		delete ratten[t];
	}

	delete BalkL; 
}
