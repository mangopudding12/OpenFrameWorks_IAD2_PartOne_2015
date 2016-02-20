#include "ofApp.h"



void ofApp::setup()
{

	// --------------------- Arduino & servo & lichtsensor & timer -------------------------------
		
		// Arduino connexting
			ofAddListener(Arduino.EInitialized, this, &ofApp::setupArduino); 
			arduino_opstarten = false; 
 			Arduino.connect("COM3", 57600); // aan deze poort zit de arduino 
			Arduino.sendFirmwareVersionRequest(); 

		// BELANGRIJK STUK ALS JE CODE WILT TESTEN !!!
			// Wanneer het nacht is heb je deze settings nodig. 
				//zaklamp_aan = 190; 
				//zaklamp_aan_extreem = 220;

			// overdag 
				zaklamp_aan = 70;
				zaklamp_aan_extreem = 110;

		
		// Timer settings gereed zetten
			for (int k = 0; k < Sensors; k++)
			{
				TimerReached[k] = false;
				TimerReached_extreem[k] = false;

				licht_gekregen[k] = false;  
				fase[k] = 0; 
				fase_extreem[k] = 0; 
			}
	

		// Maximum van lichtsensors
			maximum = 1100; 
			
		// Stappen schema
			state = 0; 

		// Bonussen waarde 
			bonus1 = 4000; // wanneer de lichtsensor 4 seconden extreem veel licht krijgt --> deze lichtsensor krijgt een bonus zodat spook langer weg blijft.  
			bonus2 = 2000; // 2 seconden
			bonus3 = 1000; // 1 seconden 



	// --------------------- Aarde & Duisterenpoort & Aantrekkingskracht ------------------------------


		// aanroepen van de constructor 
			aarde1 = Aarde(ofGetWidth()/2 - 40,ofGetHeight()/2); 
			aarde1.setup(); 

			duisterpoort[0] = Aarde(70,620); 
			duisterpoort[1] = Aarde(70,80); 
			duisterpoort[2] = Aarde(910,80); 
			duisterpoort[3] = Aarde(910,620); 

		// Setup functie van duisterenpoorten
			for(int r = 0; r < Sensors; r++)
			{
				duisterpoort[r].setup();
				aan[r] = false;
			}

		// Setup functie van de array spoken
			for(int a = 0; a < aantal; a++)
			{
				spook1[a] = Spook(ofRandom(3.5,6.5),ofRandom(300,600),ofRandom(300,600));
				spook1[a].setup(); 
			}

		// achtergrond plaatje inladen
			achtergrond.loadImage("achtergrond.jpg");
}





