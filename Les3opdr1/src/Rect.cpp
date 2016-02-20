
#include "ofMain.h"
#include "RectH.h"


RectH::RectH()
{

}



void RectH::display()
{
	ofSetColor(kleur1-100,kleur2-100,kleur3-100);
	ofRect(X,Y,radius,radius); 
}


