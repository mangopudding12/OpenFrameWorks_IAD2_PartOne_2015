#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

	af = 0;			
	hoeveelheid = 1; 

	// Dingen inladen 
	myfont.loadFont("verdana.ttf", 15);
	dood.loadSound("HIHI.mp3");

	
	for (int t = 0; t < hoeveelheid; t++)
	{
		Rat newratten; 
		newratten.setup(); 
		ratten.push_back(newratten); 
	}
	

	BalkL = Balk(); 
	BalkL.setup(); 
}

//--------------------------------------------------------------
void ofApp::update()
{

	for (int t = 0; t < ratten.size(); t++)
	{
		ratten[t].ren();  



		// Hoi Edwin
		// Hieronder zit een probleem. 
		// Hierdoor zorgt de balk er soms wel voor dat de vierkant bounce 
		// Maar soms luisteren de vierkanten ook gewoon niet en gaan er dwars door heen. 
		// Weet jij waardoor het komt ? 

		if (ratten[t].x  <=  BalkL.x + BalkL.breedte && ratten[t].x >= BalkL.x)
		{
			if (ratten[t].y >= BalkL.y && ratten[t].y <= BalkL.y + BalkL.hoogte)
			{
					ratten[t].speedX *= -1;
					cout << ratten[t].speedX << endl; 
			}
		}


		
		if (ratten[t].x < 0)
		{
			ratten.erase(ratten.begin()+t);
			af +=1; 
			
			dood.play(); 
		}
	}


	
	if (ratten.size() == 0)
	{
		for (int t = 0; t < hoeveelheid; t++)
		{
			Rat newratten; 
			newratten.setup(); 
			ratten.push_back(newratten); 
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{

	ofSetColor(0);
	myfont.drawString("Bal     van scherm af:", 700,30);

	// Zo zet je int op het scherm !!!! door std::to_string( Hier is variable)
	myfont.drawString( std::to_string(af), 750,30);
	

	for (int t = 0; t < ratten.size(); t++)
	{
		ratten[t].display(); 
	}

	BalkL.display(); 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 97)
	{
		speedBalk = -20; 
		BalkL.move(speedBalk);
	} else if (key == 100) { 
		speedBalk = 20; 
		BalkL.move(speedBalk);
	}

 }

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

