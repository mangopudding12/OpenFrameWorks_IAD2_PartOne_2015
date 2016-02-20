
#include "ofMain.h"
#include "DrieH.h"

DrieH::DrieH()
{

}



void DrieH::display()
{
	ofSetColor(kleur1-200,kleur2-200,kleur3-200);
	ofSetCircleResolution(3);
	ofEllipse(X,Y,radius,radius); 
}