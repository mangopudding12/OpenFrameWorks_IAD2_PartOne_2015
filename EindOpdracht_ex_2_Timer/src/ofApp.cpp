#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// Arduino stuff
	ofAddListener(Arduino.EInitialized, this, &ofApp::setupArduino); 

    arduino_opstarten = false; 
 	Arduino.connect("COM3", 57600); // aan deze poort zit de arduino 

	Arduino.sendFirmwareVersionRequest(); // Deze regel code niet weg halen anders werkt het niet meer

	// s'nachts 
	// wanneer met zaklamp wordt geschenen: 190 
	//zaklamp_aan = 190; 

	// overdag 
	zaklamp_aan = 150;
	zaklamp_aan_extreem = 200;

	// Timer 
	for (int k = 0; k < Sensors; k++)
	{
		TimerReached[k] = false;
		TimerReached_extreem[k] = false;

		licht_gekregen[k] = false;  
		fase[k] = 0; 
		fase_extreem[k] = 0; 
	}
	
	maximum = 1100; 
	// Stappen schema
	state = 0; 

	// Bonussen 
	bonus1 = 4000; // 4 seconden 
	bonus2 = 2000; // 2 seconden
	bonus3 = 1000; // 1 seconden 
}

//--------------------------------------------------------------
void ofApp::update()
{
	Arduino.update();


}

