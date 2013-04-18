/*
 * Fachbereich.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#include "Fachbereich.h"
const string def_fachbereich[] ={"Physiologie", "Deutsch", "Mathe", "Informatik", "Handwerk", "Technik"};
const int anz_fachbereich = sizeof(def_fachbereich) / sizeof(def_fachbereich[0]);

/**
 * Initialisiert einen Fachbereich mit zufallswerten.
 */
Fachbereich::Fachbereich(){
	int auswahl = liefere_ganze_zufallszahl(0, (anz_fachbereich-1));
	name = def_fachbereich[auswahl];
	bereichsnummer = auswahl;
}
/**
 * Schreibt einen Fachbereich auf den Bildschirm.
 */
void Fachbereich::zeige_fachbereich(){
	cout << name << " (" << bereichsnummer << ")" << endl;
}
/**
 * Erfasst die Nummer eines Fachbereiches.
 */
void Fachbereich::erfasse_bereichsnummer(){
	bereichsnummer = erfasse_int(1,99,"Bitte geben Sie die Bereichsnummer ein : ");
}
/**
 * Erfasst den Namen eines Fachbereiches
 */
void Fachbereich::erfasse_name(){
	cout << "Bitte geben Sie den Namen des Fachbereiches an : ";
	getline(cin, this->name);
}

/**
 * Erfasst einen Fachbereich.
 */
void Fachbereich::erfasse_fachbereich(){
	cout << "Bitte geben Sie den Fachbereichsnamen ein : ";
	for (int i = 0; i < anz_fachbereich; i++){
		cout << "("<<i+1<<")" << def_fachbereich[i]<<endl;
	}
	int auswahl = (erfasse_int(1, anz_fachbereich));
	this->name = def_fachbereich[auswahl-1];
	this->bereichsnummer = auswahl;
}

/**
 * Gibt den Fachbereich als String zurueck.
 */
string Fachbereich::get_fachbereichsname(){
	return name;
}

/**
 * Gibt die Fachbereichsnummer als Ganzzahl zurueck.
 */
int Fachbereich::get_fachbereichsnummer(){
	return bereichsnummer;
}
/**
 * Setzt den Wert des Fachbereichsnamen.
 * @param der_name Name, der gesetzt werden soll
 */
void Fachbereich::set_fachbereichsname(string der_name){
	this->name = der_name;
}
/**
 * Setzt den Wert Fachbereichsnummer.
 * @param die_bereichsnummer Bereichsnummer, die gesetzt werden soll.
 */
void Fachbereich::set_fachbereichsnummer(int die_bereichsnummer){
	this->bereichsnummer = die_bereichsnummer;
}
/**
 * Gibt den Fachbereich komplett als String zurueck.
 */
string Fachbereich::get_fachbereich(){
	ostringstream wandler(ios::out);
	  wandler  << name << " (" << bereichsnummer <<")";
	  return wandler.str();
}
