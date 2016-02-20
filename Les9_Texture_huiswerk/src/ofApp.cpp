#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);


	// Hier wordt een licht in de 3D ruimte geplaats
	licht.setPointLight(); 
	licht.setPosition(ofRandom(50,200),ofRandom(50,200),ofRandom(50,200));

	afbeelding1.loadImage("plaatje1.jpg");
	afbeelding2.loadImage("plaatje2.jpg");
	afbeelding3.loadImage("plaatje3.jpg");

	ofEnableDepthTest(); // Wat is dit ?? 
}

//--------------------------------------------------------------
void ofApp::update()
{
		ofBackground(ofRandom(0,255),30,ofRandom(100,255));
}

//--------------------------------------------------------------
void ofApp::draw()
{
	// Texture passen maken voor object
	glMatrixMode(GL_TEXTURE); 
	glPushMatrix(); 
	ofScale(afbeelding1.getWidth(),afbeelding1.getHeight()); 

	// Camera aan 
	camera.begin();

	//  Licht aan zetten 
	licht.enable(); 
	licht.draw(); 

		// Maakt van afbeelding texture 
		afbeelding1.bind(); 
		ofDrawSphere(ofRandom(-50,-100),90,0,ofRandom(20,100));
		// Texture uit zetten 
		afbeelding1.unbind(); 


		
	// Licht uit zetten 
	licht.disable(); 

	// Camera uit zetten 
	camera.end(); 

	 // dit maakt de texture-schaal-instellingen van boven weer ongedaan
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);


	// Texture passen maken voor object
	glMatrixMode(GL_TEXTURE); 
	glPushMatrix(); 
	ofScale(afbeelding2.getWidth(),afbeelding2.getHeight()); 

	// Camera aan 
	camera.begin();

	//  Licht aan zetten 
	licht.enable(); 
	licht.draw(); 

		// Maakt van afbeelding texture 
		afbeelding2.bind(); 
		ofDrawSphere(100,0,0,ofRandom(100,150));
		// Texture uit zetten 
		afbeelding2.unbind(); 


		
	// Licht uit zetten 
	licht.disable(); 

	// Camera uit zetten 
	camera.end(); 

	 // dit maakt de texture-schaal-instellingen van boven weer ongedaan
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);


		// Texture passen maken voor object
	glMatrixMode(GL_TEXTURE); 
	glPushMatrix(); 
	ofScale(afbeelding3.getWidth(),afbeelding3.getHeight()); 

	// Camera aan 
	camera.begin();

	//  Licht aan zetten 
	licht.enable(); 
	licht.draw(); 

		// Maakt van afbeelding texture 
		afbeelding3.bind(); 
		ofDrawSphere(100,300,100,ofRandom(150,250));
		// Texture uit zetten 
		afbeelding3.unbind(); 


		
	// Licht uit zetten 
	licht.disable(); 

	// Camera uit zetten 
	camera.end(); 

	 // dit maakt de texture-schaal-instellingen van boven weer ongedaan
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

}

