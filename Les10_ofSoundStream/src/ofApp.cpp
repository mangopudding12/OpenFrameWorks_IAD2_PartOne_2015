#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofBackground(34,34,34);

	soundStream.listDevices();
	soundStream.setDeviceID(1); // Dit is mijn persoonlijke nummer 1
	soundStream.setup(this,2,0,22050,512,4); 
}

void ofApp::audioOUT(float * output,int bufferSize,int nChannels)
{
	for (int i = 0; i < bufferSize * nChannels; i +=2)
	{
		float sample = sin(phase); 
		output[i] = sample;
		output[i+1] = sample; 
		phase += 0.05; // phase is xas van geluids golf 

	}
}