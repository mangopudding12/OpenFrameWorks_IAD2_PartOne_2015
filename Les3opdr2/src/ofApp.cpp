#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

	hoeveelheid = 1;
	eenMEER = 0; 

	for (int i = 0; i < hoeveelheid; i++)
	{
		// Pakt de class en maakt een nieuw object aan.
		DrieHoek newDriehoek;

		// Waarom ????? 
		newDriehoek.setup(); 

		// Waarom ??????? 
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
	for (int i = 0; i < Drie.size(); i++)
	{
		Drie[i].display(); 
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
		
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

	 // Print het nummer van de toets 
	 cout << "keyPressed " << key << endl;


	if (key == 32) // spacebar
	{
			eenMEER += 1;

			for (int i = 0; i < eenMEER; i++)
			 {
					DrieHoek newDriehoek;
					newDriehoek.setup(); 
					Drie.push_back(newDriehoek);

					eenMEER = 0;  // Hier door krijg je maar 1 vorm per keer dat je toets indrukt 
			}
	} else if (key == 100) {  // d
		
			// Zorgt ervoor dat je nooit een error krijgt 
			// Dat je DrieHoeken wilt verwijderen hoewel ze al niet meer bestaan. 
			if (Drie.size() > 0)
			{
				  // Verwijder een driehoek
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
