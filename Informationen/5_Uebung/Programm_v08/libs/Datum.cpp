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
	jahr = 1903;
}
/**
 * Setzt ein zufaelliges Datum.
 */
void Datum::setze_zufallsdatum(){
	tag = liefere_ganze_zufallszahl(1,27);
	monat = liefere_ganze_zufallszahl(1,12);
	jahr = liefere_ganze_zufallszahl(1939,2010);
}
/**
 * Erfasst ein Jahr;
 */
void Datum::erfasse_jahr(){
	jahr = erfasse_int("Bitte geben Sie das Jahr ein : ");
}
/**
 * Erfasst einen Monat.
 */
void Datum::erfasse_monat(){
	monat = erfasse_int(1,12, "Bitte geben Sie den Monat ein ");

}
/**
 * Erfasst einen Tag.
 */
void Datum::erfasse_tag(){
	tag = erfasse_int(1,31, "Bitte geben Sie den Tag ein : ");
}
/**
 * Erfasst ein Datum.
 */
void Datum::erfasse_datum(){
	erfasse_jahr();
	erfasse_monat();
	erfasse_tag();
}
/**
 * Liefert das Datum im Format TT.MM.JJJJ
 * @return gibt das Datum als String zurueck
 */
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
/**
 * @return Gibt ein String im Format JJJJMMTT zurueck;
 */
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
/**
 * @return gibt den tag zurueck
 */
int Datum::get_tag(){
	return this->tag;
}
/**
 * @return Gibt den Monat zurueck.
 */
int Datum::get_monat(){
	return this->monat;
}
/**
 * @return Gibt das Jahr zurueck.
 */
int Datum::get_jahr(){
	return this->jahr;
}

/**
 * Setzt den Tag.
 * @param der_tag Tag der gesetzt werden soll.
 */
void Datum::set_tag(int der_tag){
	tag = der_tag;
}
/**
 * Setzt den Monat.
 * @param Monat der gesetzt werden soll.
 */
void Datum::set_monat(int der_monat){
	monat = der_monat;
}
/**
 * Setzt das Jahr.
 * @param Jahr das gesetzt werden soll.
 */
void Datum::set_jahr(int das_jahr){
	jahr = das_jahr;
}

