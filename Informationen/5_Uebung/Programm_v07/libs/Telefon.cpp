/*
 * Telefon.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Telefon.h"

Telefon::Telefon(){
	vorwahl = "05507";
	anschluss = "7088";
}

string Telefon::get_telefon(){
	return  this->vorwahl + " / " + this->anschluss;
}

void Telefon::erfasse_vorwahl(){
	cout << "Bitte geben Sie die Vorwahl ein : ";
	cin >> vorwahl;
}

void Telefon::erfasse_anschluss(){
	cout << "Bitte geben Sie den Anschluss ein : ";
	cin >> anschluss;
}

void Telefon::erfasse_telefon(){
	erfasse_vorwahl();
	erfasse_anschluss();
}
