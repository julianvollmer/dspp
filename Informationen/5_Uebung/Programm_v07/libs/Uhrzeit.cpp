/*
 * Uhrzeit.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Uhrzeit.h"
Uhrzeit::Uhrzeit(){
	stunde = liefere_ganze_zufallszahl(0,23);
	minute = liefere_ganze_zufallszahl(0,59);
	sekunde = liefere_ganze_zufallszahl(0,60);
}

Uhrzeit::~Uhrzeit(){

}

void Uhrzeit::zeige_uhrzeit(){
	cout << stunde << ":" << minute << ":" << sekunde;
}

string Uhrzeit::get_uhrzeit(){
	ostringstream wandler(ios::out);
	  wandler  << stunde << ":" << minute << ":" << sekunde;
	  return wandler.str();
}
