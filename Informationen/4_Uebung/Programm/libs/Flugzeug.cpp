/*
 * Flugzeuge.cpp
 *
 *  Created on: 28.05.2010
 *      Author: julian
 */

#include "Flugzeug.h"
/**
 * Standartkonstruktor eines Flugzeuges
 */
Flugzeug::Flugzeug(){
	this->max_passagiere = 0;
	this->name = "NoN";
}

/**
 * Standartkonstruktor eines Flugzeuges mit definierten Name und maximalen Passagieren
 */
Flugzeug::Flugzeug(string der_name, int die_max_passagiere){
	this->name = der_name;
	this->max_passagiere = die_max_passagiere;
}
/**
 * @return Gibt den Namen eines Flugzeuges zurueck
 */
string Flugzeug::get_name(){
	return this->name;
}

/**
 * @return Gibt die Maximalen Passagiere eines Flugzeuges zurueck.
 */
int Flugzeug::get_max_passagiere(){
	return this->max_passagiere;
}
/**
 * Berechnet die Auslastung eines Flugzeuges
 * @param passagiere_an_board Passagiere die zur Berechnug der Auslastung genommen werden sollen
 * @return Gibt die Auslastung eines Flugzeuges zurueck
 */
double Flugzeug::get_auslastung(double passagiere_an_board ){
	return (double)(passagiere_an_board / this->max_passagiere) * 100.0;
}