//.................... Beste Paul hier is de Arduino setup gedeelte .....................
void ofApp::setupArduino(const int& version) 
{
	// Arduino opstarten 
		ofRemoveListener(Arduino.EInitialized, this, &ofApp::setupArduino);
		arduino_opstarten = true; 

	 // Servo's vertellen aan welke pin ze zitten.
		for (int k = 2; k < Servos; k++)
		{ 	
				Arduino.sendServoAttach(k); // servo 1 = pin 2 --- servo 2 = pin 3
				Arduino.sendServo(k, 0, false);
		}

	 // Lichtsensor vertellen aan welke pin ze zitten.
		 for (int k = 0; k < Sensors; k++)
		{
				Arduino.sendAnalogPinReporting(k, ARD_ANALOG); // lichtsensor 1 = pin 0 -- lichtsensor 2 = pin 1 
		 }

	 // Lampjes vertellen aan welke pin ze zitten.
		 for (int k = 8; k < Lampjes; k++) // lampjes
		{
			 Arduino.sendDigitalPinMode(k, ARD_OUTPUT); // lichtsensor 1 = pin 0 -- lichtsensor 2 = pin 1 
			Arduino.sendDigital(k+8,ARD_HIGH);
		 }

    // Lisenaars voor de analoge arduino poorten 
		ofAddListener(Arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}




//--------------------------------------------------------------
void ofApp::update()
{
	Arduino.update();

	// Hier wordt vertel aan de spoken wanneer ze aangetrokken worden aan de aarde. 
	// En wanneer de spoken worden afgestoten en worden aan getrokken door de duistere poorten.
		for(int r = 0; r < Sensors; r++)
		{
			if (aan[r] == true)
			{
				for(int a = 0; a < aantal; a++)
				{
					aarde1.attractor(spook1[a].massa,spook1[a].location,1,0.0001); // als je dit getal lager zet gaan de spook random verplaatsen --> hoe hoger hoe gerichter ze naar de lichtsensor gaan die licht ontvangt
					spook1[a].applyforce(aarde1.force_final);

					for(int r = 0; r < poorten; r++)
					{
						duisterpoort[r].attractor(spook1[a].massa,spook1[a].location,-1,0.00000003);
						spook1[a].applyforce(duisterpoort[r].force_final);
					}
				}
			}


			if (aan[r] == false)
			{
				for(int a = 0; a < aantal; a++)
				{
					aarde1.attractor(spook1[a].massa,spook1[a].location,-1,0.0009);
					spook1[a].applyforce(aarde1.force_final);

					duisterpoort[r].attractor(spook1[a].massa,spook1[a].location,1,0.0003);
					spook1[a].applyforce(duisterpoort[r].force_final);
				}
			}
		}


		// Spoken bounce van de zijkant van de het scherm
		// Spoken bewegen
			for(int a = 0; a < aantal; a++)
			{
				spook1[a].bounce(); 
				spook1[a].move(); 
			}
}



// ............ Beste Paul hier ontvang ik de analoge data van de arduino pinnen ................. 
void ofApp:: analogPinChanged(const int & pinNum)
{
	 
	// State 0 gebruik ik om het minimum van alle lichtsensor gelijk te zetten met het omgevings licht.
	if (state == 0) 
	{
		 for (int k = 0; k < Sensors; k++)
		 {
			sersorvalua[k] = Arduino.getAnalog(k);

			if (sersorvalua[k] > 0) // zet omgeving licht als minimum zodat pas reageert als die meer licht ontvangt. 
			{
				minimum[k] = sersorvalua[k]; 
			} else {
				minimum[k] = 0; 
			}

			Arduino.sendServo(k+2, 0, false);
			Arduino.sendDigital(k+8,ARD_LOW);
            aan[k] = true; // spoken aan getrokken tot aarde omdat het licht uit is.  

			cout << "minimum = " << minimum[k] << endl;  
		 }

		// Mimimums zijn berekent -- ga nu naar fase 2       
			state = 2; 



		// ...........................Fase 2 ........................................................


	}  else if (state == 2){ 
		
		// Data light sensor uitvangen -- bruikbaar maken -- tussen 0 en 255 getallen
		for (int k = 0; k < Sensors; k++)
		{
			sersorvalua[k] = Arduino.getAnalog(k);
			lichtwaardes[k] = ofMap(sersorvalua[k],minimum[k],maximum,0,255); 

			
			// Als de lichtsensor een hogere waarden dan zaklamp_aan ontvangen 
			if (lichtwaardes[k] > zaklamp_aan)
			{  
				if (TimerReached[k] == false) 
				{

					// Start de timer zodat die de begin tijd onthoud wanneer hij voor het eerst zaklamp licht kreeg.
					if (fase[k] == 0)
					{
						tijd[k].start(); 
						fase[k] = 1; 

						cout << "Sensor "  << k  << "____Fase normaal gestart____" << endl; 
					}
				

					licht_gekregen[k] = true; 
						

						// Servo omlaag 
						if (k == 0) // servo aan pin 2 heeft een afwijking van daar die wel op 180 graden draait.
						{	
							Arduino.sendServo(k+2, 180, false);
						} else { 
							Arduino.sendServo(k+2, 160, false);
						}

						aan[k] = false; // spoken aangetrokken tot duistere poort
				}

				
				
				if (TimerReached_extreem[k] == false) 
				{
					
					// Wanneer je de zaklamp heel dicht op de lichtsensor hou krijgt die zoveel licht dat de extreem zaklamp aan gaat.
					if (lichtwaardes[k] > zaklamp_aan_extreem)
						{

							// onthoud begin tijd wanneer die voor het eerst deze lichtsterkte kreeg.
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

					// Hier wordt berekend hoelang de lichtsensor de extreem lichtwaarde heeft gekregen. 
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

					// Hier wordt berekend hoelang de lichtsensor een normale lichtwaarde heeft gekregen. Dit wordt de eindtijd van nieuwe timer.
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

						// Heeft de lichtsensor een bonus verdient ?? 
						if (tijd_extreme[k].eindtijd > 2)
						{
							cout << "Sensor:  "  << k  << "__Heeft zolang:  " << tijd_extreme[k].eindtijd << "  Extreem veel licht gehad" << endl;
						}

						// Bonus tijd erbij als die extreem veel licht heeft ontvangen 
						if (tijd_extreme[k].eindtijd > 7000)
						{
							cout << "Hoera  "  << "Sensor:   "  << k  << "__Heeft een Bonus nummer 1" << endl; 
							tijd[k].eindtijd += bonus1;
	
						} 
						
						if (tijd_extreme[k].eindtijd > 4000 && tijd_extreme[k].eindtijd < 6900){

							cout << "Hoera  "  << "Sensor:  "  << k  << "__Heeft een Bonus nummer 2 " << endl; 
							tijd[k].eindtijd += bonus2;
							
						}
						
						if (tijd_extreme[k].eindtijd > 1500 && tijd_extreme[k].eindtijd < 3900 ){
							cout << "Hoera  "  << "Sensor:   "  << k  << "__Heeft een Bonus nummer 3" << endl; 
							tijd[k].eindtijd += bonus3;
						}

						// Geeft de timer een nieuwe start tijd.
						tijd[k].start();

						// Aarde licht gaat aan en verjaargd spoken.  
						Arduino.sendDigital(k+8,ARD_HIGH); 
					
						fase[k] = 3; 
					}


					// Dw timer gaat tikking en tik zolang als je hem licht hebt gegeven met de zaklamp.
					// Tenzij die een bonus heeft gekregen als die extreem veel licht heeft gekregen.
					if (fase[k] == 3)
					{
						tijd[k].tikking(); // Deze doet het !!! 

						if (tijd[k].passedTime > tijd[k].eindtijd)
						{
							Arduino.sendServo(k+2, 0, false);
							Arduino.sendDigital(k+8,ARD_LOW); // lichtjes uit spoken komen weer omhoog
							aan[k] = true; // spoken worden aangetrokken tot de aarde

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






//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(255,255,255,80);
	achtergrond.draw(0,0,ofGetWidth(),ofGetHeight());

	for(int r = 0; r < poorten; r++)
	{
			duisterpoort[r].display(2);
	}

	
	for(int a = 0; a < aantal; a++)
	{
		
		aarde1.display(1);
	}

	for(int a = 0; a < aantal; a++)
	{
		if (a <= aantal/2)
		{
			spook1[a].display(2); 
		} else {
			spook1[a].display(1); 
		}
	}
}


 //-------------------------------------------------------------
void ofApp:: exit() 
{
	Arduino.disconnect();
}