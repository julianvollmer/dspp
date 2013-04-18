/*
 * Dienstzimmer.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */
#include "Dienstzimmer.h"

		string gebaeude;
		string raum;

void Dienstzimmer::set_gebaeude(string das_gebaeude){
	this->gebaeude = das_gebaeude;
}
void Dienstzimmer::set_raum(string der_raum){
	this->raum = der_raum;
}

string Dienstzimmer::get_gebaeude(){
	return this->gebaeude;
}
string Dienstzimmer::get_raum(){
	return this->raum;
}

Dienstzimmer::Dienstzimmer(){
	gebaeude = "WC";
	for(int i = 0; i < 3; i++){
			raum+=liefere_ganze_zufallszahl(48,57);
		}
}

void Dienstzimmer::zeige_dienstzimmer(){
	cout << gebaeude << " " << raum << endl;
}

void Dienstzimmer::erfasse_gebaeude(){
	cout << "Bitte geben Sie das Gebäude ein : ";
	cin >> gebaeude;
}

void Dienstzimmer::erfasse_raum(){
	cout << "Bitte geben Sie den Raum ein : ";
	cin >> raum;
}

void Dienstzimmer::erfasse_dienstzimmer(){
	erfasse_gebaeude();
	erfasse_raum();
}
