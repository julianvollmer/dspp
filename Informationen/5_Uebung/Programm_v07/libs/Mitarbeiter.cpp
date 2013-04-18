/*
 * mitarbeiter.cpp
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef MITARBEITER_CPP_
#define MITARBEITER_CPP_
#include "Mitarbeiter.h"

Mitarbeiter::Mitarbeiter(){
	funktion = "Schreibkraft";
	string myemail = get_name().get_vorname()+get_name().get_nachname();
	transform(myemail.begin(),myemail.end(),myemail.begin(),::tolower);
	email.set_email(myemail);
}

Mitarbeiter::~Mitarbeiter(){

}

void Mitarbeiter::zeige_person(){
	Person::zeige_person();
	cout << setw(FELDBREITE) <<left << "Dienstraum"<<" : " << right << raum.get_gebaeude() << " " << raum.get_raum() << endl;
	cout << setw(FELDBREITE) <<left << "Telefon"<<" : " << right << telefon.get_telefon()<< endl;
	cout << setw(FELDBREITE) <<left << "Fax"<<" : " << right << fax.get_telefon()<< endl;
	cout << setw(FELDBREITE) <<left << "Email"<<" : " << right << email.get_email()<< endl;
	cout << setw(FELDBREITE) <<left << "Funktion"<<" : " << right << funktion<< endl;
}

void Mitarbeiter::erfasse_funktion(){
	cout << "Bitte geben Sie Ihre Funktion ein : ";
	cin >> funktion;
}

void Mitarbeiter::erfasse_person(){
	Person::erfasse_person();
	raum.erfasse_dienstzimmer();
	telefon.erfasse_telefon();
	email.erfasse_email();
	erfasse_funktion();
}

#endif /* MITARBEITER_CPP_ */
