#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	image.loadImage("HOI.jpg");

	for (int y = 0; y < MESH_HEIGHT; y++)
	{
		for (int x = 0; x < MESH_WIDTH; x++)
		{
			ofPoint vertex = ofPoint((x-MESH_WIDTH/2)*MESH_SIZE,(y - MESH_HEIGHT/2)*MESH_SIZE,0);

			mesh.addVertex(vertex);
			mesh.addTexCoord(ofPoint(x*(IMAGE_WIDTH/MESH_WIDTH),y*(IMAGE_HEIGHT/MESH_HEIGHT)));


			ofColor color = ofColor(255,255,255); 
			mesh.addColor(color);
		}
	}

	for (int y = 0; y < MESH_HEIGHT-1; y++)
	{
		for (int x = 0; x < MESH_WIDTH-1; x++)
		{
			int vertex1 = x + MESH_WIDTH * y; 
			int vertex2 = x+1 + MESH_WIDTH * y;
			int vertex3 = x + MESH_WIDTH * (y+1); 
			int vertex4 = x + 1 + MESH_WIDTH * (y+1);

			mesh.addTriangle(vertex1,vertex2,vertex3);
			mesh.addTriangle(vertex2,vertex4,vertex3); 
		}
	}

}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int y = 0; y < MESH_HEIGHT; y++)
	{
		for (int x = 0; x < MESH_WIDTH; x++)
		{
			int index = x + MESH_WIDTH *y;
			ofPoint vertex = mesh.getVertex(index);
			vertex.z = ofNoise(x*0.05, y*0.05, ofGetElapsedTimef()*0.5)*100;
			mesh.setVertex(index,vertex);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(0);

	camera.setVFlip(0);
	camera.begin(); 
		image.bind();
		mesh.draw();
		//mesh.drawWireframe();
		image.unbind();
	camera.end(); 
}
