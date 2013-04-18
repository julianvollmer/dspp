/*
 * Sprechstunde.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Sprechstunde.h"

/*
 * Initialisiert eine Sprechstunde
 */
Sprechstunde::Sprechstunde(){

}

Sprechstunde::~Sprechstunde(){

}
/**
 * Schreibt eine Sprechstunde auf den Bildschirm.
 */
void Sprechstunde::zeige_sprechstunde(){
	tag.zeige_wochentag();
	cout << ", ";
	zeit.zeige_uhrzeit();
}

/**
 * Erfasst einen Sprechstunde
 */
void Sprechstunde::erfasse_sprechstunde(){
	tag.erfasse_wochentag();
}
/**
 * @return Gibt eine Sprechstunde zurueck
 */
string Sprechstunde::get_sprechstunde(){
	ostringstream wandler(ios::out);
	wandler  << tag.get_wochentag_name() << ", " << zeit.get_uhrzeit();
	return wandler.str();
}
