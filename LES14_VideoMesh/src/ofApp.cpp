#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	video.loadMovie("fingers.mov");
	video.play();

	// Alle ofPiont aanmaken + rekent al die driehoeken meteen uit
	plane.set(MESH_WIDTH,MESH_HEIGHT);
	plane.setResolution(MESH_SIZE_X,MESH_SIZE_Y);
	
	plane.mapTexCoordsFromTexture(video.getTextureReference());
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	video.update();

	if (video.isFrameNew())
	{
		ofMesh& mesh = plane.getMesh(); 

		for (int y = 0; y < MESH_SIZE_Y; y ++)
		{
			for (int x = 0;  x < MESH_SIZE_X; x++)
			{
				int index = x + MESH_SIZE_X * y; 
				ofPoint vertex = mesh.getVertex(index);

				vertex.z = ofNoise(x*0.05,y*0.05,ofGetElapsedTimef()*0.5)*100;
				mesh.setVertex(index,vertex);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(30,30,30); 

	// Camera goed richten
	cam.setVFlip(true);
	cam.begin(); 

	video.getTextureReference().bind();
	plane.drawWireframe();
	video.getTextureReference().unbind(); 

	cam.end(); 
}
