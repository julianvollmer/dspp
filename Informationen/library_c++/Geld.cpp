/*
 * geld.cpp
 *
 *  Created on: 14.05.2010
 *      Author: jule
 */

/**
 * Initialisiert Geld mit einem Betrag. Desweiteren wird die Waehrung auf Euro gesetzt
 */
#include "Geld.h"
Geld::Geld(double der_wert){
	wert = der_wert;
	einheit = "Euro";
}
/**
 * Standartkonstruktor Iinitialiesiert Geld mit den Betrag 0.00 Euro
 */
Geld::Geld(){
	wert = 0.0;
	einheit = "Euro";
}

/**
 * Gibt den Wert aus.
 */
void Geld::zeige_wert() const {
	cout << wert;
}

/**
 * Gibt die Einheit aus.
 */
void Geld::zeige_einheit()const {
	cout << einheit;
}

/**
 * Setzt einen Wert.
 */
void Geld::set_wert(double der_wert){
	wert = der_wert;
}

/**
 * @return Gibt den Wert zurueck.
 */
double Geld::get_wert(){
	return wert;
}
