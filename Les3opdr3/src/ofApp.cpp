#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// Waar is dit voor ??? 
	gui.setup("Instellingen","settings.xml");

    gui.add(speedX.setup("speedX",1,0,5)); // via setup
    gui.add(Vorm.setup("vorm",20,0,200)); // via display 
	gui.add(speedY.setup("speedY",1,0,5)); // via constructor 

	// Waar is dit voor ?? 
    gui.loadFromFile("settings.xml");



	hoeveelheid = 1;
	eenMEER = 0; 

	for (int i = 0; i < hoeveelheid; i++)
	{
		DrieHoek newDriehoek(speedY, Vorm);
		newDriehoek.setup(speedX); 
		Drie.push_back(newDriehoek);
	}

	
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i < Drie.size(); i++)
	{
		Drie[i].bounce(); 
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	 gui.draw();


	for (int i = 0; i < Drie.size(); i++)
	{
		Drie[i].display(); // Vorm stuurt gegeven van slider naar de radius van de bewegende vormen.
	}

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	

}

void ofApp::keyReleased(int key)
{


	if (key == 32) // spacebar
	{
					DrieHoek newDriehoek(speedY,Vorm); // ontvangt gegeven van slider stuur het duur naar Driehoek.cpp en voert in en gebruikt het.
					newDriehoek.setup(speedX); 
					Drie.push_back(newDriehoek);
	} 
	

	if (key == 100) {  // d
		
			if (Drie.size() > 0)
			{
				 Drie.erase(Drie.begin());
				 
			}
	} // end if statement 
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