//--------------------------------------------------------------
void ofApp::draw()
{     
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{     
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}


void ofApp::setupArduino(const int& version) 
{
	// Arduino opstarten 
	ofRemoveListener(Arduino.EInitialized, this, &ofApp::setupArduino);
	arduino_opstarten = true; 

	 // Electronica vertellen welke pinnen ze hebben. 
	 for (int k = 2; k < Servos; k++)
	 { 
			Arduino.sendServoAttach(k); // servo 1 = pin 3 --- servo 2 = pin 4 
			Arduino.sendServo(k, 0, false);
	 }

	 for (int k = 0; k < Sensors; k++)
	 {
			Arduino.sendAnalogPinReporting(k, ARD_ANALOG); // lichtsensor 1 = pin 0 -- lichtsensor 2 = pin 1 
	 }

	 for (int k = 8; k < Lampjes; k++) // lampjes
	 {
		 Arduino.sendDigitalPinMode(k, ARD_OUTPUT); // lichtsensor 1 = pin 0 -- lichtsensor 2 = pin 1 
		 Arduino.sendDigital(k+8,ARD_HIGH);
	 }

	 

    // Lisenaars voor de arduino poorten 
	ofAddListener(Arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	ofAddListener(Arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
}



void ofApp:: analogPinChanged(const int & pinNum)
{
	 

	if (state == 0)
	{
		 for (int k = 0; k < Sensors; k++)
		 {
			sersorvalua[k] = Arduino.getAnalog(k);

			if (sersorvalua[k] > 0) // zet omgeving licht als minimum zodat pas reageert als die meer licht ontvangt. 
			{
				minimum[k] = sersorvalua[k]; 
			}

			Arduino.sendServo(k+2, 0, false);
			Arduino.sendDigital(k+8,ARD_LOW);
			cout << "minimum = " << minimum[k] << endl;  
		 }

		// Mimimums zijn berekent -- ga nu naar fase 2       
		state = 2; 


		// ...........................Fase 2 ........................................................


	}  else if (state == 2){ // Start Experiment met servo's
		
		// Data light sensor uitvangen -- bruikbaar maken -- tussen 0 en 255 getallen
		for (int k = 0; k < Sensors; k++)
		{
			sersorvalua[k] = Arduino.getAnalog(k);
			lichtwaardes[k] = ofMap(sersorvalua[k],minimum[k],maximum,0,255); 

			
			if (lichtwaardes[k] > zaklamp_aan)
			{  

				if (TimerReached[k] == false) 
				{
					if (fase[k] == 0)
					{
						tijd[k].start(); 
						fase[k] = 1; 

						cout << "Sensor "  << k  << "Fase normaallllllllllll gestart" << endl; 
					}
				
					licht_gekregen[k] = true; 
						

						// Servo omlaag 
						if (k == 0) // servo aan pin 2
						{	
							Arduino.sendServo(k+2, 180, false);
						} else { 
							Arduino.sendServo(k+2, 160, false);
						}

					//cout << "Sensor "  << k  << " = veel licht" << endl; 
				}


				if (TimerReached_extreem[k] == false) 
				{
					if (lichtwaardes[k] > zaklamp_aan_extreem)
						{
							if (fase_extreem[k] == 0)
							{
								tijd_extreme[k].start(); 
								fase_extreem[k] = 1;

								cout  << "Sensor "  << k  << "Fase extreem is gestart" << endl;
							}
						}
				 }
			} // end if statement lichtwaardes
		
			
			// Extreem eindtijd berekening 
			if (licht_gekregen[k] == true && lichtwaardes[k] < zaklamp_aan_extreem)
			{ 
				if (TimerReached_extreem[k] == false)
				{
					if (fase_extreem[k] == 1)
					{
							tijd_extreme[k].bereken_eindtijd(); 
							fase_extreem[k] = 2;

							TimerReached_extreem[k] = true; 
					}
				}
			}


			// normale eindtijd berekening
			if (licht_gekregen[k] == true && lichtwaardes[k] < zaklamp_aan)
			{ 
			 
				if (TimerReached[k] == false)
				{

					if (fase[k] == 1)
					{
						tijd[k].bereken_eindtijd(); 
						fase[k] = 2; 

						TimerReached[k] = true; 
					}
				}
			}
	

		
			if (TimerReached[k] == true)
				{
				
					if (fase[k] == 2)
					{
						// Bonus tijd erbij als die extreem veel licht heeft ontvangen 
						if (tijd_extreme[k].eindtijd > 7000)
						{
							cout << "Hoera"  << "Sensor___ "  << k  << "__Bonus_____1___" << tijd_extreme[k].eindtijd << endl; 
							tijd[k].eindtijd += bonus1;
	
						} 
						
						if (tijd_extreme[k].eindtijd > 4000 && tijd_extreme[k].eindtijd < 6900){

							cout << "Hoera"  << "Sensor___ "  << k  << "__Bonus___2__" << tijd_extreme[k].eindtijd << endl; 
							tijd[k].eindtijd += bonus2;
							
						}
						
						if (tijd_extreme[k].eindtijd > 1500 && tijd_extreme[k].eindtijd < 3900 ){
							cout << "Hoera"  << "Sensor___ "  << k  << "__Bonus_3__" << tijd_extreme[k].eindtijd  << endl; 
							tijd[k].eindtijd += bonus3;
						}



						tijd[k].start();

						// Aarde licht gaat aan en verjaargd spoken.  
						Arduino.sendDigital(k+8,ARD_HIGH); 
					
						fase[k] = 3; 
					}

					if (fase[k] == 3)
					{
						tijd[k].tikking(); // Deze doet het !!! 

						if (tijd[k].passedTime > tijd[k].eindtijd)
						{
							cout  << "Sensor: "<< k << " =   Klaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaarrr" << endl;

							// Kijk even of dit gaat werken !!!!!!!!!!!!!1 
							Arduino.sendServo(k+2, 0, false);
							Arduino.sendDigital(k+8,ARD_LOW); // lichtjes uit spoken komen weer omhoog

							fase_extreem[k] = 0; 
							TimerReached_extreem[k] = false;     
							fase[k] = 0; 
							TimerReached[k] = false;  
						}
					
					}
				}
			
		} // end for loop

    } // end state 2 
		
} // end analogefunctie 



void ofApp:: digitalPinChanged(const int & pinNum)
{
}







void ofApp:: exit() 
{
	Arduino.disconnect();
}