#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	image.loadImage("hoi.jpg"); 
	
	// Als je mooiere bal wilt zet resolutie hoger.
	sphere.setRadius(200);
	sphere.setResolution(MESH_SIZE); 

	sphere.mapTexCoordsFromTexture(image.getTextureReference());
	ofMesh& mesh = sphere.getMesh(); 

	for (int index = 0; index < mesh.getNumVertices(); index++)
	{
		ofPoint vertex = mesh.getVertex(index);
		origz.push_back(vertex.z);
	}


	light.setPointLight(); 
	light.setPosition(400,400,400);
	light.enable(); 
}

//--------------------------------------------------------------
void ofApp::update()
{
	ofMesh& mesh = sphere.getMesh(); 

	for (int y = 0; y < MESH_SIZE*2; y ++)
	{
		for (int x = 0;  x < MESH_SIZE; x++)
		{
			int index = x + MESH_SIZE * y; 

			ofPoint vertex = mesh.getVertex(index); 

			vertex.z = origz[index] + ofNoise (x*0.05,y*0.05,ofGetElapsedTimef()*5)*50-25;
			mesh.setVertex(index, vertex);

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
	ofEnableDepthTest(); 

	image.bind(); 
	sphere.draw();
	//sphere.drawWireframe();
	image.unbind(); 
	ofDisableDepthTest();

	cam.end(); 

}
