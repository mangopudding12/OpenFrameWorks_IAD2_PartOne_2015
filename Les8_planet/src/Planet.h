#pragma once

#include "ofMain.h"

class Planet{

	public:
		Planet(); 
		virtual ~Planet(); 

		void setup(string name,int welkekantop_);
		void update();
		void draw();

		float rotation; 
		int welkekantop; 

		ofParameterGroup planetParamGroup; 
		ofParameter<float> rotateSpeed;
		ofParameter<float> distance;

		ofParameter<int> red;
		ofParameter<int> green;
		ofParameter<int> blue;
};
