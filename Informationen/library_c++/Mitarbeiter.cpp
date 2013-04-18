/*
 * mitarbeiter.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef MITARBEITER_CPP_
#define MITARBEITER_CPP_
#include "Mitarbeiter.h"


const string def_funktion[] = {"Schreibkraft", "Hausmeister", "Lehrkraft", "Hilfskraft", "Praktikant", "Schueller"};
const int anz_funktionen = sizeof(def_funktion) / sizeof(def_funktion[0]);
/**
 * Initialisiert eine Mitarbeiterin zufaellig.
 */
Mitarbeiter::Mitarbeiter(){
	funktion = def_funktion[liefere_ganze_zufallszahl(0,(anz_funktionen-1))];
	string myemail = get_name().get_vorname()+get_name().get_nachname();
	transform(myemail.begin(),myemail.end(),myemail.begin(),::tolower);
	email.set_email(myemail);
}

Mitarbeiter::~Mitarbeiter(){

}
/**
 * Schreibt eine Person auf den Bildschirm
 */
void Mitarbeiter::zeige_person(){
	Person::zeige_person();
	cout << setw(FELDBREITE) <<left << "Dienstraum"<<" : " << right << raum.get_gebaeude() << " " << raum.get_raum() << endl;
	cout << setw(FELDBREITE) <<left << "Telefon"<<" : " << right << telefon.get_telefon()<< endl;
	cout << setw(FELDBREITE) <<left << "Fax"<<" : " << right << fax.get_telefon()<< endl;
	cout << setw(FELDBREITE) <<left << "Email"<<" : " << right << email.get_email()<< endl;
	cout << setw(FELDBREITE) <<left << "Funktion"<<" : " << right << funktion<< endl;
}
/**
 * Erfasst eine Funktion.
 */
void Mitarbeiter::erfasse_funktion(){
	cout << "Bitte geben Sie Ihre Funktion ein : ";
	getline(cin,funktion);
}
/**
 * Erfasst einen Kompletten Mitarbeiter.
 */
void Mitarbeiter::erfasse_person(){
	Person::erfasse_person();
	raum.erfasse_dienstzimmer();
	telefon.erfasse_telefon();
	email.erfasse_email();
	erfasse_funktion();
}

#endif /* MITARBEITER_CPP_ */
