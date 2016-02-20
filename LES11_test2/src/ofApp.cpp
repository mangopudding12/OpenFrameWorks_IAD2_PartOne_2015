#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//ofBackground(255,255,255);
	//ofSetFrameRate(60);

	video.loadMovie("koe.mp4");
	video.play(); 
	//video.setLoopState(OF_LOOP_NORMAL); // Loop functie 

	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	frameByframe = false;

	// Uncomment this to show movies with alpha channels
	// fingerMovie.setPixelFormat(OF_PIXELS_RGBA);

	fingerMovie.loadMovie("movies/fingers.mov");
	fingerMovie.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update(); 
	fingerMovie.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	video.draw(0,0);
	 fingerMovie.draw(20,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

