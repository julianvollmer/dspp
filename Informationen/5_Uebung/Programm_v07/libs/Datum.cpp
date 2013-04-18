/*
 * Datum.cpp
 *
 *  Created on: 13.06.2010
 *      Author: jule
 */

#include "Datum.h"
Datum::Datum(){
	tag = 1;
	monat = 1;
	jahr = 1603;
}

void Datum::setze_zufallsdatum(){
	tag = liefere_ganze_zufallszahl(1,27);
	monat = liefere_ganze_zufallszahl(1,12);
	jahr = liefere_ganze_zufallszahl(1939,2000);
}

void Datum::erfasse_jahr(){
	cout << "Bitte geben Sie das Jahr ein : ";
	cin >> jahr;
}

void Datum::erfasse_monat(){
	cout << "Bitte geben Sie den Monat ein ";
	cin >> monat;
}

void Datum::erfasse_tag(){
	cout << "Bitte geben Sie den Tag ein : ";
	cin >> tag;
}

void Datum::erfasse_datum(){
	erfasse_jahr();
	erfasse_monat();
	erfasse_tag();
}

string Datum::get_datum_DE(){
	ostringstream wandler(ios::out);
	if(tag < 10)
		wandler<<"0";
	  wandler  << tag << ".";
	  if(monat < 10)
		  wandler<<"0";
	  wandler << monat << ".";
	  wandler << jahr;
	  return wandler.str();
}
string Datum::get_datum(){
	ostringstream wandler(ios::out);
	wandler << jahr;
	if(monat < 10)
		wandler<<"0";
	wandler << monat;
	if(tag < 10)
		wandler<<"0";
	wandler  << tag;
	  return wandler.str();
}

int Datum::get_tag(){
	return this->tag;
}
int Datum::get_monat(){
	return this->monat;
}
int Datum::get_jahr(){
	return this->jahr;
}

