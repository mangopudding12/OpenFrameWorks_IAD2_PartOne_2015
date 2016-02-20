#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60); 

	drawGrid = true; 

	gui.setup(); 
	gui.add(rotateSpeedX.set("X",0,0,9.0)); // Label naam -- Beginwaarde -- Minimum -- Maximum 
	gui.add(rotateSpeedY.set("Y",0,0,9.0));
	gui.add(rotateSpeedZ.set("Z",0,0,9.0));

	rotationX = 0; 
	rotationY = 0; 
	rotationZ = 0; 
}

//--------------------------------------------------------------
void ofApp::update()
{
	rotationX += rotateSpeedX; 
	rotationY += rotateSpeedY; 
	rotationZ += rotateSpeedZ; 
}

//--------------------------------------------------------------
void ofApp::draw()
{
	gui.draw(); 

	ofTranslate(ofGetWidth()/2,ofGetHeight()/2);


	ofRotateX(rotationX);

	ofSetColor(255,0,0); 
	ofCircle(-300,0,130); 

	ofRotateY(rotationY); 	 
	
	ofSetColor(0,255,0); 
	ofCircle(0,0,130); 

	ofRotateZ(rotationZ); 

	ofSetColor(0,0,255); 
	ofCircle(300,0,130); 



	if (drawGrid)
	{
		ofDrawGrid(200); 
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'g')
	{
		drawGrid =! drawGrid; 
	}
}
