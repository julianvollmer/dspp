/*
 * Telefon.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Telefon.h"
/**
 * Initialisiert eine Telefonnummer mit sinnvollen Standardwerten.
 */
Telefon::Telefon(){
	vorwahl = "05594";
	anschluss = "447";
}
/**
 * @return Gibt die Telefonnummer als String im Format Vorwahl / Anschluss aus.
 */
string Telefon::get_telefon(){
	return  this->vorwahl + " / " + this->anschluss;
}
/**
 * Erfasst eine Vorwahl
 */
void Telefon::erfasse_vorwahl(){
	cout << "Bitte geben Sie die Vorwahl ein : ";
	cin >> vorwahl;
}
/**
 * Erfasst einen Anschluss
 */
void Telefon::erfasse_anschluss(){
	cout << "Bitte geben Sie den Anschluss ein : ";
	cin >> anschluss;
}
/**
 * Erfasst eine Komplette Telefonnummer.
 */
void Telefon::erfasse_telefon(){
	erfasse_vorwahl();
	erfasse_anschluss();
}
