/*
 * Email.cpp
 *
 *  Created on: 13.06.2010
 *      Author: jule
 */

#include "Email.h"

/**
 * initialisiert eine Emailadresse.
 */
Email::Email(){
	email = "me@htw-berlin.de";
}

/**
 * Zeigt eine Emailadresse.
 */
void Email::zeige_email(){
	cout << email << endl;
}
/**
 * Erfasst eine Emailadresse.
 */
void Email::erfasse_email(){
	cout << "Bitte geben Sie Ihre Email adresse ein : ";
	getline(cin, email);
}

/**
 * @return Emailadresse als String.
 */
string Email::get_email(){
	return this->email;
}
/**
 * Setzt die Emailadresse.
 */
void Email::set_email(string die_email){
	this->email = die_email+"@htw-berlin.de";
}
