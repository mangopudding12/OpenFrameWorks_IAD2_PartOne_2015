#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(255,255,255);
	ofSetFrameRate(60);

	video.loadMovie("bendershort.mp4");
	video.play(); 
	video.setLoopState(OF_LOOP_NORMAL); // Loop functie 
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update(); 
}

//--------------------------------------------------------------
void ofApp::draw(){
	video.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

