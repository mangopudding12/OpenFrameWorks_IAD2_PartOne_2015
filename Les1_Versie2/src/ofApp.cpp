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
