/*
 * produkte.cpp
 *
 *  Created on: 17.05.2010
 *      Author: jule
 */

#include "Produkte.h"
/**
 * Initialisiert Produkte mit einem Preis und einem Namen.
 */
Produkte::Produkte(double der_preis, string der_name){
	preis = der_preis;
	name = der_name;
}

/**
 * Standartkonstruktur initialisiert Produkte mit 0 und dem Wort nichts.
 */
Produkte::Produkte(){
	preis = 0;
	name = "nichts";
}

/**
 * Gibt den Preis aus.
 */
void Produkte::zeige_preis()const {
	cout << preis;
}

/**
 * Zeigt den Namen eines Produktes.
 */
void Produkte::zeige_name()const{
	cout << name;
}


/**
 * @return gibt den Preis eines Produktes zurueck.
 */
double Produkte::get_preis() const {
	return preis;
}

/**
 * @return Gibt den Namen zurueck
 */
string Produkte::get_name() const {
	return name;
}


