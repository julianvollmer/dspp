/*
 * Uhrzeit.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Uhrzeit.h"
/**
 * Initilisiert eine Uhrzeit zufaellig
 */
Uhrzeit::Uhrzeit(){
	stunde = liefere_ganze_zufallszahl(0,23);
	minute = liefere_ganze_zufallszahl(0,59);
	sekunde = liefere_ganze_zufallszahl(0,60);
}

Uhrzeit::~Uhrzeit(){

}
/**
 * Schreibt die Uhrzahl auf den Bildschirm.
 */
void Uhrzeit::zeige_uhrzeit(){
	cout << stunde << ":" << minute << ":" << sekunde;
}
/**
 * @return Liefert die Uhrzeit als String
 */
string Uhrzeit::get_uhrzeit(){
	ostringstream wandler(ios::out);
	  wandler  << stunde << ":" << minute << ":" << sekunde;
	  return wandler.str();
}
