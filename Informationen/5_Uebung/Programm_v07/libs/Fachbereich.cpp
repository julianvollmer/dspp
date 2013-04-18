/*
 * Fachbereich.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#include "Fachbereich.h"

Fachbereich::Fachbereich(){
	name = "Angewandte Informatik";
	bereichsnummer = 101;
}

void Fachbereich::zeige_fachbereich(){
	cout << name << " (" << bereichsnummer << ")" << endl;
}

void Fachbereich::erfasse_bereichsnummer(){
	bereichsnummer = erfasse_int(1,99,"Bitte geben Sie die Bereichsnummer ein : ");
}

void Fachbereich::erfasse_name(){
	cout << "Bitte geben Sie den Fachbereichsnamen ein : ";
	cin >> name;
}

void Fachbereich::erfasse_fachbereich(){
	erfasse_bereichsnummer();
	erfasse_name();
}

string Fachbereich::get_fachbereichsname(){
	return name;
}

int Fachbereich::get_fachbereichsnummer(){
	return bereichsnummer;
}

void Fachbereich::set_fachbereichsname(string der_name){
	this->name = der_name;
}

void Fachbereich::set_fachbereichsnummer(int die_bereichsnummer){
	this->bereichsnummer = die_bereichsnummer;
}

string Fachbereich::get_fachbereich(){
	ostringstream wandler(ios::out);
	  wandler  << name << " (" << bereichsnummer <<")";
	  return wandler.str();
}
