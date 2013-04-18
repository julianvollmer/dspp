/*
 * Telefon.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Telefon.h"
/**
 * Initialisiert ein Telefon
 */
Telefon::Telefon(){
	vorwahl = '0' + liefere_zufallszahl_als_string(5);
	anschluss = liefere_zufallszahl_als_string(6);
}
/**
 * @return gibt einen Telefonnummer zureck.
 */
string Telefon::get_telefon(){
	return  this->vorwahl + " / " + this->anschluss;
}
/**
 * Erfasst eine Vorwahl
 */
void Telefon::erfasse_vorwahl(){
	cout << "Bitte geben Sie die Vorwahl ein : ";
	getline(cin, vorwahl);
}
/**
 * Erfasst einen Anschluss
 */
void Telefon::erfasse_anschluss(){
	cout << "Bitte geben Sie den Anschluss ein : ";
	getline(cin, anschluss);
}
/**
 * Erfasst eine Telefonnummer.
 */
void Telefon::erfasse_telefon(){
	erfasse_vorwahl();
	erfasse_anschluss();
}
