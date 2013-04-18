/*
 * Email.cpp
 *
 *  Created on: 13.06.2010
 *      Author: jule
 */

#include "Email.h"

Email::Email(){
	email = "me@htw-berlin.de";
}


void Email::zeige_email(){
	cout << email << endl;
}

void Email::erfasse_email(){
	cout << "Bitte geben Sie Ihre Email adresse ein : ";
	cin >> email;
}

string Email::get_email(){
	return this->email;
}

void Email::set_email(string die_email){
	this->email = die_email+"@htw-berlin.de";
}
