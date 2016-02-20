#include "ofApp.h"

// Test de snor die bij je past 

//--------------------------------------------------------------
void ofApp::setup()
{
		grabber.setDeviceID(0);
		grabber.initGrabber(CAM_WIDTH,CAM_HEIGHT); 
		grabber.setDesiredFrameRate(30);
	
	video.loadMovie("snorfilmpje7.mp4");
	video.play(); 
}

//--------------------------------------------------------------
void ofApp::update()
{
	ofBackground(255);
	video.update(); 

		grabber.update(); 

}

//--------------------------------------------------------------
void ofApp::draw()
{
		ofSetColor(255,255,255,255);
		grabber.draw(0,0);

		ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		grabber.draw(ofRandom (ofGetWidth()/2, (ofGetWidth()/2)+62),0);
	
		ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		grabber.draw(0,ofGetHeight()/2,ofRandom(450,512),384);

		ofSetColor(255,255,255,255);
		grabber.draw(ofGetWidth()/2,ofGetHeight()/2);

		ofSetColor(255,255,255,50);
		ofScale(0.25,0.25);

		video.draw(800,600);
		video.draw(2850,2100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}
