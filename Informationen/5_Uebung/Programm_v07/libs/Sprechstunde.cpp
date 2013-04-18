/*
 * Sprechstunde.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Sprechstunde.h"

Sprechstunde::Sprechstunde(){

}

Sprechstunde::~Sprechstunde(){

}

void Sprechstunde::zeige_sprechstunde(){
	tag.zeige_wochentag();
	cout << ", ";
	zeit.zeige_uhrzeit();
}

void Sprechstunde::erfasse_sprechstunde(){
	tag.erfasse_wochentag();
}

string Sprechstunde::get_sprechstunde(){
	ostringstream wandler(ios::out);
	wandler  << tag.get_wochentag_name() << ", " << zeit.get_uhrzeit();
	return wandler.str();
}
