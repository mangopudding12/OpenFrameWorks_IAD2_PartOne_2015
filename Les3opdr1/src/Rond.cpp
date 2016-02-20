#include "ofMain.h"
#include "Rond.h"

RondH::RondH()
{

}



void RondH::display()
{
	ofSetColor(kleur1-50,kleur2-50,kleur3-50);
	ofSetCircleResolution(100);
	ofEllipse(X,Y,radius,radius); 
}


