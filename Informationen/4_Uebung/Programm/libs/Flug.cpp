/*
 * Flug.cpp
 *
 *  Created on: 28.05.2010
 *      Author: julian
 */

#include "Flug.h"
/**
 * Standardkonstruktor für einen Flug.
 */
Flug::Flug(){
	this->start = "NoN";
	this->ziel = "NoN";
	this->auslastung = 50;

}
/**
 * Standardkonstruktor mit einem bestimmten Flugzeug.
 * @param f Flugzeug das gesetzt werden soll.
 */
Flug::Flug(Flugzeug f){
	this->start = "NoN";
	this->ziel = "NoN";
	this->flieger = f;
}

/**
 * Gibt den Namen des Startflughafen zurueck.
 * @return Name des Startflughafens.
 */
string Flug::get_start(){
	return this->start;
}

/**
 * Gibt den Namen des Zielflughafen zurueck.
 * @return Name des Zielflughafens.
 */
string Flug::get_ziel(){
	return this->ziel;
}
/**
 * Gibt das Flugzeug zurueck.
 * @return ein Objekt des Typs Flugzeug.
 */
Flugzeug Flug::get_flieger(){
	return this->flieger;
}
/**
 * Gibt die Auslastung eines Fluges zurueck.
 * @return Die Auslastung als Gleitkommazahl.
 */
double Flug::get_auslastung(){
	return auslastung;
}

/**
 * Gibt die Anzahl der Passagiere zurueck
 * @return Anzahl der Passagiere eines eines FLuges
 */
int Flug::get_anz_passagiere(){
	return this->anz_passagiere;
}

/**
 * Setzt die Anzahl der Passagiere und bestimmt die Auslastung
 * @param die_passagiere setzt anz_passagiere
 */
void Flug::set_anz_passagiere(int die_passagiere){
	this->anz_passagiere = die_passagiere;
	double auslastung = ((double)anz_passagiere / (double)flieger.get_max_passagiere())*100;
	this->set_auslastung(auslastung);
}

/**
 * Setzt das Start eines Fluges
 * @param der_start setz den Start
 */
void Flug::set_start(string der_start){
	this->start = der_start;
}

/**
 * Setzt das Ziel eines Fluges
 * @param das_ziel setz das Ziel
 */
void Flug::set_ziel(string das_ziel){
	this->ziel = das_ziel;
}
/**
 * Setzt die Auslastung
 * @param die_auslastung setzt den Parameter auslastung
 */
void Flug::set_auslastung(double die_auslastung){
	this->auslastung = die_auslastung;
}
