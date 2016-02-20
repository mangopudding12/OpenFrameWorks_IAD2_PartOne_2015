#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	 hoeveelheid = 20; 

	  for (int t = 0; t < hoeveelheid; t++)
	  {
		  // Vraag je ????????? 
		  // newDrieHoek 
		  // Waarom maak je dit aan als je het niet gebruik voor de bounce functie ??? 
		  // Waarom gebruik je voor de bounce functie weer nogmale vector DrieHoek ????
		  // waar gebruik je daar niet de newDrieHoek voor die speciaal aan maakt ??? 

		  DrieH newDrieHoek;
		  newDrieHoek.setup(); 
		  DrieHoek.push_back(newDrieHoek);
	  }

	  for (int t = 0; t < hoeveelheid; t++)
	  {
		  RectH newVierKant;
		  newVierKant.setup(); 
		  VierKant.push_back(newVierKant);
	  }


	  for (int t = 0; t < hoeveelheid; t++)
	  {
		  RondH newRondjes;
		  newRondjes.setup(); 
		  Rondjes.push_back(newRondjes);
	  }
}

//--------------------------------------------------------------
void ofApp::update()
{
	 
	  for (int t = 0; t < DrieHoek.size(); t++)
	  {
		  DrieHoek[t].bounce(); 
		  VierKant[t].bounce(); 
		  Rondjes[t].bounce(); 
	  }
	  
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
	  for (int t = 0; t < DrieHoek.size(); t++)
	  {
		  DrieHoek[t].display(); 
	  }

	   for (int u = 0; u < DrieHoek.size(); u++)
	   {
		   Rondjes[u].display(); 
	   }


	  for (int t = 0; t < DrieHoek.size(); t++)
	  {
		   VierKant[t].display(); 
	  }
	 	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
