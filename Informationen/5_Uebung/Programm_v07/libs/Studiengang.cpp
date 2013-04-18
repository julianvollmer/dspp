/*
 * Studiengang.cpp
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#include "Studiengang.h"

Studiengang::Studiengang(){

}

Studiengang::~Studiengang(){

}

string Studiengang::get_studiengang(){
	ostringstream wandler(ios::out);
	  wandler  << name << " (" << studiengangnr << ")";
	  return wandler.str();
}

void Studiengang::zeige_studiengang(){
	cout << name << " (" << studiengangnr << ")" << endl;
}
void Studiengang::erfasse_name(){
	cout << "Bitte geben Sie den Studiengangsnamen ein : ";
	cin >> studiengangnr;
}
void Studiengang::erfasse_studiengangnr(){
	cout << "Bitte geben sie die Studiengangsnr ein : ";
	cin >> name;
}

void Studiengang::erfasse_studiengang(){
	erfasse_name();
	erfasse_studiengangnr();
}
