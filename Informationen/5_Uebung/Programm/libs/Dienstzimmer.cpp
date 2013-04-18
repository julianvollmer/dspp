/*
 * Dienstzimmer.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Dienstzimmer.h"

/**
 * Initialisiert ein Dienstzimmer zufaellig.
 */
Dienstzimmer::Dienstzimmer(){
	gebaeude = "WC";
	for(int i = 0; i < 3; i++){
			raum+=liefere_ganze_zufallszahl(48,57);
		}
}

/**
 * Setzt ein Gebaudenamen.
 * @param das_gebaeude Gebaeude, welches gesetzt werden soll
 */
void Dienstzimmer::set_gebaeude(string das_gebaeude){
	this->gebaeude = das_gebaeude;
}

/**
 * Setzt den Raum.
 * @param der_raum Raum, der gesetzt werden soll.
 */
void Dienstzimmer::set_raum(string der_raum){
	this->raum = der_raum;
}

/**
 * @return Gibt den Namen des Gebaeudes zurueck.
 */
string Dienstzimmer::get_gebaeude(){
	return this->gebaeude;
}

/**
 * @return Gibt den Raum zurueck.
 */
string Dienstzimmer::get_raum(){
	return this->raum;
}

/**
 * Gibt das Dienstzimmer auf der Konsole aus.
 */
void Dienstzimmer::zeige_dienstzimmer(){
	cout << gebaeude << " " << raum << endl;
}
/**
 * Erfasst ein Gebaeude.
 */
void Dienstzimmer::erfasse_gebaeude(){
	cout << "Bitte geben Sie das Gebäude ein : ";
	cin >> gebaeude;
}

/**
 * Erfasst einen Raum.
 */
void Dienstzimmer::erfasse_raum(){
	cout << "Bitte geben Sie den Raum ein : ";
	cin >> raum;
}
/**
 * Erfasst ein Dienstzimmer.
 */
void Dienstzimmer::erfasse_dienstzimmer(){
	erfasse_gebaeude();
	erfasse_raum();
}
