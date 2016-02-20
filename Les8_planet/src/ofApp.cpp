#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60); 
	ofBackground(30,30,30); 
	drawGrid = false; 


	// aanmaken van planets 
	planet01.setup("planet 1",1); 
	planetParams.add(planet01.planetParamGroup);

	planet02.setup("planet 2",1); 
	planetParams.add(planet02.planetParamGroup);

	planet03.setup("planet 3",1); 
	planetParams.add(planet03.planetParamGroup); 

	planet04.setup("planet 4",-1);
	planetParams.add(planet04.planetParamGroup); 
	
	planet05.setup("planet 5",-1);
	planetParams.add(planet05.planetParamGroup); 




	gui.setup(planetParams); 
	light.setDirectional(); 
	light.setPosition(-200,-200,-200);
	light.lookAt(ofVec3f(0,0,0),ofVec3f(0,0,0));
	light.setDiffuseColor(ofColor(255,255,255)); 
	light.enable(); 
}

//--------------------------------------------------------------
void ofApp::update()
{
	// update alle planeten 
	planet01.update(); 
	planet02.update(); 
	planet03.update(); 
	planet04.update();
	planet05.update();

	cout << planet03.welkekantop << endl;
}

//--------------------------------------------------------------
void ofApp::draw()
{
	gui.draw(); 
	ofEnableDepthTest(); 
	cam.begin(); 
	
	if (drawGrid)
	{
		ofDrawGrid(200);
	}


	ofPushMatrix();
		planet01.draw();
		ofTranslate(planet01.distance,0);
		planet02.draw();

		ofTranslate(planet02.distance,0);
		planet03.draw(); 
	  
	ofPopMatrix();

	
	ofPushMatrix();
		planet01.draw();

		ofTranslate(planet01.distance,0);
		planet04.draw();

		ofTranslate(planet04.distance,0);
		planet05.draw();
	ofPopMatrix();


	cam.end();
	ofDisableDepthTest(); 
}

void ofApp:: keyPressed(int key)
{
	if (key == 'g')
	{
		drawGrid = !drawGrid; 
	}
}