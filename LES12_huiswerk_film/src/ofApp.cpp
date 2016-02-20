#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{
	grabber.setDeviceID(0);
	grabber.initGrabber(CAM_WIDTH,CAM_HEIGHT); 
	grabber.setDesiredFrameRate(30);

	workspace.allocate(CAM_WIDTH,CAM_HEIGHT,OF_IMAGE_COLOR);

	hoeveelheid = 10;

	for (int h = 0; h < hoeveelheid; h ++)
	{
		Image newplaatje = Image(15 , 2 + (h*2), (h*2)); 
		newplaatje.setup(); 
		plaatje.push_back(newplaatje);
	}

	wind.set(0.01,0);
	wgrote = 100; 

	
	for (int h = 0; h < hoeveelheid; h ++)
	{
		zwaartekracht.set(0,0.02f*plaatje[h].massa);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	grabber.update(); 

	if (grabber.isFrameNew())
	{
		ofPixels pixels = grabber.getPixelsRef(); 

		for (int y = 0; y < pixels.getHeight(); y ++)
		{
			for (int x = 0; x < pixels.getWidth(); x++)
			{
				ofColor col = pixels.getColor(x,y); 
				col.r = 255 - col.r;
				col.g = 255 - col.g; 
				col.b = 255 - col.b; 

				workspace.setColor(x,y,col);
			}
		}
	}

	for (int h = 0; h < hoeveelheid; h ++)
	{
	
		plaatje[h].applyforce(wind); 
		plaatje[h].applyforce(zwaartekracht); 

		weerstand *= 0; 

		if (plaatje[h].location.x + wgrote*3 > ofGetWidth())
		{
			weerstand.x = (plaatje[h].location.x / (ofGetWidth())) * -0.05;
		

		} else if (plaatje[h].location.x - wgrote*2.5 < 0) { 
			// Waarom is deze eigenlijk niet nodig ?? 
			weerstand.x =  (plaatje[h].location.x / ofGetWidth()) * 0.02;
		}
	

		


		plaatje[h].applyforce(weerstand);  

		for (int h = 0; h < hoeveelheid; h ++)
		{
			zwaartekracht.set(0,0.01f*plaatje[h].massa);
		}

		plaatje[h].bounce();
		plaatje[h].move();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	grabber.draw(0,0);
	
	for (int h = 0; h < hoeveelheid; h ++)
	{
		plaatje[h].display(workspace);
	}
}

