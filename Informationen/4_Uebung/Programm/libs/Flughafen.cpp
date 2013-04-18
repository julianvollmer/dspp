/*
 * Flughafen.cpp
 *
 *  Created on: 28.05.2010
 *      Author: julian
 */
#include "Flughafen.h"
/**
 * Standartkonstruktor der Klasse Flughafen
 */
Flughafen::Flughafen(){
	this->max_flieger = liefere_ganze_zufallszahl(12,39);
	this->name = this->generiere_name();
	this->flieger = init_flieger_zufall(this->max_flieger);
	this->angekommen_durchsatz = 0;
	this->abgeflogen_durchsatz = 0;
}

/**
 * @return Gibt den Namen eines Flughafens zurueck
 */
string Flughafen::get_name(){
	return this->name;
}

/**
 * @return gibt die Anzahl der Maximalen Flieger zurueck
 */
int Flughafen::get_max_flieger(){
	return this->max_flieger;
}

/**
 * @param der_name Name welcher beim Flughafen gesetzt werden soll
 */
void Flughafen::set_name(string der_name){
	this->name = der_name;
}

/**
 * Generiert eine 3 Stelliges Flughafen kuerzel.
 * @return 3 stelliges Flughafenkuerzel
 */
string Flughafen::generiere_name(){
	string name;
	for(int i = 0; i < 3; i++){
		name+=liefere_ganze_zufallszahl(65,90);
	}
	return name;
}
/**
 * @return Gibt einen Vector vom Typ Flugzeug zurueck der alle Flugzeuge des Flughafens enhaelt
 */
vector<Flugzeug> Flughafen::get_flieger(){
	return this->flieger;
}
/**
 * @param der_angekommene_durchsatz erhoeht den Parameter angekommen_durchsatz um der_angekommene_durchsatz.
 */

void Flughafen::erhoehe_durchsatz_angekommen(int der_angekommene_durchsatz){
	this->angekommen_durchsatz += der_angekommene_durchsatz;
}

/**
 * @param der_abgeflogene_durchsatz erhoeht den Parameter abgeflogen_durchsatz um der_abgeflogene_durchsatz.
 */

void Flughafen::erhoehe_durchsatz_abgefloggen(int der_abgeflogene_durchsatz){
	this->abgeflogen_durchsatz += der_abgeflogene_durchsatz;
}

/**
 * @return Gibt den Wert des Durchsatzes der angekommen Passagiere zurueck
 */
int Flughafen::get_durchsatz_angekommen(){
	return this->angekommen_durchsatz;
}

/**
 * @return Gibt den Wert des Durchsatzes der abgeflogenen Passagiere zurueck
 */
int Flughafen::get_durchsatz_abgeflogen(){
	return this->abgeflogen_durchsatz;
}
/**
 * Loescht ein Flugzeug aus dem Array
 */
void Flughafen::loesche_flugezeug(int auswahl_flieger){
	flieger.erase(flieger.begin() + (auswahl_flieger));
}
/**
 * Fuegt ein Flugezug in das Array ein.
 */
void Flughafen::platziere_flugezeug(Flugzeug flugzeug){
	flieger.push_back(flugzeug);
}


/**
 * Setzt den Durchsatz der angekomenen Passagiere.
 * @param der_angekommene_durchsatz passagiere die angekommen sind.
 */
void Flughafen::set_durchsatz_angekommen(int der_angekommene_durchsatz){
 	this->angekommen_durchsatz = der_angekommene_durchsatz;
}

/**
 * @param der_abgeflogene_durchsatz Setzt den Parameter abgeflogen_durchsatz
 */
void Flughafen::set_durchsatz_abgeflogen(int der_abgeflogene_durchsatz){
	this->abgeflogen_durchsatz = der_abgeflogene_durchsatz;
}
/**
 * Initialisiert die Flugzeuge
 * @return Es wird ein Vector von Flugzeugen zurueck gegeben.
 */
vector<Flugzeug> Flughafen::init_flieger(){
	this->flieger.push_back(Flugzeug("Airbus 320", 174));
	this->flieger.push_back(Flugzeug("Airbus 330", 325));
	this->flieger.push_back(Flugzeug("Boeing 737", 144));
	this->flieger.push_back(Flugzeug("Boeing 757", 209));
	this->flieger.push_back(Flugzeug("Dornier 328", 33));
	this->flieger.push_back(Flugzeug("Fokker F10", 100));
	this->flieger.push_back(Flugzeug("Learjet 35", 8));
	this->flieger.push_back(Flugzeug("McDonnell Douglas MD-88", 152));
	this->flieger.push_back(Flugzeug("Saab 340", 33));
	return this->flieger;
}


/**
 * Initilisiert einen Vector mit Flugzeugen zufaellig.
 */
vector<Flugzeug> Flughafen::init_flieger_zufall(int anz){
	vector<Flugzeug> Flugzeug;
	for(int i = 0; i < (anz / 2); i++){
		Flugzeug.push_back( this->init_flieger()[liefere_ganze_zufallszahl(0,(this->init_flieger().size() - 1 ))] );
	}
	return Flugzeug;
}
